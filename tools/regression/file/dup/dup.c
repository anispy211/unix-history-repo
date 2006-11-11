/*
 * $OpenBSD: dup2test.c,v 1.3 2003/07/31 21:48:08 deraadt Exp $
 * $OpenBSD: dup2_self.c,v 1.3 2003/07/31 21:48:08 deraadt Exp $
 * $OpenBSD: fcntl_dup.c,v 1.2 2003/07/31 21:48:08 deraadt Exp $
 *
 * Written by Artur Grabowski <art@openbsd.org> 2002 Public Domain.
 *
 * $FreeBSD$
 */

/*
 * Test #1:  check if dup(2) works.
 * Test #2:  check if dup2(2) works.
 * Test #3:  check if dup2(2) returned a fd we asked for.
 * Test #4:  check if dup2(2) cleared close-on-exec flag for duped fd.
 * Test #5:  check if dup2(2) allows to dup fd to itself.
 * Test #6:  check if dup2(2) returned a fd we asked for.
 * Test #7:  check if dup2(2) did not clear close-on-exec flag for duped fd.
 * Test #8:  check if fcntl(F_DUPFD) works.
 * Test #9:  check if fcntl(F_DUPFD) cleared close-on-exec flag for duped fd.
 * Test #10: check if dup2() to a fd > current maximum number of open files
 *           limit work.
 */

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	getafile(void);

static int
getafile(void)
{
	int fd;

	char temp[] = "/tmp/dup2XXXXXXXXX";
	if ((fd = mkstemp(temp)) < 0)
		err(1, "mkstemp");
	remove(temp);
	if (ftruncate(fd, 1024) != 0)
		err(1, "ftruncate");
	return (fd);
}

int
main(int __unused argc, char __unused *argv[])
{
	struct rlimit rlp;
	int orgfd, fd1, fd2, test = 0;

	orgfd = getafile();

	printf("1..10\n");

	/* If dup(2) ever work? */
	if ((fd1 = dup(orgfd)) < 0)
		err(1, "dup");
	printf("ok %d - dup(2) works\n", ++test);

	/* Set close-on-exec */
	if (fcntl(fd1, F_SETFD, 1) != 0)
		err(1, "fcntl(F_SETFD)");

	/* If dup2(2) ever work? */
	if ((fd2 = dup2(fd1, fd1 + 1)) < 0)
		err(1, "dup2");
	printf("ok %d - dup2(2) works\n", ++test);

	/* Do we get the right fd? */
	++test;
	if (fd2 != fd1 + 1)
		printf("no ok %d - dup2(2) didn't give us the right fd\n",
		    test);
	else
		printf("ok %d - dup2(2) returned a correct fd\n", test);

	/* Was close-on-exec cleared? */
	++test;
	if (fcntl(fd2, F_GETFD) != 0)
		printf("not ok %d - dup2(2) didn't clear close-on-exec\n",
		    test);
	else
		printf("ok %d - dup2(2) cleared close-on-exec\n", test);

	/*
	 * Dup to itself.
	 *
	 * We're testing a small tweak in dup2 semantics.
	 * Normally dup and dup2 will clear the close-on-exec
	 * flag on the new fd (which appears to be an implementation
	 * mistake from start and not some planned behavior).
	 * In todays implementations of dup and dup2 we have to make
	 * an effort to really clear that flag.  But all tested
	 * implementations of dup2 have another tweak.  If we
	 * dup2(old, new) when old == new, the syscall short-circuits
	 * and returns early (because there is no need to do all the
	 * work (and there is a risk for serious mistakes)).
	 * So although the docs say that dup2 should "take 'old',
	 * close 'new' perform a dup(2) of 'old' into 'new'"
	 * the docs are not really followed because close-on-exec
	 * is not cleared on 'new'.
	 *
	 * Since everyone has this bug, we pretend that this is
	 * the way it is supposed to be and test here that it really
	 * works that way.
	 *
	 * This is a fine example on where two separate implementation
	 * fuckups take out each other and make the end-result the way
	 * it was meant to be.
	 */
        if ((fd2 = dup2(fd1, fd1)) < 0)
		err(1, "dup2");
	printf("ok %d - dup2(2) to itself works\n", ++test);

	/* Do we get the right fd? */
	++test;
	if (fd2 != fd1)
		printf("not ok %d - dup2(2) didn't give us the right fd\n",
		    test);
	else
		printf("ok %d - dup2(2) to itself returned a correct fd\n",
		    test);

	/* Was close-on-exec cleared? */
	++test;
	if (fcntl(fd2, F_GETFD) == 0)
		printf("not ok %d - dup2(2) cleared close-on-exec\n", test);
	else
		printf("ok %d - dup2(2) didn't clear close-on-exec\n", test);

	/* Does fcntl(F_DUPFD) work? */
	if ((fd2 = fcntl(fd1, F_DUPFD)) < 0)
		err(1, "fcntl(F_DUPFD)");
	printf("ok %d - fcntl(F_DUPFD) works\n", ++test);

	/* Was close-on-exec cleared? */
	++test;
        if (fcntl(fd2, F_GETFD) != 0)
		printf(
		    "not ok %d - fcntl(F_DUPFD) didn't clear close-on-exec\n",
		    test);
	else
		printf("ok %d - fcntl(F_DUPFD) cleared close-on-exec\n", test);

	++test;
	if (getrlimit(RLIMIT_NOFILE, &rlp) < 0)
		err(1, "getrlimit");
        if ((fd2 = dup2(fd1, rlp.rlim_cur + 1)) == 0)
		printf("not ok %d - dup2(2) bypassed NOFILE limit\n", test);
	else
		printf("ok %d - dup2(2) didn't bypass NOFILE limit\n", test);

	return (0);
}
