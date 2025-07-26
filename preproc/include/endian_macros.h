#ifndef ENDIAN_MACROS_H
#define ENDIAN_MACROS_H

#define ENDIAN_BIG    0
#define ENDIAN_LITTLE 0

#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__AARCH64EB__)
    #undef ENDIAN_BIG
    #define ENDIAN_BIG 1
#elif defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN || \
    defined(__LITTLE_ENDIAN__) || \
    defined(__ARMEL__) || \
    defined(__AARCH64EL__)
    #undef ENDIAN_LITTLE
    #define ENDIAN_LITTLE 1
#else
    #error "ENDIANNESS UNKNOWN"
#endif

#endif
