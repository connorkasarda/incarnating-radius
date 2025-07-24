#ifndef MEMORY_PROVIDER_H
#define MEMORY_PROVIDER_H

namespace IncarnatingRadius::Memory
{
    /// Memory provider interface for strategies that preallocate memory based on OS and other factors
    class MemoryProvider
    {
    public:
        /// Destructor
        virtual ~MemoryProvider() = default;
        /**
         * @brief Provides pre-allocated memory block for allocator to use
         * @param size Amount of memory to provide
         * @param alignment Alignment for memory
         * @return Pointer to the pre-allocated memory
         */
        virtual void* provide(size_t size,
                              size_t alignment = alignof(std::max_align_t)) = 0;
        /**
         * @brief Releases the pre-allocated memory
         * @param ptr Pointer to the memory
         * @param size Amount of memory to remove
         */
        virtual void release(void* ptr, std::size_t size) = 0;
    }; // class MemoryProvider
} // namespace IncarnatingRadius::Memory

#endif
