# $FreeBSD: releng/10.3/usr.sbin/wpa/hostapd_cli/Makefile 252726 2013-07-04 21:12:58Z rpaulo $

.include "${.CURDIR}/../Makefile.inc"

.PATH.c:${HOSTAPD_DISTDIR}

PROG=	hostapd_cli
SRCS=	common.c edit.c eloop.c hostapd_cli.c os_unix.c wpa_ctrl.c wpa_debug.c

CFLAGS+= -DCONFIG_CTRL_IFACE
CFLAGS+= -DCONFIG_CTRL_IFACE_UNIX

MAN=	hostapd_cli.8

.include <bsd.prog.mk>
