#ifndef INTRINSICS_MACROS_H
#define INTRINSICS_MACROS_H

#include <compiler.h>

#if COMPILER_GCC || COMPILER_CLANG
    #define INLINE inline
    #define FORCE_INLINE inline __attribute__((always_inline))
    #define RESTRICT __restrict__
#elif COMPILER_MSVC
    #define INLINE __inline
    #define FORCE_INLINE __forceinline
    #define RESTRICT __restrict
#else
    #define INLINE inline
    #define FORCE_INLINE inline
    #define RESTRICT 
#endif

#endif
