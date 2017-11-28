/*
 * Copyright (c) 2004 David Xu <davidxu@freebsd.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: releng/10.3/lib/libkse/thread/thr_symbols.c 174689 2007-12-16 23:29:57Z deischen $
 */

#include "namespace.h"
#include <sys/types.h>
#include <stddef.h>
#include <pthread.h>
#include <rtld.h>
#include "un-namespace.h"

#include "thr_private.h"

/* A collection of symbols needed by debugger */

/* int _libkse_debug */
int _thread_off_tcb = offsetof(struct pthread, tcb);
int _thread_off_tmbx = offsetof(struct tcb, tcb_tmbx);
int _thread_off_next = offsetof(struct pthread, tle.tqe_next);
int _thread_off_attr_flags = offsetof(struct pthread, attr.flags);
int _thread_off_kse = offsetof(struct pthread, kse);
int _thread_off_kse_locklevel = offsetof(struct kse, k_locklevel);
int _thread_off_thr_locklevel = offsetof(struct pthread, locklevel);
int _thread_off_linkmap = offsetof(Obj_Entry, linkmap);
int _thread_off_tlsindex = offsetof(Obj_Entry, tlsindex);
int _thread_size_key = sizeof(struct pthread_key);
int _thread_off_key_allocated = offsetof(struct pthread_key, allocated);
int _thread_off_key_destructor = offsetof(struct pthread_key, destructor);
int _thread_max_keys = PTHREAD_KEYS_MAX;
int _thread_off_dtv = DTV_OFFSET;
int _thread_off_state = offsetof(struct pthread, state);
int _thread_state_running = PS_RUNNING;
int _thread_state_zoombie = PS_DEAD;
int _thread_off_sigmask = offsetof(struct pthread, sigmask);
int _thread_off_sigpend = offsetof(struct pthread, sigpend);
