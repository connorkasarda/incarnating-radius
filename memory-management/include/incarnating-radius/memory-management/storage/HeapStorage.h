#ifndef HEAP_STORAGE_H
#define HEAP_STORAGE_H

#include <incarnating-radius/memory-management/storage/Storage.h>

namespace IncarnatingRadius::MemoryManagement::Storage
{
    class HeapStorage : public Storage
    {
    public:
        /**
         * @brief Constructor
         */
        HeapStorage() = default;

        /**
         * @brief Destructor
         */
        ~HeapStorage() override = default;
        
        /**
         * @brief Obtains a block of memory via the heap
         * @param size Amount of heap memory to reserve
         * @param alignment Defines pattern for acceptable addresses
         * @return pointer to acquired memory block
         */
        void* acquire(std::size_t size, std::size_t alignment) override;

        /**
         * @brief Relinquishes control of heap memory block
         * @param pointer Location of memory block
         * @param size Size of memory block
         * @param alignment Defines pattern for acceptable addresses
         */
        void release(void* pointer, std::size_t size, std::size_t alignment) override;
    }; // class HeapStorage
} // namespace IncarnatingRadius::MemoryManagement::Storage

#endif // HEAP_STORAGE_H
