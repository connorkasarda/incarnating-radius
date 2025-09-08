#include <incarnating-radius/platform/memory/PlatformPageHelper.h>
#include <iostream>
#include <windows.h>

namespace IncarnatingRadius::Platform::Memory
{
    void* PlatformPageHelper::acquire(std::size_t size, std::size_t alignment)
    {
        size_t alignedSize = size + alignment - 1;

        void* basePtr = VirtualAlloc(NULL, alignedSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (basePtr == nullptr)
            return nullptr;        

        uintptr_t alignedPtr = reinterpret_cast<uintptr_t>(basePtr) + alignment - 1;
        alignedPtr &= ~(alignment - 1);

        return reinterpret_cast<void*>(alignedPtr);
    }

    void PlatformPageHelper::release(void* pointer, std::size_t size, std::size_t alignment) noexcept
    {
        uintptr_t basePtr = reinterpret_cast<uintptr_t>(pointer) - alignment - 1;

        if (!VirtualFree(reinterpret_cast<void*>(basePtr), 0, MEM_RELEASE)
            std::cerr << "VirtualFree failed" << std::endl;
    } 
} // namespace IncarnatingRadius::Platform::Memory
