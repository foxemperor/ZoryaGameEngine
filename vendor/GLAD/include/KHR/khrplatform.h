#ifndef __khrplatform_h_
#define __khrplatform_h_

/*
** Copyright (c) 2008-2018 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Platform-specific types and definitions. */

#if defined(__SCITECH_SNAP__) && !defined(KHRONOS_STATIC)
#   define KHRONOS_STATIC 1
#endif

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#include <windows.h>
#endif

#include <stdint.h>

typedef int8_t   khronos_int8_t;
typedef uint8_t  khronos_uint8_t;
typedef int16_t  khronos_int16_t;
typedef uint16_t khronos_uint16_t;
typedef int32_t  khronos_int32_t;
typedef uint32_t khronos_uint32_t;
typedef int64_t  khronos_int64_t;
typedef uint64_t khronos_uint64_t;

typedef float    khronos_float_t;

#if defined(_WIN64)
typedef signed   long long int khronos_intptr_t;
typedef unsigned long long int khronos_uintptr_t;
typedef signed   long long int khronos_ssize_t;
typedef unsigned long long int khronos_usize_t;
#elif defined(_WIN32)
typedef signed   long int khronos_intptr_t;
typedef unsigned long int khronos_uintptr_t;
typedef signed   long int khronos_ssize_t;
typedef unsigned long int khronos_usize_t;
#else
#include <sys/types.h>
typedef ssize_t  khronos_ssize_t;
typedef size_t   khronos_usize_t;
typedef intptr_t khronos_intptr_t;
typedef uintptr_t khronos_uintptr_t;
#endif

typedef unsigned long int khronos_utime_nanoseconds_t;
typedef long int          khronos_time_ns_t;
typedef unsigned int      khronos_date_t;
typedef unsigned char     khronos_boolean_enum_t;

#define KHRONOS_FALSE   0
#define KHRONOS_TRUE    1
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif /* __khrplatform_h_ */
