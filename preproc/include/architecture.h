#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#if defined(__x86_64__) || defined(_M_X64)
    #define ARCH_X64 1
#else
    #define ARCH_X64 0
#endif

#if defined(__i386__) || defined(_M_IX86)
    #define ARCH_X86 1
#else
    #define ARCH_X86 0
#endif

#if defined(__aarch64__) || defined(_M_ARM64)
    #define ARCH_ARM64 1
#else
    #define ARCH_ARM64 0
#endif

#if defined(__arm__) || defined(_M_ARM)
    #define ARCH_ARM 1
#else
    #define ARCH_ARM 0
#endif

#if !ARCH_X64 && !ARCH_X86 && !ARCH_ARM64 && !ARCH_ARM
    #error "ARCHITECTURE UNKNOWN"
#endif

#endif
