#ifndef COMPILER_MACROS_H
#define COMPILER_MACROS_H

#define COMPILER_GCC  0
#define COMPILER_MSCV  0
#define COMPILER_CLANG 0

#if defined(__GNUC__) || defined(__GNUC_MINOR__) || defined(__GNUC_PATCHLEVEL__)
    #undef COMPILER_GCC
    #define COMPILER_GCC 1
#elif defined(_MSC_VER)
    #undef COMPILER_MSCV
    #define COMPILER_MSCV 1
#elif defined(__clang__) || defined(__clang_major__) || defined(__clang_minor__)
    #undef COMPILER_CLANG
    #define COMPILER_CLANG 1
#else
    #error "COMPILER UNKNOWN"
#endif

#endif
