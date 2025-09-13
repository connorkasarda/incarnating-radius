#include <incarnating-radius/platform/memory/PlatformPageHelper.h>
#include <sys/mman.h>

namespace IncarnatingRadius::Platform::Memory
{
    void* PlatformPageHelper::acquire(std::size_t size, std::size_t alignment)
    {
        std::size_t alignedSize = size + alignment - 1;
        void* basePtr = 
            mmap(NULL, alignedSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        if (basePtr == MAP_FAILED)
            return nullptr;

        uintptr_t alignedPtr = reinterpret_cast<uintptr_t>(basePtr) + alignment - 1;
        alignedPtr &= ~(alignedPtr - 1);

        return reinterpret_cast<void*>(alignedPtr);
    }

    void PlatformPageHelper::release(void* pointer, std::size_t size, std::size_t alignment) noexcept
    {
        uintptr_t basePtr = reinterpret_cast<uintptr_t>(pointer) - alignment - 1;
        std::size_t alignedSize = size + alignment - 1;        

        if (munmap(reinterpret_cast<void*>(basePtr), alignedSize) < 0)
            return std::cerr << "munmap failed" << std::endl;
    }
} // namespace IncarnatingRadius::Platform::Memory
