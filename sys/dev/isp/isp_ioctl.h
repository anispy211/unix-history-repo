/* $FreeBSD$ */
/*-
 * Copyright (c) 1997-2006 by Matthew Jacob
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice immediately at the beginning of the file, without modification,
 *    this list of conditions, and the following disclaimer.
 * 2. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * ioctl definitions for Qlogic FC/SCSI HBA driver
 */
#define	ISP_IOC		(021)	/* 'Ctrl-Q' */

/*
 * This ioctl sets/retrieves the debugging level for this hba instance.
 * Note that this is not a simple integer level- see ispvar.h for definitions.
 *
 * The arguments is a pointer to an integer with the new debugging level.
 * The old value is written into this argument.
 */

#define	ISP_SDBLEV	_IOWR(ISP_IOC, 1, int)

/*
 * This ioctl resets the HBA. Use with caution.
 */
#define	ISP_RESETHBA	_IO(ISP_IOC, 2)

/*
 * This ioctl performs a fibre channel rescan.
 */
#define	ISP_RESCAN	_IO(ISP_IOC, 3)

/*
 * This ioctl performs a reset and then will set the adapter to the
 * role that was passed in (the old role will be returned). It almost
 * goes w/o saying: use with caution.
 */
#define ISP_SETROLE     _IOWR(ISP_IOC, 4, int)

#define ISP_ROLE_NONE           0x0
#define ISP_ROLE_TARGET         0x1
#define ISP_ROLE_INITIATOR      0x2
#define ISP_ROLE_BOTH           (ISP_ROLE_TARGET|ISP_ROLE_INITIATOR)

/*
 * Get the current adapter role
 */
#define ISP_GETROLE     _IOR(ISP_IOC, 5, int)

/*
 * Get/Clear Stats
 */
#define	ISP_STATS_VERSION	0
typedef struct {
	uint8_t		isp_stat_version;
	uint8_t		isp_type;		/* (ro) reflects chip type */
	uint8_t		isp_revision;		/* (ro) reflects chip version */
	uint8_t		unused1;
	uint32_t	unused2;
	/*
	 * Statistics Counters
	 */
#define	ISP_NSTATS	16
#define	ISP_INTCNT	0
#define	ISP_INTBOGUS	1
#define	ISP_INTMBOXC	2
#define	ISP_INGOASYNC	3
#define	ISP_RSLTCCMPLT	4
#define	ISP_FPHCCMCPLT	5
#define	ISP_RSCCHIWAT	6
#define	ISP_FPCCHIWAT	7
	uint64_t	isp_stats[ISP_NSTATS];
} isp_stats_t;

#define	ISP_GET_STATS	_IOR(ISP_IOC, 6, isp_stats_t)
#define	ISP_CLR_STATS	_IO(ISP_IOC, 7)

/*
 * Initiate a LIP
 */
#define	ISP_FC_LIP	_IO(ISP_IOC, 8)

/*
 * Return the Port Database structure for the named device, or ENODEV if none.
 * Caller fills in virtual loopid (0..255), aka 'target'. The driver returns
 * ENODEV (if nothing valid there) or the actual loopid (for local loop devices
 * only), 24 bit Port ID and Node and Port WWNs.
 */
struct isp_fc_device {
	uint32_t	loopid;		/* 0..255 */
	uint32_t		: 6,
			role 	: 2,
			portid	: 24;	/* 24 bit Port ID */
	uint64_t	node_wwn;
	uint64_t	port_wwn;
};
#define	ISP_FC_GETDINFO	_IOWR(ISP_IOC, 9, struct isp_fc_device)

/*
 * Get F/W crash dump
 */
#define	ISP_GET_FW_CRASH_DUMP	_IO(ISP_IOC, 10)
#define	ISP_FORCE_CRASH_DUMP	_IO(ISP_IOC, 11)

/*
 * Get information about this Host Adapter, including current connection
 * topology and capabilities.
 */
struct isp_hba_device {
	uint32_t
					: 8,
					: 4,
		fc_speed		: 4,	/* Gbps */
					: 2,
		fc_class2		: 1,
		fc_ip_supported		: 1,
		fc_scsi_supported	: 1,
		fc_topology		: 3,
		fc_loopid		: 8;
	uint8_t		fc_fw_major;
	uint8_t		fc_fw_minor;
	uint8_t		fc_fw_micro;
	uint8_t		reserved;
	uint64_t	nvram_node_wwn;
	uint64_t	nvram_port_wwn;
	uint64_t	active_node_wwn;
	uint64_t	active_port_wwn;
};

#define	ISP_TOPO_UNKNOWN	0	/* connection topology unknown */
#define	ISP_TOPO_FCAL		1	/* private or PL_DA */
#define	ISP_TOPO_LPORT		2	/* public loop */
#define	ISP_TOPO_NPORT		3	/* N-port */
#define	ISP_TOPO_FPORT		4	/* F-port */

#define	ISP_FC_GETHINFO	_IOR(ISP_IOC, 12, struct isp_hba_device)
/*
 * Set some internal parameters. This doesn't take effect until
 * the chip is reset.
 *
 * Each parameter is generalized to be a name string with an integer value.
 *
 * Known parameters are:
 *
 *	Name				Value Range
 *	
 *	"framelength"			512,1024,2048
 *	"exec_throttle"			16..255
 *	"fullduplex"			0,1
 *	"loopid"			0..125
 */

struct isp_fc_param {
	char		param_name[16];	/* null terminated */
	uint32_t	parameter;
};

#define	ISP_GET_FC_PARAM	_IOWR(ISP_IOC, 98, struct isp_fc_param)
#define	ISP_SET_FC_PARAM	_IOWR(ISP_IOC, 99, struct isp_fc_param)

/*
 * Various Reset Goodies
 */
struct isp_fc_tsk_mgmt {
	uint32_t	loopid;		/* 0..255 */
	uint32_t	lun;
	enum {
		IPT_CLEAR_ACA,
		IPT_TARGET_RESET,
		IPT_LUN_RESET,
		IPT_CLEAR_TASK_SET,
		IPT_ABORT_TASK_SET
	} action;
};
#define	ISP_TSK_MGMT		_IOWR(ISP_IOC, 97, struct isp_fc_tsk_mgmt)
