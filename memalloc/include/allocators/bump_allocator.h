#ifndef BUMP_ALLOCATOR_H
#define BUMP_ALLOCATOR_H

#include <allocators/memory_allocator.h>
#include <backend/memory_backend.h>

namespace IncarnatingRadius::Memory
{
    /// A simple linear allocator that just "bumps" a pointer forward
    class BumpAllocator : public MemoryAllocator
    {
    public:
        /// Constructor
        explicit BumpAllocator(MemoryBackend& backend, size_t size);

        /// Destructor
        ~BumpAllocator() override;

        /**
         * @brief Allocates a portion of memory from backend
         * @param size Amount of memory to allocate from backend
         * @param alignment Alignment of memory
         * @return Pointer to memory
         */
        void* allocate(size_t size, size_t alignment) override;

        /**
         * @brief Convenience allocate function for object of type T
         * @return Pointer to memory for object T
         */
        template<typename T>
        T* allocate();

        /// Resets memory pointer
        void reset() override;

    private:
        uint8_t* m_start = nullptr;
        size_t m_capacity = 0;
        size_t m_offset = 0;
    }; // class BumpAllocator

    template<typename T>
    T* BumpAllocator::allocate()
    {
        return static_cast<T*>(allocate(sizeof(T), alignof(T)));
    }

} // namespace IncarnatingRadius::Memory

#endif
