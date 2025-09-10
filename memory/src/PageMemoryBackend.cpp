#include <incarnating-radius/memory/PageMemoryBackend.h>
#include <incarnating-radius/platform/memory/PlatformPageHelper.h>

namespace IRPlatMem = IncarnatingRadius::Platform::Memory;

namespace IncarnatingRadius::Memory
{
    void* PageMemoryBackend::acquire(std::size_t size, std::size_t alignment)
    {
        return IRPlatMem::PlatformPageHelper::acquire(size, alignment);
    }

    void PageMemoryBackend::release(void* pointer, std::size_t size, std::size_t alignment)
    {
        IRPlatMem::PlatformPageHelper::release(pointer, size, alignment);
    } 
} // namespace IncarnatingRadius::Memory
