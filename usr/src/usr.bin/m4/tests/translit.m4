dnl $FreeBSD: releng/10.3/usr.bin/m4/tests/translit.m4 234852 2012-04-30 22:00:34Z bapt $
dnl $OpenBSD: src/regress/usr.bin/m4/translit.m4,v 1.1 2010/03/23 20:11:52 espie Exp $
dnl first one should match, not second one
translit(`onk*', `**', `p_')
