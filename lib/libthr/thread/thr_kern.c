/*
 * Copyright (c) 2003 Jeffrey Roberson <jeff@freebsd.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/signalvar.h>
#include <sys/time.h>
#include <sys/timespec.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include "thr_private.h"

/* XXX Why can't I get this from time.h? :-( */
#define timespecsub(vvp, uvp)                                           \
        do {                                                            \
                (vvp)->tv_sec -= (uvp)->tv_sec;                         \
                (vvp)->tv_nsec -= (uvp)->tv_nsec;                       \
                if ((vvp)->tv_nsec < 0) {                               \
                        (vvp)->tv_sec--;                                \
                        (vvp)->tv_nsec += 1000000000;                   \
                }                                                       \
        } while (0)

void
_thread_critical_enter(pthread_t pthread)
{
	_thread_sigblock();
	UMTX_LOCK(&pthread->lock);
}

void
_thread_critical_exit(pthread_t pthread)
{
	UMTX_UNLOCK(&pthread->lock);
	_thread_sigunblock();
}

void
_thread_sigblock()
{
	sigset_t set;
	sigset_t sav;

	/*
	 * Block all signals.
	 */
	SIGFILLSET(set);
	SIGDELSET(set, SIGTRAP);

	/* If we have already blocked signals, just up the refcount */
	if (++curthread->signest > 1)
		return;
	PTHREAD_ASSERT(curthread->signest == 1,
	    ("Blocked signal nesting level must be 1!"));

	if (__sys_sigprocmask(SIG_SETMASK, &set, &sav)) {
		_thread_printf(STDERR_FILENO, "Critical Enter: sig err %d\n",
		    errno);
		abort();
	}
	curthread->savedsig = sav;
}

void
_thread_sigunblock()
{
	sigset_t set;

	/* We might be in a nested 'blocked signal' section */
	if (--curthread->signest > 0)
		return;
	PTHREAD_ASSERT(curthread->signest == 0,
	    ("Non-Zero blocked signal nesting level."));

	/*
	 * Restore signals.
	 */
	set = curthread->savedsig;
	if (__sys_sigprocmask(SIG_SETMASK, &set, NULL)) {
		_thread_printf(STDERR_FILENO, "Critical Exit: sig err %d\n",
		    errno);
		abort();
	}
}

int
_thread_suspend(pthread_t pthread, const struct timespec *abstime)
{
	struct timespec remaining;
	struct timespec *ts;
	int error;

	/*
	 * Compute the remainder of the run time.
	 */
	if (abstime) {
		struct timespec now;
		struct timeval tv;

		GET_CURRENT_TOD(tv);
		TIMEVAL_TO_TIMESPEC(&tv, &now);

		remaining = *abstime;
		timespecsub(&remaining, &now);
		ts = &remaining;

		/*
		 * NOTE: timespecsub() makes sure the tv_nsec member >= 0.
		 */
		if (ts->tv_sec < 0)
			return (ETIMEDOUT);
	} else
		ts = NULL;
	error = thr_suspend(ts);
	return (error == -1 ? errno : error);
}
