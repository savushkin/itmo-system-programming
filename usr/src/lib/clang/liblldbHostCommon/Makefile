# $FreeBSD: releng/10.3/lib/clang/liblldbHostCommon/Makefile 269024 2014-07-23 19:35:02Z emaste $

.include <bsd.own.mk>

LIB=	lldbHostCommon

SRCDIR=	tools/lldb/source/Host/common
SRCS=	Condition.cpp \
	DynamicLibrary.cpp \
	Editline.cpp \
	File.cpp \
	FileSpec.cpp \
	Host.cpp \
	Mutex.cpp \
	OptionParser.cpp \
	ProcessRunLock.cpp \
	SocketAddress.cpp \
	Symbols.cpp \
	Terminal.cpp \
	TimeValue.cpp

TGHDRS=	DiagnosticCommonKinds \
	DeclNodes \
	StmtNodes \
	CommentCommandList

.include "../lldb.lib.mk"
