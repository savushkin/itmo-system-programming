/* $OpenBSD: version.h,v 1.76 2016/02/23 09:14:34 djm Exp $ */
/* $FreeBSD: releng/10.3/crypto/openssh/version.h 296853 2016-03-14 13:05:13Z des $ */

#define SSH_VERSION	"OpenSSH_7.2"

#define SSH_PORTABLE	"p2"
#define SSH_RELEASE	SSH_VERSION SSH_PORTABLE

#define SSH_VERSION_FREEBSD	"FreeBSD-20160310"

#ifdef WITH_OPENSSL
#define OPENSSL_VERSION	SSLeay_version(SSLEAY_VERSION)
#else
#define OPENSSL_VERSION	"without OpenSSL"
#endif
