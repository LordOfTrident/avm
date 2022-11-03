#ifndef UTILS_H__HEADER_GUARD__
#define UTILS_H__HEADER_GUARD__

#include <stdio.h>  /* stderr, fprintf */
#include <stdlib.h> /* exit, EXIT_FAILURE */
#include <stdarg.h> /* va_list, va_start, va_end, vsnprintf */
#include <assert.h> /* assert */

#include "platform.h"

#if defined(__COMPILER_GCC__) || defined(__COMPILER_CLANG__)
#	define PACK(p_struct) p_struct __attribute__((__packed__))
#elif defined(__COMPILER_MSVC__)
#	define PACK(p_struct) __pragma(pack(push, 1)) p_struct __pragma(pack(pop))
#else
#	define PACK(p_struct) p_struct __attribute__((__packed__))
#endif

#define UNREACHABLE() fatal("%s:%i: Unreachable", __FILE__, __LINE__)
#define TODO(P_MSG)   fatal("%s:%i: TODO: %s", __FILE__, __LINE__, P_MSG)

#define SILENCE_RETURN_WARNING() \
	fprintf(stderr, "%s:%i: Reached unreachable return warning silencer\n", __FILE__, __LINE__); \
	exit(EXIT_FAILURE)

void fatal(const char *p_fmt, ...);

#endif
