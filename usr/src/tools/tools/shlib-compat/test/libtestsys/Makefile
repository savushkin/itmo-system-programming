# $FreeBSD: releng/10.3/tools/tools/shlib-compat/test/libtestsys/Makefile 248693 2013-03-25 00:31:14Z gleb $

TESTNUM=	sys

CLEANFILES+= test.c

.include <../Makefile.inc>
.include <bsd.lib.mk>

test.c: ../../makesyscalls-fake.sh
	sh ${.CURDIR}/../../makesyscalls-fake.sh /usr/src/sys/kern/syscalls.master > ${.TARGET}
