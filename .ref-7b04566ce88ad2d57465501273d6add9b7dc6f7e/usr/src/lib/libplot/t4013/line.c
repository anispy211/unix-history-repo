/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)line.c	5.1 (Berkeley) %G%";
#endif not lint

line(x0,y0,x1,y1){
	move(x0,y0);
	cont(x1,y1);
}
