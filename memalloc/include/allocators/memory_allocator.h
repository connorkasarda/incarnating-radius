#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include <cstddef>

namespace IncarnatingRadius::Memory
{
    /// Interface for memory allocators
    class MemoryAllocator
    {
    public:
        /// Destructor
        virtual ~MemoryAllocator() = default;

        /**
         * @brief Returns pointer to memory for object
         * @param size Amount of memory required for object
         * @param alignment Memory alignment required for object
         * @return Pointer to allocated memory
         */
        virtual void* allocate(size_t size,
                               size_t alignment = alignof(std::max_align_t)) = 0;

        /// Resets entire memory block
        virtual void reset() = 0;

    }; // class MemoryAllocator
} // namespace IncarnatingRadius::Memory

#endif
