#ifndef PLATFORM_MACROS_H
#define PLATFORM_MACROS_H

#define PLATFORM_WINDOWS 0
#define PLATFORM_LINUX   0
#define PLATFORM_MAC     0
#define PLATFORM_UNIX    0

#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    #undef PLATFORM_WINDOWS
    #define PLATFORM_WINDOWS 1
#elif defined(__linux__)
    #undef PLATFORM_LINUX
    #define PLATFORM_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
    #undef PLATFORM_MAC
    #define PLATFORM_MAC 1
#else
    #error "PLATFORM UNKNOWN"
#endif

#if defined(__unix__) || defined(__unix) || PLATFORM_MAC || PLATFORM_LINUX
    #undef PLATFORM_UNIX
    #define PLATFORM_UNIX 1
#endif

#endif
