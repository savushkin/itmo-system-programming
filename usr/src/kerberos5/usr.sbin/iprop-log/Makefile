# $FreeBSD: releng/10.3/kerberos5/usr.sbin/iprop-log/Makefile 289042 2015-10-08 17:49:14Z bdrewery $

PROG=	iprop-log
MAN=	iprop-log.8
SRCS=	iprop-log.c iprop-commands.c iprop-commands.h kadm5_err.h
CFLAGS+=	-I${KRB5DIR}/lib/kadm5 \
		-I${KRB5DIR}/lib/krb5 \
		-I${KRB5DIR}/lib/roken \
		-I${KRB5DIR}/lib/sl \
		-I.
DPADD=	${LIBKADM5SRV} ${LIBHDB} ${LIBKRB5} ${LIBASN1} ${LIBCRYPTO} \
	${LIBCRYPT} ${LIBSL} ${LIBROKEN} ${LIBVERS} ${LIBEDIT}
LDADD=	-lkadm5srv -lhdb -lkrb5 -lasn1 -lcrypto -lcrypt ${LIBSL} -lroken \
	${LIBVERS} -ledit
LDFLAGS=${LDAPLDFLAGS}

CLEANFILES=	iprop-commands.h iprop-commands.c

iprop-commands.h: iprop-commands.in
	${SLC} ${.ALLSRC:M*.in}

iprop-commands.c: iprop-commands.h

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/lib/kadm5
