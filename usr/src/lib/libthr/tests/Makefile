# $FreeBSD: releng/10.3/lib/libthr/tests/Makefile 274578 2014-11-16 06:35:20Z ngie $

OBJTOP=		${.OBJDIR:H:H:H}
SRCTOP=		${.CURDIR:H:H:H}
TESTSRC=	${SRCTOP}/contrib/netbsd-tests/lib/libpthread

TESTSDIR=	${TESTSBASE}/lib/libthr

# TODO: t_name (missing pthread_getname_np support in FreeBSD)
NETBSD_ATF_TESTS_C=	barrier_test
NETBSD_ATF_TESTS_C+=	cond_test
NETBSD_ATF_TESTS_C+=	condwait_test
NETBSD_ATF_TESTS_C+=	detach_test
NETBSD_ATF_TESTS_C+=	equal_test
NETBSD_ATF_TESTS_C+=	fork_test
NETBSD_ATF_TESTS_C+=	fpu_test
NETBSD_ATF_TESTS_C+=	join_test
NETBSD_ATF_TESTS_C+=	kill_test
NETBSD_ATF_TESTS_C+=	mutex_test
NETBSD_ATF_TESTS_C+=	once_test
NETBSD_ATF_TESTS_C+=	preempt_test
NETBSD_ATF_TESTS_C+=	rwlock_test
NETBSD_ATF_TESTS_C+=	sem_test
NETBSD_ATF_TESTS_C+=	sigmask_test
NETBSD_ATF_TESTS_C+=	sigsuspend_test
NETBSD_ATF_TESTS_C+=	siglongjmp_test
NETBSD_ATF_TESTS_C+=	sleep_test
NETBSD_ATF_TESTS_C+=	swapcontext_test

NETBSD_ATF_TESTS_SH=	atexit_test
NETBSD_ATF_TESTS_SH+=	cancel_test
NETBSD_ATF_TESTS_SH+=	exit_test
NETBSD_ATF_TESTS_SH+=	resolv_test

DPADD+=		${LIBPTHREAD}
LDADD+=		-lpthread
DPADD.fpu_test+=	${LIBM}
LDADD.fpu_test+=	-lm
DPADD.sem_test+=	${LIBRT}
LDADD.sem_test+=	-lrt

BINDIR=		${TESTSDIR}

PROGS=		h_atexit
PROGS+=		h_cancel
PROGS+=		h_exit
PROGS+=		h_resolv

FILESDIR=	${TESTSDIR}
FILES=		d_mach

TESTS_SUBDIRS=		dlopen

.include <netbsd-tests.test.mk>

CFLAGS.condwait_test+=	-I${SRCTOP}/contrib/netbsd-tests/lib/libc/gen

.include <bsd.test.mk>
