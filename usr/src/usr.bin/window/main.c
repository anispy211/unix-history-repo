#ifndef lint
static	char *sccsid = "@(#)main.c	3.16 84/03/23";
#endif

#include "defs.h"
#include <sys/signal.h>
#include <stdio.h>

#define next(a) (*++*(a) ? *(a) : (*++(a) ? *(a) : (char *)usage()))

/*ARGSUSED*/
main(argc, argv)
char **argv;
{
	register char *p;
	char fflag = 0;
	char dflag = 0;
	char xflag = 0;

	if (p = rindex(*argv, '/'))
		p++;
	else
		p = *argv;
	debug = strcmp(p, "a.out") == 0;
	while (*++argv) {
		if (**argv == '-') {
			switch (*++*argv) {
			case 'f':
				fflag++;
				break;
			case 'e':
				setescape(next(argv));
				break;
			case 't':
				terse++;
				break;
			case 'd':
				dflag++;
				break;
			case 'D':
				debug = !debug;
				break;
			case 'x':
				xflag++;
				break;
			default:
				(void) usage();
			}
		} else
			(void) usage();
	}
	nbufline = 48;				/* compatible */
	escapec = CTRL(p);	
	if ((shell = getenv("SHELL")) == 0)
		shell = "/bin/csh";
	if (shellname = rindex(shell, '/'))
		shellname++;
	else
		shellname = shell;
#ifndef O_4_1A
	(void) gettimeofday(&starttime, (struct timezone *)0);
#endif
	if (wwinit() < 0) {
		(void) fprintf(stderr, "%s.\n", wwerror());
		exit(1);
	}
	if (debug)
		wwnewtty.ww_tchars.t_quitc = wwoldtty.ww_tchars.t_quitc;
	if (xflag) {
		wwnewtty.ww_tchars.t_stopc = wwoldtty.ww_tchars.t_stopc;
		wwnewtty.ww_tchars.t_startc = wwoldtty.ww_tchars.t_startc;
	}
	if (debug || xflag)
		(void) wwsettty(0, &wwnewtty);

	if ((cmdwin = wwopen(WWO_REVERSE, 1, wwncol, 0, 0, 0)) == 0) {
		(void) wwflush();
		(void) fprintf(stderr, "%s.\r\n", wwerror());
		goto bad;
	}
	cmdwin->ww_nointr = 1;
	if ((framewin = wwopen(WWO_GLASS|WWO_FRAME, wwnrow, wwncol, 0, 0, 0))
	    == 0) {
		(void) wwflush();
		(void) fprintf(stderr, "%s.\r\n", wwerror());
		goto bad;
	}
	wwadd(framewin, &wwhead);
	if ((boxwin = wwopen(WWO_GLASS, wwnrow, wwncol, 0, 0, 0)) == 0) {
		(void) wwflush();
		(void) fprintf(stderr, "%s.\r\n", wwerror());
		goto bad;
	}

	wwupdate();
	wwflush();
	(void) signal(SIGCHLD, wwchild);
	setvars();
	if (fflag)
		wwcurwin = 0;
	else {
		if (!terse)
			wwadd(cmdwin, &wwhead);
		if (dflag || doconfig() < 0)
			dodefault();
		if (selwin != 0) {
			wwcurwin = selwin;
			wwcursor(selwin, 0);
		}
		if (!terse) {
			wwdelete(cmdwin);
			reframe();
		}
	}

	mloop();

	wwupdate();
	wwflush();
bad:
	wwend();
	return 0;
}

usage()
{
	(void) fprintf(stderr, "window: [-e escape-char] [-t] [-f] [-d]\n");
	exit(1);
	return 0;			/* for lint */
}
