#ifndef STORAGE_H
#define STORAGE_H

namespace IncarnatingRadius::MemoryManagement::Storage
{
    /**
     * @brief Raw memory backend interface
     */
    struct Storage
    {
        /**
         * @brief Destructor
         */
        virtual ~Storage() = default;
        
        /**
         * @brief Obtains a block of memory for use
         * @param size Amount of memory to reserve
         * @param alignment Defines pattern for acceptable addresses
         * @return pointer to acquired memory block
         */
        virtual void* acquire(std::size_t size, std::size_t alignment) = 0;

        /**
         * @brief Relinquishes control of memory block
         * @param pointer Location of memory block
         * @param size Size of memory block
         * @param alignment Defines pattern for acceptable addresses
         */
        virtual void release(void* pointer, std::size_t size, std::size_t alignment) = 0;
    }; // struct Storage
} // namespace IncarnatingRadius::MemoryManagement::Storage

#endif // STORAGE_H
