#include <incarnating-radius/memory/backend/HeapMemoryBackend.h>
#include <new>

namespace IncarnatingRadius::Memory::Backend
{
    void* HeapMemoryBackend::acquire(std::size_t size, std::size_t alignment)
    {
        return ::operator new(size, std::align_val_t(alignment));
    }

    void HeapMemoryBackend::release(void* pointer, std::size_t size, std::size_t alignment) noexcept
    {
       ::operator delete(pointer, size, std::align_val_t(alignment)); 
    }
} // namespace IncarnatingRadius::Memory::Backend

