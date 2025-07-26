#include <system_memory_backend.h>
#include <platform_macros.h>
#include <memory_macros.h>

#if PLATFORM_WINDOWS
#include <windows.h>
#elif PLATFORM_LINUX
#include <sys/mman.h>
#include <unistd.h>
#endif

void* IncarnatingRadius::Memory::SystemMemoryBackend::allocate(size_t size, size_t alignment)
{
#if PLATFORM_WINDOWS
    void* ptr = VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!ptr)
    {
        HANDLE_ALLOC_FAILURE;
    }
    return ptr;
#elif PLATFORM_LINUX
    void* ptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (ptr == MAP_FAILED)
    {
        HANDLE_ALLOC_FAILURE;
    }
    return ptr;
#else
    HANDLE_ALLOC_UNSUPPORTED_PLATFORM;
#endif
}

void IncarnatingRadius::Memory::SystemMemoryBackend::deallocate(void* ptr, size_t size)
{
#if PLATFORM_WINDOWS
    if (!VirtualFree(ptr, 0, MEM_RELEASE))
    {
        HANDLE_DEALLOC_FAILURE;        
    }
#elif PLATFORM_LINUX
    if (munmap(ptr, size) != 0)
    {
        HANDLE_DEALLOC_FAILURE;
    }
#else
    HANDLE_DEALLOC_UNSUPPORTED_PLATFORM;
#endif
}
