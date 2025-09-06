#include <incarnating-radius/memory-management/storage/HeapStorage.h>
#include <new>
#include <cstdlib>

namespace IncarnatingRadius::MemoryManagement::Storage
{
    void* acquire(std::size_t size, std::size_t alignment)
    {
        return ::operator new(size, std::align_val_t(alignment));
    }

    void release(void* pointer, std::size_t size, std::size_t alignment)
    {
       ::operator delete(pointer, size, std::align_val_t(alignment)); 
    }
} // namespace IncarnatingRadius::MemoryManagement::Storage

