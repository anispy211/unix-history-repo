/*-
 * Copyright (c) 1984 The Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.proprietary.c%
 */

#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "@(#)nargs.s	5.4 (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */

#include "DEFS.h"

ENTRY(nargs, 0)
	movzbl	*8(fp),r0	/* 8(fp) is old ap */
	ret
