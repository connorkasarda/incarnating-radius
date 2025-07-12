#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#define ARCH_X64   0
#define ARCH_X86   0
#define ARCH_ARM64 0
#define ARCH_ARM   0

#if defined(__x86_64__) || defined(_M_X64)
    #undef ARCH_X64
    #define ARCH_X64 1
#elif defined(__i386__) || defined(_M_IX86)
    #undef ARCH_X86
    #define ARCH_X86 1
#elif defined(__aarch64__) || defined(_M_ARM64)
    #undef ARCH_ARM64
    #define ARCH_ARM64 1
#elif defined(__arm__) || defined(_M_ARM)
    #undef ARCH_ARM
    #define ARCH_ARM 1
#else
    #error "ARCHITECTURE UNKNOWN"
#endif

#endif
