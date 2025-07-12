#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    #define PLATFORM_WINDOWS 1
#else
    #define PLATFORM_WINDOWS 0
#endif

#if defined(__linux__)
    #define PLATFORM_LINUX 1
#else
    #define PLATFORM_LINUX 0
#endif

#if defined(__APPLE__) && defined(__MACH__)
    #define PLATFORM_MAC 1
#else
    #define PLATFORM_MAC 0
#endif

#if defined(__unix__) || defined(__unix) || PLATFORM_MAC || PLATFORM_LINUX
    #define PLATFORM_UNIX 1
#else
    #define PLATFORM_UNIX 0
#endif 

#if !PLATFORM_WINDOWS && !PLATFORM_LINUX && !PLATFORM_MAC && !PLATFORM_UNIX
    #error "PLATFORM UNKNOWN"
#endif

#endif
