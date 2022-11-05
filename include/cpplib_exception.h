#ifndef __CPPLIB_EXCEPTION_H__
#define __CPPLIB_EXCEPTION_H__

#include <stdio.h>
#include <stdarg.h>

namespace cpplib {

enum exception_type {
    runtime_exception,
    memory_exception,
};

static inline exception_type print_error(exception_type type,
                                         const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    return type;
}

// Throws runtime error
#define runtime_error(__fmt, ...) \
        print_error(exception_type::runtime_exception, __fmt, \
                    ##__VA_ARGS__)

// Throws memory error
#define memory_error(__fmt, ...) \
        print_error(exception_type::memory_exception, __fmt, \
                    ##__VA_ARGS__)
}

#endif

