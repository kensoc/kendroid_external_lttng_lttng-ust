#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER lttng_ust_dl

#if !defined(_TRACEPOINT_UST_DL_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_UST_DL_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Copyright (C) 2013  Paul Woegerer <paul_woegerer@mentor.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdint.h>
#include <unistd.h>

#define LTTNG_UST_DL_PROVIDER
#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(lttng_ust_dl, dlopen,
	TP_ARGS(void *, baddr, const char*, sopath, int64_t, size,
		int64_t, mtime, void *, ip),
	TP_FIELDS(
		ctf_integer_hex(void *, baddr, baddr)
		ctf_string(sopath, sopath)
		ctf_integer(int64_t, size, size)
		ctf_integer(int64_t, mtime, mtime)
	)
)

TRACEPOINT_EVENT(lttng_ust_dl, dlclose,
	TP_ARGS(void *, baddr, void *, ip),
	TP_FIELDS(
		ctf_integer_hex(void *, baddr, baddr)
	)
)

#endif /* _TRACEPOINT_UST_DL_H */

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./ust_dl.h"

/* This part must be outside ifdef protection */
#include <lttng/tracepoint-event.h>

#ifdef __cplusplus
}
#endif
