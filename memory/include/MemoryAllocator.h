#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include <cstddef>

namespace IncarnatingRadius::Memory
{
    class MemoryAllocator
    {
        virtual void* allocate(size_t size,
                               size_t alignment = alignof(std::max_align_t)) = 0;
        virtual void deallocate(void* ptr) = 0;
        virtual void reset() = 0;
        virtual ~MemoryAllocator() = default;
    }; // class MemoryAllocator
} // namespace IncarnatingRadius

#endif
