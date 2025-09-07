#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

namespace IncarnatingRadius::Memory
{
    class MemoryAllocator
    {
    public:
        /** @brief Destructor */
       virtual ~MemoryAllocator() = default;
    }; // class MemoryAllocator
} // namespace IncarnatingRadius::Memory

#endif // MEMORY_ALLOCATOR_H
