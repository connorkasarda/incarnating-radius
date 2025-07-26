#ifndef MEMORY_MACROS_H
#define MEMORY_MACROS_H

#include <build_macros.h>
#include <new>            // std::runtime_error
#include <stdexcept>      // std::bad_alloc

#define HANDLE_ALLOC_FAILURE \
    do { \
#if BUILD_TYPE_DEBUG \
        throw std::bad_alloc(); \
#else \
        return nullptr; \
#endif \
    } while (0)

#define HANDLE_DEALLOC_FAILURE \
    do { \
#if BUILD_TYPE_DEBUG \
        throw std::runtime_error("Deallocation failed"); \
#else \
        return; \
#endif \
    } while (0)

#define HANDLE_ALLOC_UNSUPPORTED_PLATFORM \
    do { \
#if BUILD_TYPE_DEBUG \
        throw std::runtime_error("Allocation on unsupported platform"); \
#else \
        return nullptr; \
#endif \
    } while (0)

#define HANDLE_DEALLOC_UNSUPPORTED_PLATFORM \
    do { \
#if BUILD_TYPE_DEBUG \
        throw std::runtime_error("Deallocation on unsupported platform"); \
#else \
        return; \
#endif \
    } while (0)

#endif
