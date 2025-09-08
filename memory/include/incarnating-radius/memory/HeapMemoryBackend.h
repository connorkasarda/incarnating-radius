#ifndef HEAP_MEMORY_BACKEND_H
#define HEAP_MEMORY_BACKEND_H

#include <incarnating-radius/memory/MemoryBackend.h>

namespace IncarnatingRadius::Memory
{
    class HeapMemoryBackend : public MemoryBackend
    {
    public:
        /**
         * @brief Constructor
         */
        HeapMemoryBackend() = default;

        /**
         * @brief Destructor
         */
        ~HeapMemoryBackend() override = default;
        
        /**
         * @brief Obtains a block of memory via the heap
         * @param size Amount of heap memory to reserve
         * @param alignment Defines pattern for aligning memory
         * @return pointer to acquired memory block
         */
        void* acquire(std::size_t size, std::size_t alignment) override;

        /**
         * @brief Relinquishes control of heap memory block
         * @param pointer Location of memory block
         * @param size Size of memory block
         * @param alignment Defines pattern for aligning memory
         */
        void release(void* pointer, std::size_t size, std::size_t alignment) noexcept override;
    }; // class HeapMemoryBackend
} // namespace IncarnatingRadius::Memory

#endif // HEAP_MEMORY_BACKEND_H
