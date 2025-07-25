#include <system_memory_provider.h>
#include <platform.h>

#if PLATFORM_WINDOWS
#include <windows.h>
#elif PLATFORM_LINUX
#include <sys/mman.h>
#include <unistd.h>
#endif

void* IncarnatingRadius::Memory::SystemMemoryProvider::provide(size_t size, size_t alignment)
{
#if PLATFORM_WINDOWS
    void* ptr = VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!ptr)
    {
        throw std::bad_alloc();
    }
    return ptr;
#elif PLATFORM_LINUX
    void* ptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (ptr == MAP_FAILED)
    {
        throw std::bad_alloc();
    }
    return ptr;
#else
    return nullptr;
#endif
}

void IncarnatingRadius::Memory::SystemMemoryProvider::release(void* ptr, size_t size)
{
#if PLATFORM_WINDOWS
    
#elif PLATFORM_LINUX
    
#else

#endif
}
