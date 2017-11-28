/*
 * by Manuel Bouyer (bouyer@ensta.fr)
 *
 * There is no copyright, you can use it as you want.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: releng/10.3/libexec/rpc.rquotad/rquotad.c 207736 2010-05-07 00:41:12Z mckusick $");

#include <sys/param.h>
#include <sys/mount.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/socket.h>

#include <ufs/ufs/quota.h>
#include <rpc/rpc.h>
#include <rpcsvc/rquota.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <ctype.h>
#include <errno.h>
#include <fstab.h>
#include <grp.h>
#include <libutil.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

static void rquota_service(struct svc_req *request, SVCXPRT *transp);
static void sendquota(struct svc_req *request, SVCXPRT *transp);
static void initfs(void);
static int getfsquota(long id, char *path, struct dqblk *dqblk);

static struct quotafile **qfa;	/* array of qfs */
static int nqf, szqf;		/* number of qfs and size of array */
static int from_inetd = 1;

static void
cleanup(int sig)
{

	(void)sig;
	(void)rpcb_unset(RQUOTAPROG, RQUOTAVERS, NULL);
	exit(0);
}

int
main(void)
{
	SVCXPRT *transp;
	int ok;
	struct sockaddr_storage from;
	socklen_t fromlen;

	fromlen = sizeof(from);
	if (getsockname(0, (struct sockaddr *)&from, &fromlen) < 0)
		from_inetd = 0;

	if (!from_inetd) {
		daemon(0, 0);
		(void)rpcb_unset(RQUOTAPROG, RQUOTAVERS, NULL);
		(void)signal(SIGINT, cleanup);
		(void)signal(SIGTERM, cleanup);
		(void)signal(SIGHUP, cleanup);
	}

	openlog("rpc.rquotad", LOG_CONS|LOG_PID, LOG_DAEMON);

	/* create and register the service */
	if (from_inetd) {
		transp = svc_tli_create(0, NULL, NULL, 0, 0);
		if (transp == NULL) {
			syslog(LOG_ERR, "couldn't create udp service.");
			exit(1);
		}
		ok = svc_reg(transp, RQUOTAPROG, RQUOTAVERS,
		    rquota_service, NULL);
	} else {
		ok = svc_create(rquota_service,
		    RQUOTAPROG, RQUOTAVERS, "udp");
	}
	if (!ok) {
		syslog(LOG_ERR,
		    "unable to register (RQUOTAPROG, RQUOTAVERS, %s)",
		    from_inetd ? "(inetd)" : "udp");
		exit(1);
	}

	initfs();
	svc_run();
	syslog(LOG_ERR, "svc_run returned");
	exit(1);
}

static void
rquota_service(struct svc_req *request, SVCXPRT *transp)
{

	switch (request->rq_proc) {
	case NULLPROC:
		(void)svc_sendreply(transp, (xdrproc_t)xdr_void, (char *)NULL);
		break;
	case RQUOTAPROC_GETQUOTA:
	case RQUOTAPROC_GETACTIVEQUOTA:
		sendquota(request, transp);
		break;
	default:
		svcerr_noproc(transp);
		break;
	}
	if (from_inetd)
		exit(0);
}

/* read quota for the specified id, and send it */
static void
sendquota(struct svc_req *request, SVCXPRT *transp)
{
	struct getquota_args getq_args;
	struct getquota_rslt getq_rslt;
	struct dqblk dqblk;
	struct timeval timev;
	int scale;

	bzero(&getq_args, sizeof(getq_args));
	if (!svc_getargs(transp, (xdrproc_t)xdr_getquota_args, &getq_args)) {
		svcerr_decode(transp);
		return;
	}
	if (request->rq_cred.oa_flavor != AUTH_UNIX) {
		/* bad auth */
		getq_rslt.status = Q_EPERM;
	} else if (!getfsquota(getq_args.gqa_uid, getq_args.gqa_pathp, &dqblk)) {
		/* failed, return noquota */
		getq_rslt.status = Q_NOQUOTA;
	} else {
		gettimeofday(&timev, NULL);
		getq_rslt.status = Q_OK;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_active = TRUE;
		scale = 1 << flsll(dqblk.dqb_bhardlimit >> 32);
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_bsize =
		    DEV_BSIZE * scale;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_bhardlimit =
		    dqblk.dqb_bhardlimit / scale;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_bsoftlimit =
		    dqblk.dqb_bsoftlimit / scale;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_curblocks =
		    dqblk.dqb_curblocks / scale;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_fhardlimit =
		    dqblk.dqb_ihardlimit;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_fsoftlimit =
		    dqblk.dqb_isoftlimit;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_curfiles =
		    dqblk.dqb_curinodes;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_btimeleft =
		    dqblk.dqb_btime - timev.tv_sec;
		getq_rslt.getquota_rslt_u.gqr_rquota.rq_ftimeleft =
		    dqblk.dqb_itime - timev.tv_sec;
	}
	if (!svc_sendreply(transp, (xdrproc_t)xdr_getquota_rslt, &getq_rslt))
		svcerr_systemerr(transp);
	if (!svc_freeargs(transp, (xdrproc_t)xdr_getquota_args, &getq_args)) {
		syslog(LOG_ERR, "unable to free arguments");
		exit(1);
	}
}

static void
initfs(void)
{
	struct fstab *fs;

	setfsent();
	szqf = 8;
	if ((qfa = malloc(szqf * sizeof *qfa)) == NULL)
		goto enomem;
	while ((fs = getfsent())) {
		if (strcmp(fs->fs_vfstype, "ufs"))
			continue;
		if (nqf >= szqf) {
			szqf *= 2;
			if ((qfa = reallocf(qfa, szqf * sizeof *qfa)) == NULL)
				goto enomem;
		}
		if ((qfa[nqf] = quota_open(fs, USRQUOTA, O_RDONLY)) == NULL) {
			if (errno != EOPNOTSUPP)
				goto fserr;
			continue;
		}
		++nqf;
		/* XXX */
	}
	endfsent();
	return;
enomem:
	syslog(LOG_ERR, "out of memory");
	exit(1);
fserr:
	syslog(LOG_ERR, "%s: %s", fs->fs_file, strerror(errno));
	exit(1);
}

/*
 * gets the quotas for id, filesystem path.
 * Return 0 if fail, 1 otherwise
 */
static int
getfsquota(long id, char *path, struct dqblk *dqblk)
{
	int i;

	for (i = 0; i < nqf; ++i)
		if (quota_check_path(qfa[i], path) == 1)
			return (quota_read(qfa[i], dqblk, id) == 0);
	return (0);
}
