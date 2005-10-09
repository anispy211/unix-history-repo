/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 * created from FreeBSD: src/sys/alpha/linux/syscalls.master,v 1.63.2.1 2005/07/20 17:42:14 jhb Exp 
 */

#include <bsm/audit_kevents.h>
#include "opt_compat.h"
#include <sys/param.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <compat/linux/linux_sysproto.h>
#include <alpha/linux/linux.h>
#include <alpha/linux/linux_proto.h>

#define AS(name) (sizeof(struct name) / sizeof(register_t))

/* The casts are bogus but will do for now. */
struct sysent linux_sysent[] = {
#define	nosys	linux_nosys
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 0 =  */
	{ SYF_MPSAFE | AS(sys_exit_args), (sy_call_t *)sys_exit, AUE_NULL },	/* 1 = exit */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_fork, AUE_NULL },	/* 2 = linux_fork */
	{ SYF_MPSAFE | AS(read_args), (sy_call_t *)read, AUE_NULL },	/* 3 = read */
	{ SYF_MPSAFE | AS(write_args), (sy_call_t *)write, AUE_NULL },	/* 4 = write */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 5 =  */
	{ SYF_MPSAFE | AS(close_args), (sy_call_t *)close, AUE_NULL },	/* 6 = close */
	{ SYF_MPSAFE | AS(osf1_wait4_args), (sy_call_t *)osf1_wait4, AUE_NULL },	/* 7 = osf1_wait4 */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 8 =  */
	{ SYF_MPSAFE | AS(linux_link_args), (sy_call_t *)linux_link, AUE_NULL },	/* 9 = linux_link */
	{ SYF_MPSAFE | AS(linux_unlink_args), (sy_call_t *)linux_unlink, AUE_NULL },	/* 10 = linux_unlink */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 11 =  */
	{ SYF_MPSAFE | AS(linux_chdir_args), (sy_call_t *)linux_chdir, AUE_NULL },	/* 12 = linux_chdir */
	{ SYF_MPSAFE | AS(fchdir_args), (sy_call_t *)fchdir, AUE_NULL },	/* 13 = fchdir */
	{ SYF_MPSAFE | AS(linux_mknod_args), (sy_call_t *)linux_mknod, AUE_NULL },	/* 14 = linux_mknod */
	{ SYF_MPSAFE | AS(linux_chmod_args), (sy_call_t *)linux_chmod, AUE_NULL },	/* 15 = linux_chmod */
	{ SYF_MPSAFE | AS(linux_chown_args), (sy_call_t *)linux_chown, AUE_NULL },	/* 16 = linux_chown */
	{ AS(linux_brk_args), (sy_call_t *)linux_brk, AUE_NULL },	/* 17 = linux_brk */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 18 =  */
	{ SYF_MPSAFE | AS(linux_lseek_args), (sy_call_t *)linux_lseek, AUE_NULL },	/* 19 = linux_lseek */
	{ SYF_MPSAFE | 0, (sy_call_t *)getpid, AUE_NULL },	/* 20 = getpid */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 21 = osf1_mount */
	{ AS(linux_umount_args), (sy_call_t *)linux_umount, AUE_NULL },	/* 22 = linux_umount */
	{ SYF_MPSAFE | AS(setuid_args), (sy_call_t *)setuid, AUE_NULL },	/* 23 = setuid */
	{ SYF_MPSAFE | 0, (sy_call_t *)getuid, AUE_NULL },	/* 24 = getuid */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 25 =  */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_ptrace, AUE_NULL },	/* 26 = linux_ptrace */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 27 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 28 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 29 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 30 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 31 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 32 =  */
	{ SYF_MPSAFE | AS(linux_access_args), (sy_call_t *)linux_access, AUE_NULL },	/* 33 = linux_access */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 34 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 35 =  */
	{ SYF_MPSAFE | 0, (sy_call_t *)sync, AUE_NULL },	/* 36 = sync */
	{ SYF_MPSAFE | AS(linux_kill_args), (sy_call_t *)linux_kill, AUE_NULL },	/* 37 = linux_kill */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 38 =  */
	{ SYF_MPSAFE | AS(setpgid_args), (sy_call_t *)setpgid, AUE_NULL },	/* 39 = setpgid */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 40 =  */
	{ SYF_MPSAFE | AS(dup_args), (sy_call_t *)dup, AUE_NULL },	/* 41 = dup */
	{ SYF_MPSAFE | 0, (sy_call_t *)pipe, AUE_NULL },	/* 42 = pipe */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 43 = osf_set_program_attributes */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 44 =  */
	{ SYF_MPSAFE | AS(linux_open_args), (sy_call_t *)linux_open, AUE_NULL },	/* 45 = linux_open */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 46 =  */
	{ SYF_MPSAFE | 0, (sy_call_t *)getgid, AUE_NULL },	/* 47 = getgid */
	{ SYF_MPSAFE | AS(osf1_sigprocmask_args), (sy_call_t *)osf1_sigprocmask, AUE_NULL },	/* 48 = osf1_sigprocmask */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 49 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 50 =  */
	{ SYF_MPSAFE | AS(acct_args), (sy_call_t *)acct, AUE_NULL },	/* 51 = acct */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_sigpending, AUE_NULL },	/* 52 = linux_sigpending */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 53 =  */
	{ AS(linux_ioctl_args), (sy_call_t *)linux_ioctl, AUE_NULL },	/* 54 = linux_ioctl */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 55 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 56 =  */
	{ SYF_MPSAFE | AS(linux_symlink_args), (sy_call_t *)linux_symlink, AUE_NULL },	/* 57 = linux_symlink */
	{ SYF_MPSAFE | AS(linux_readlink_args), (sy_call_t *)linux_readlink, AUE_NULL },	/* 58 = linux_readlink */
	{ SYF_MPSAFE | AS(linux_execve_args), (sy_call_t *)linux_execve, AUE_NULL },	/* 59 = linux_execve */
	{ SYF_MPSAFE | AS(umask_args), (sy_call_t *)umask, AUE_NULL },	/* 60 = umask */
	{ SYF_MPSAFE | AS(chroot_args), (sy_call_t *)chroot, AUE_NULL },	/* 61 = chroot */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 62 =  */
	{ SYF_MPSAFE | 0, (sy_call_t *)getpgrp, AUE_NULL },	/* 63 = getpgrp */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_getpagesize, AUE_NULL },	/* 64 = linux_getpagesize */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 65 =  */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_vfork, AUE_NULL },	/* 66 = linux_vfork */
	{ SYF_MPSAFE | AS(linux_newstat_args), (sy_call_t *)linux_newstat, AUE_NULL },	/* 67 = linux_newstat */
	{ SYF_MPSAFE | AS(linux_newlstat_args), (sy_call_t *)linux_newlstat, AUE_NULL },	/* 68 = linux_newlstat */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 69 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 70 =  */
	{ SYF_MPSAFE | AS(linux_mmap_args), (sy_call_t *)linux_mmap, AUE_NULL },	/* 71 = linux_mmap */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 72 =  */
	{ SYF_MPSAFE | AS(linux_munmap_args), (sy_call_t *)linux_munmap, AUE_NULL },	/* 73 = linux_munmap */
	{ SYF_MPSAFE | AS(linux_mprotect_args), (sy_call_t *)linux_mprotect, AUE_NULL },	/* 74 = linux_mprotect */
	{ SYF_MPSAFE | AS(madvise_args), (sy_call_t *)madvise, AUE_NULL },	/* 75 = madvise */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_vhangup, AUE_NULL },	/* 76 = linux_vhangup */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 77 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 78 =  */
	{ SYF_MPSAFE | AS(linux_setgroups_args), (sy_call_t *)linux_setgroups, AUE_NULL },	/* 79 = linux_setgroups */
	{ SYF_MPSAFE | AS(linux_getgroups_args), (sy_call_t *)linux_getgroups, AUE_NULL },	/* 80 = linux_getgroups */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 81 =  */
	{ SYF_MPSAFE | AS(setpgid_args), (sy_call_t *)setpgid, AUE_NULL },	/* 82 = setpgid */
	{ SYF_MPSAFE | AS(osf1_setitimer_args), (sy_call_t *)osf1_setitimer, AUE_NULL },	/* 83 = osf1_setitimer */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 84 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 85 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 86 = osf_getitimer */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_gethostname, AUE_NULL },	/* 87 = linux_gethostname */
	{ SYF_MPSAFE | AS(sethostname_args), (sy_call_t *)osethostname, AUE_NULL },	/* 88 = osethostname */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_getdtablesize, AUE_NULL },	/* 89 = linux_getdtablesize */
	{ SYF_MPSAFE | AS(dup2_args), (sy_call_t *)dup2, AUE_NULL },	/* 90 = dup2 */
	{ SYF_MPSAFE | AS(linux_newfstat_args), (sy_call_t *)linux_newfstat, AUE_NULL },	/* 91 = linux_newfstat */
	{ SYF_MPSAFE | AS(linux_fcntl_args), (sy_call_t *)linux_fcntl, AUE_NULL },	/* 92 = linux_fcntl */
	{ SYF_MPSAFE | AS(osf1_select_args), (sy_call_t *)osf1_select, AUE_NULL },	/* 93 = osf1_select */
	{ SYF_MPSAFE | AS(poll_args), (sy_call_t *)poll, AUE_NULL },	/* 94 = poll */
	{ SYF_MPSAFE | AS(fsync_args), (sy_call_t *)fsync, AUE_NULL },	/* 95 = fsync */
	{ SYF_MPSAFE | AS(setpriority_args), (sy_call_t *)setpriority, AUE_NULL },	/* 96 = setpriority */
	{ SYF_MPSAFE | AS(osf1_socket_args), (sy_call_t *)osf1_socket, AUE_NULL },	/* 97 = osf1_socket */
	{ SYF_MPSAFE | AS(linux_connect_args), (sy_call_t *)linux_connect, AUE_NULL },	/* 98 = linux_connect */
	{ SYF_MPSAFE | AS(accept_args), (sy_call_t *)oaccept, AUE_NULL },	/* 99 = accept */
	{ SYF_MPSAFE | AS(linux_getpriority_args), (sy_call_t *)linux_getpriority, AUE_NULL },	/* 100 = linux_getpriority */
	{ SYF_MPSAFE | AS(osend_args), (sy_call_t *)osend, AUE_NULL },	/* 101 = osend */
	{ SYF_MPSAFE | AS(orecv_args), (sy_call_t *)orecv, AUE_NULL },	/* 102 = orecv */
	{ SYF_MPSAFE | AS(osf1_sigreturn_args), (sy_call_t *)osf1_sigreturn, AUE_NULL },	/* 103 = osf1_sigreturn */
	{ SYF_MPSAFE | AS(bind_args), (sy_call_t *)bind, AUE_NULL },	/* 104 = bind */
	{ SYF_MPSAFE | AS(setsockopt_args), (sy_call_t *)setsockopt, AUE_NULL },	/* 105 = setsockopt */
	{ SYF_MPSAFE | AS(listen_args), (sy_call_t *)listen, AUE_NULL },	/* 106 = listen */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 107 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 108 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 109 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 110 =  */
	{ SYF_MPSAFE | AS(osf1_sigsuspend_args), (sy_call_t *)osf1_sigsuspend, AUE_NULL },	/* 111 = osf1_sigsuspend */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 112 = osf_sigstack */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_recvmsg, AUE_NULL },	/* 113 = linux_recvmsg */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_sendmsg, AUE_NULL },	/* 114 = linux_sendmsg */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 115 =  */
	{ SYF_MPSAFE | AS(osf1_gettimeofday_args), (sy_call_t *)osf1_gettimeofday, AUE_NULL },	/* 116 = osf1_gettimeofday */
	{ SYF_MPSAFE | AS(osf1_getrusage_args), (sy_call_t *)osf1_getrusage, AUE_NULL },	/* 117 = osf1_getrusage */
	{ SYF_MPSAFE | AS(getsockopt_args), (sy_call_t *)getsockopt, AUE_NULL },	/* 118 = getsockopt */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 119 =  */
	{ SYF_MPSAFE | AS(readv_args), (sy_call_t *)readv, AUE_NULL },	/* 120 = readv */
	{ SYF_MPSAFE | AS(writev_args), (sy_call_t *)writev, AUE_NULL },	/* 121 = writev */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 122 = osf_settimeofday */
	{ SYF_MPSAFE | AS(fchown_args), (sy_call_t *)fchown, AUE_NULL },	/* 123 = fchown */
	{ SYF_MPSAFE | AS(fchmod_args), (sy_call_t *)fchmod, AUE_NULL },	/* 124 = fchmod */
	{ SYF_MPSAFE | AS(recvfrom_args), (sy_call_t *)orecvfrom, AUE_NULL },	/* 125 = recvfrom */
	{ SYF_MPSAFE | AS(setreuid_args), (sy_call_t *)setreuid, AUE_NULL },	/* 126 = setreuid */
	{ SYF_MPSAFE | AS(setregid_args), (sy_call_t *)setregid, AUE_NULL },	/* 127 = setregid */
	{ SYF_MPSAFE | AS(linux_rename_args), (sy_call_t *)linux_rename, AUE_NULL },	/* 128 = linux_rename */
	{ SYF_MPSAFE | AS(linux_truncate_args), (sy_call_t *)linux_truncate, AUE_NULL },	/* 129 = linux_truncate */
	{ SYF_MPSAFE | AS(oftruncate_args), (sy_call_t *)oftruncate, AUE_NULL },	/* 130 = oftruncate */
	{ SYF_MPSAFE | AS(flock_args), (sy_call_t *)flock, AUE_NULL },	/* 131 = flock */
	{ SYF_MPSAFE | AS(setgid_args), (sy_call_t *)setgid, AUE_NULL },	/* 132 = setgid */
	{ SYF_MPSAFE | AS(osf1_sendto_args), (sy_call_t *)osf1_sendto, AUE_NULL },	/* 133 = osf1_sendto */
	{ SYF_MPSAFE | AS(shutdown_args), (sy_call_t *)shutdown, AUE_NULL },	/* 134 = shutdown */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_socketpair, AUE_NULL },	/* 135 = linux_socketpair */
	{ SYF_MPSAFE | AS(linux_mkdir_args), (sy_call_t *)linux_mkdir, AUE_NULL },	/* 136 = linux_mkdir */
	{ SYF_MPSAFE | AS(linux_rmdir_args), (sy_call_t *)linux_rmdir, AUE_NULL },	/* 137 = linux_rmdir */
	{ SYF_MPSAFE | AS(utimes_args), (sy_call_t *)utimes, AUE_NULL },	/* 138 = utimes */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 139 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 140 =  */
	{ SYF_MPSAFE | AS(ogetpeername_args), (sy_call_t *)ogetpeername, AUE_NULL },	/* 141 = ogetpeername */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 142 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 143 =  */
	{ SYF_MPSAFE | AS(linux_getrlimit_args), (sy_call_t *)linux_getrlimit, AUE_NULL },	/* 144 = linux_getrlimit */
	{ SYF_MPSAFE | AS(linux_setrlimit_args), (sy_call_t *)linux_setrlimit, AUE_NULL },	/* 145 = linux_setrlimit */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 146 =  */
	{ SYF_MPSAFE | 0, (sy_call_t *)setsid, AUE_NULL },	/* 147 = setsid */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_quotactl, AUE_NULL },	/* 148 = linux_quotactl */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 149 =  */
	{ SYF_MPSAFE | AS(getsockname_args), (sy_call_t *)ogetsockname, AUE_NULL },	/* 150 = getsockname */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 151 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 152 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 153 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 154 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 155 =  */
	{ SYF_MPSAFE | AS(osf1_sigaction_args), (sy_call_t *)osf1_sigaction, AUE_NULL },	/* 156 = osf1_sigaction */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 157 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 158 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 159 = osf_getdirentries */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 160 = osf_statfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 161 = osf_fstatfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 162 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 163 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 164 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 165 = osf_getdomainname */
	{ SYF_MPSAFE | AS(setdomainname_args), (sy_call_t *)setdomainname, AUE_NULL },	/* 166 = setdomainname */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 167 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 168 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 169 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 170 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 171 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 172 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 173 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 174 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 175 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 176 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 177 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 178 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 179 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 180 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 181 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 182 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 183 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 184 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 185 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 186 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 187 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 188 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 189 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 190 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 191 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 192 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 193 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 194 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 195 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 196 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 197 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 198 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 199 = osf_swapon */
	{ SYF_MPSAFE | AS(linux_msgctl_args), (sy_call_t *)linux_msgctl, AUE_NULL },	/* 200 = linux_msgctl */
	{ SYF_MPSAFE | AS(linux_msgget_args), (sy_call_t *)linux_msgget, AUE_NULL },	/* 201 = linux_msgget */
	{ SYF_MPSAFE | AS(linux_msgrcv_args), (sy_call_t *)linux_msgrcv, AUE_NULL },	/* 202 = linux_msgrcv */
	{ SYF_MPSAFE | AS(linux_msgsnd_args), (sy_call_t *)linux_msgsnd, AUE_NULL },	/* 203 = linux_msgsnd */
	{ AS(linux_semctl_args), (sy_call_t *)linux_semctl, AUE_NULL },	/* 204 = linux_semctl */
	{ SYF_MPSAFE | AS(linux_semget_args), (sy_call_t *)linux_semget, AUE_NULL },	/* 205 = linux_semget */
	{ SYF_MPSAFE | AS(linux_semop_args), (sy_call_t *)linux_semop, AUE_NULL },	/* 206 = linux_semop */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 207 = osf_utsname */
	{ SYF_MPSAFE | AS(linux_lchown_args), (sy_call_t *)linux_lchown, AUE_NULL },	/* 208 = linux_lchown */
	{ SYF_MPSAFE | AS(linux_shmat_args), (sy_call_t *)linux_shmat, AUE_NULL },	/* 209 = linux_shmat */
	{ SYF_MPSAFE | AS(linux_shmctl_args), (sy_call_t *)linux_shmctl, AUE_NULL },	/* 210 = linux_shmctl */
	{ SYF_MPSAFE | AS(linux_shmdt_args), (sy_call_t *)linux_shmdt, AUE_NULL },	/* 211 = linux_shmdt */
	{ SYF_MPSAFE | AS(linux_shmget_args), (sy_call_t *)linux_shmget, AUE_NULL },	/* 212 = linux_shmget */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 213 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 214 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 215 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 216 =  */
	{ SYF_MPSAFE | AS(linux_msync_args), (sy_call_t *)linux_msync, AUE_NULL },	/* 217 = linux_msync */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 218 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 219 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 220 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 221 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 222 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 223 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 224 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 225 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 226 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 227 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 228 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 229 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 230 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 231 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 232 =  */
	{ SYF_MPSAFE | AS(getpgid_args), (sy_call_t *)getpgid, AUE_NULL },	/* 233 = getpgid */
	{ SYF_MPSAFE | AS(linux_getsid_args), (sy_call_t *)linux_getsid, AUE_NULL },	/* 234 = linux_getsid */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_sigaltstack, AUE_NULL },	/* 235 = linux_sigaltstack */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 236 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 237 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 238 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 239 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 240 =  */
	{ SYF_MPSAFE | AS(osf1_sysinfo_args), (sy_call_t *)osf1_sysinfo, AUE_NULL },	/* 241 = osf1_sysinfo */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 242 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 243 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 244 = osf_proplist_syscall */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 245 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 246 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 247 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 248 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 249 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 250 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 251 = osf_usleep_thread */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 252 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 253 =  */
	{ SYF_MPSAFE | AS(linux_sysfs_args), (sy_call_t *)linux_sysfs, AUE_NULL },	/* 254 = linux_sysfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 255 =  */
	{ SYF_MPSAFE | AS(osf1_getsysinfo_args), (sy_call_t *)osf1_getsysinfo, AUE_NULL },	/* 256 = osf1_getsysinfo */
	{ SYF_MPSAFE | AS(osf1_setsysinfo_args), (sy_call_t *)osf1_setsysinfo, AUE_NULL },	/* 257 = osf1_setsysinfo */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 258 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 259 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 260 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 261 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 262 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 263 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 264 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 265 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 266 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 267 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 268 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 269 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 270 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 271 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 272 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 273 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 274 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 275 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 276 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 277 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 278 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 279 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 280 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 281 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 282 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 283 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 284 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 285 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 286 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 287 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 288 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 289 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 290 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 291 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 292 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 293 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 294 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 295 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 296 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 297 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 298 =  */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 299 =  */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_bdflush, AUE_NULL },	/* 300 = linux_bdflush */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_sethae, AUE_NULL },	/* 301 = linux_sethae */
	{ AS(linux_mount_args), (sy_call_t *)linux_mount, AUE_NULL },	/* 302 = linux_mount */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_old_adjtimex, AUE_NULL },	/* 303 = linux_old_adjtimex */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_swapoff, AUE_NULL },	/* 304 = linux_swapoff */
	{ AS(linux_getdents_args), (sy_call_t *)linux_getdents, AUE_NULL },	/* 305 = linux_getdents */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_create_module, AUE_NULL },	/* 306 = linux_create_module */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_init_module, AUE_NULL },	/* 307 = linux_init_module */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_delete_module, AUE_NULL },	/* 308 = linux_delete_module */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_get_kernel_syms, AUE_NULL },	/* 309 = linux_get_kernel_syms */
	{ SYF_MPSAFE | AS(linux_syslog_args), (sy_call_t *)linux_syslog, AUE_NULL },	/* 310 = linux_syslog */
	{ SYF_MPSAFE | AS(linux_reboot_args), (sy_call_t *)linux_reboot, AUE_NULL },	/* 311 = linux_reboot */
	{ SYF_MPSAFE | AS(linux_clone_args), (sy_call_t *)linux_clone, AUE_NULL },	/* 312 = linux_clone */
	{ AS(linux_uselib_args), (sy_call_t *)linux_uselib, AUE_NULL },	/* 313 = linux_uselib */
	{ SYF_MPSAFE | AS(mlock_args), (sy_call_t *)mlock, AUE_NULL },	/* 314 = mlock */
	{ SYF_MPSAFE | AS(munlock_args), (sy_call_t *)munlock, AUE_NULL },	/* 315 = munlock */
	{ SYF_MPSAFE | AS(mlockall_args), (sy_call_t *)mlockall, AUE_NULL },	/* 316 = mlockall */
	{ SYF_MPSAFE | 0, (sy_call_t *)munlockall, AUE_NULL },	/* 317 = munlockall */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_sysinfo, AUE_NULL },	/* 318 = linux_sysinfo */
	{ SYF_MPSAFE | AS(linux_sysctl_args), (sy_call_t *)linux_sysctl, AUE_NULL },	/* 319 = linux_sysctl */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 320 = sys_idle */
	{ AS(linux_oldumount_args), (sy_call_t *)linux_oldumount, AUE_NULL },	/* 321 = linux_oldumount */
	{ SYF_MPSAFE | AS(swapon_args), (sy_call_t *)swapon, AUE_NULL },	/* 322 = swapon */
	{ SYF_MPSAFE | AS(linux_times_args), (sy_call_t *)linux_times, AUE_NULL },	/* 323 = linux_times */
	{ SYF_MPSAFE | AS(linux_personality_args), (sy_call_t *)linux_personality, AUE_NULL },	/* 324 = linux_personality */
	{ SYF_MPSAFE | AS(linux_setfsuid_args), (sy_call_t *)linux_setfsuid, AUE_NULL },	/* 325 = linux_setfsuid */
	{ SYF_MPSAFE | AS(linux_setfsgid_args), (sy_call_t *)linux_setfsgid, AUE_NULL },	/* 326 = linux_setfsgid */
	{ SYF_MPSAFE | AS(linux_ustat_args), (sy_call_t *)linux_ustat, AUE_NULL },	/* 327 = linux_ustat */
	{ SYF_MPSAFE | AS(linux_statfs_args), (sy_call_t *)linux_statfs, AUE_NULL },	/* 328 = linux_statfs */
	{ SYF_MPSAFE | AS(linux_fstatfs_args), (sy_call_t *)linux_fstatfs, AUE_NULL },	/* 329 = linux_fstatfs */
	{ SYF_MPSAFE | AS(sched_setparam_args), (sy_call_t *)sched_setparam, AUE_NULL },	/* 330 = sched_setparam */
	{ SYF_MPSAFE | AS(sched_getparam_args), (sy_call_t *)sched_getparam, AUE_NULL },	/* 331 = sched_getparam */
	{ SYF_MPSAFE | AS(linux_sched_setscheduler_args), (sy_call_t *)linux_sched_setscheduler, AUE_NULL },	/* 332 = linux_sched_setscheduler */
	{ SYF_MPSAFE | AS(linux_sched_getscheduler_args), (sy_call_t *)linux_sched_getscheduler, AUE_NULL },	/* 333 = linux_sched_getscheduler */
	{ SYF_MPSAFE | 0, (sy_call_t *)sched_yield, AUE_NULL },	/* 334 = sched_yield */
	{ SYF_MPSAFE | AS(linux_sched_get_priority_max_args), (sy_call_t *)linux_sched_get_priority_max, AUE_NULL },	/* 335 = linux_sched_get_priority_max */
	{ SYF_MPSAFE | AS(linux_sched_get_priority_min_args), (sy_call_t *)linux_sched_get_priority_min, AUE_NULL },	/* 336 = linux_sched_get_priority_min */
	{ SYF_MPSAFE | AS(sched_rr_get_interval_args), (sy_call_t *)sched_rr_get_interval, AUE_NULL },	/* 337 = sched_rr_get_interval */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 338 = sys_afs_syscall */
	{ SYF_MPSAFE | AS(linux_newuname_args), (sy_call_t *)linux_newuname, AUE_NULL },	/* 339 = linux_newuname */
	{ SYF_MPSAFE | AS(nanosleep_args), (sy_call_t *)nanosleep, AUE_NULL },	/* 340 = nanosleep */
	{ SYF_MPSAFE | AS(linux_mremap_args), (sy_call_t *)linux_mremap, AUE_NULL },	/* 341 = linux_mremap */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_nfsservctl, AUE_NULL },	/* 342 = linux_nfsservctl */
	{ SYF_MPSAFE | AS(setresuid_args), (sy_call_t *)setresuid, AUE_NULL },	/* 343 = setresuid */
	{ SYF_MPSAFE | AS(getresuid_args), (sy_call_t *)getresuid, AUE_NULL },	/* 344 = getresuid */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_pciconfig_read, AUE_NULL },	/* 345 = linux_pciconfig_read */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_pciconfig_write, AUE_NULL },	/* 346 = linux_pciconfig_write */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_query_module, AUE_NULL },	/* 347 = linux_query_module */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_prctl, AUE_NULL },	/* 348 = linux_prctl */
	{ SYF_MPSAFE | AS(linux_pread_args), (sy_call_t *)linux_pread, AUE_NULL },	/* 349 = linux_pread */
	{ SYF_MPSAFE | AS(linux_pwrite_args), (sy_call_t *)linux_pwrite, AUE_NULL },	/* 350 = linux_pwrite */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_rt_sigreturn, AUE_NULL },	/* 351 = linux_rt_sigreturn */
	{ SYF_MPSAFE | AS(linux_rt_sigaction_args), (sy_call_t *)linux_rt_sigaction, AUE_NULL },	/* 352 = linux_rt_sigaction */
	{ SYF_MPSAFE | AS(linux_rt_sigprocmask_args), (sy_call_t *)linux_rt_sigprocmask, AUE_NULL },	/* 353 = linux_rt_sigprocmask */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_rt_sigpending, AUE_NULL },	/* 354 = linux_rt_sigpending */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_rt_sigtimedwait, AUE_NULL },	/* 355 = linux_rt_sigtimedwait */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_rt_sigqueueinfo, AUE_NULL },	/* 356 = linux_rt_sigqueueinfo */
	{ SYF_MPSAFE | AS(linux_rt_sigsuspend_args), (sy_call_t *)linux_rt_sigsuspend, AUE_NULL },	/* 357 = linux_rt_sigsuspend */
	{ SYF_MPSAFE | AS(linux_select_args), (sy_call_t *)linux_select, AUE_NULL },	/* 358 = linux_select */
	{ SYF_MPSAFE | AS(gettimeofday_args), (sy_call_t *)gettimeofday, AUE_NULL },	/* 359 = gettimeofday */
	{ SYF_MPSAFE | AS(settimeofday_args), (sy_call_t *)settimeofday, AUE_NULL },	/* 360 = settimeofday */
	{ SYF_MPSAFE | AS(linux_getitimer_args), (sy_call_t *)linux_getitimer, AUE_NULL },	/* 361 = linux_getitimer */
	{ SYF_MPSAFE | AS(linux_setitimer_args), (sy_call_t *)linux_setitimer, AUE_NULL },	/* 362 = linux_setitimer */
	{ SYF_MPSAFE | AS(linux_utimes_args), (sy_call_t *)linux_utimes, AUE_NULL },	/* 363 = linux_utimes */
	{ SYF_MPSAFE | AS(getrusage_args), (sy_call_t *)getrusage, AUE_NULL },	/* 364 = getrusage */
	{ SYF_MPSAFE | AS(linux_wait4_args), (sy_call_t *)linux_wait4, AUE_NULL },	/* 365 = linux_wait4 */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_adjtimex, AUE_NULL },	/* 366 = linux_adjtimex */
	{ SYF_MPSAFE | AS(linux_getcwd_args), (sy_call_t *)linux_getcwd, AUE_NULL },	/* 367 = linux_getcwd */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_capget, AUE_NULL },	/* 368 = linux_capget */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_capset, AUE_NULL },	/* 369 = linux_capset */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_sendfile, AUE_NULL },	/* 370 = linux_sendfile */
	{ SYF_MPSAFE | AS(setresgid_args), (sy_call_t *)setresgid, AUE_NULL },	/* 371 = setresgid */
	{ SYF_MPSAFE | AS(getresgid_args), (sy_call_t *)getresgid, AUE_NULL },	/* 372 = getresgid */
	{ 0, (sy_call_t *)nosys, AUE_NULL },			/* 373 = sys_dipc */
	{ SYF_MPSAFE | AS(linux_pivot_root_args), (sy_call_t *)linux_pivot_root, AUE_NULL },	/* 374 = linux_pivot_root */
	{ SYF_MPSAFE | AS(linux_mincore_args), (sy_call_t *)linux_mincore, AUE_NULL },	/* 375 = linux_mincore */
	{ SYF_MPSAFE | 0, (sy_call_t *)linux_pciconfig_iobase, AUE_NULL },	/* 376 = linux_pciconfig_iobase */
	{ AS(linux_getdents64_args), (sy_call_t *)linux_getdents64, AUE_NULL },	/* 377 = linux_getdents64 */
};
