# $FreeBSD: releng/10.3/usr.sbin/bsdinstall/distfetch/Makefile 291819 2015-12-04 19:16:56Z bdrewery $

BINDIR= ${LIBEXECDIR}/bsdinstall
PROG=	distfetch
DPADD=	${LIBFETCH} ${LIBDIALOG} ${LIBM}
LDADD=	-lfetch -ldialog -lm

WARNS?=	6
MAN=

.include <bsd.own.mk>

.if ${MK_NCURSESW} == "no"
DPADD+=	${LIBNCURSES}
LDADD+=	-lncurses
.else
DPADD+=	${LIBNCURSESW}
LDADD+=	-lncursesw
.endif

.include <bsd.prog.mk>
