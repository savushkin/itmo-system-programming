# $FreeBSD: releng/10.3/cddl/lib/libnvpair/Makefile 292973 2015-12-31 03:28:14Z ngie $

.PATH: ${.CURDIR}/../../../cddl/contrib/opensolaris/lib/libnvpair
.PATH: ${.CURDIR}/../../../sys/cddl/contrib/opensolaris/common/nvpair

LIB=	nvpair

SRCS=	libnvpair.c \
	nvpair_alloc_system.c \
	nvpair_json.c \
	opensolaris_fnvpair.c \
	opensolaris_nvpair.c \
	opensolaris_nvpair_alloc_fixed.c

WARNS?=	0
CFLAGS+= -I${.CURDIR}/../../../cddl/compat/opensolaris/include
CFLAGS+= -I${.CURDIR}/../../../cddl/contrib/opensolaris/lib/libzpool/common
CFLAGS+= -I${.CURDIR}/../../../sys/cddl/compat/opensolaris
CFLAGS+= -I${.CURDIR}/../../../sys/cddl/contrib/opensolaris/uts/common
CFLAGS+= -I${.CURDIR}/../../../sys/cddl/contrib/opensolaris/uts/common/fs/zfs
CFLAGS+= -I${.CURDIR}/../../../sys
CFLAGS+= -I${.CURDIR}/../../../cddl/contrib/opensolaris/head
CFLAGS+= -I${.CURDIR}/../../../cddl/compat/opensolaris/lib/libumem

.include <bsd.lib.mk>
