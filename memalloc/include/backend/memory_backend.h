#ifndef MEMORY_BACKEND_H
#define MEMORY_BACKEND_H

#include <cstddef>

namespace IncarnatingRadius::Memory
{
    /// Interface that provides memory stores for allocators
    class MemoryBackend
    {
    public:
        /// Destructor
        virtual ~MemoryBackend() = default;

        /**
         * @brief Provides pre-allocated memory block for allocator to use
         * @param size Amount of memory to provide
         * @param alignment Alignment for memory
         * @return Pointer to the pre-allocated memory
         */
        virtual void* allocate(size_t size,
                               size_t alignment = alignof(std::max_align_t)) = 0;

        /**
         * @brief Releases the pre-allocated memory
         * @param ptr Pointer to the memory
         * @param size Amount of memory to remove
         */
        virtual void deallocate(void* ptr, std::size_t size) = 0;

    }; // class MemoryBackend
} // namespace IncarnatingRadius::Memory

#endif
