# $FreeBSD: releng/10.3/kerberos5/libexec/digest-service/Makefile 287428 2015-09-03 11:33:33Z ume $

PROG=	digest-service
MAN=
CFLAGS+=	-I${KRB5DIR}/kdc \
		-I${KRB5DIR}/lib/asn1 \
		-I${KRB5DIR}/lib/krb5 \
		-I${KRB5DIR}/lib/ipc \
		-I${KRB5DIR}/lib/wind \
		-I${KRB5DIR}/lib/roken
DPADD=	${LIBHDB} ${LIBKDC} ${LIBHEIMIPCS} ${LIBKRB5} ${LIBROKEN} ${LIBASN1} \
	${LIBCRYPTO} ${LIBCRYPT} ${LIBVERS}
LDADD=	-lhdb -lkdc -lheimipcs -lkrb5 -lroken -lasn1 -lcrypto -lcrypt \
	${LIBVERS} -lheimntlm
LDFLAGS=${LDAPLDFLAGS}
USEPRIVATELIB= heimipcs

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/kdc
