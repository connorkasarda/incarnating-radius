#ifndef MEMORY_BACKEND_H
#define MEMORY_BACKEND_H

namespace IncarnatingRadius::Memory
{
    /**
     * @brief Raw memory backend interface
     */
    class MemoryBackend
    {
    public:
        /**
         * @brief Destructor
         */
        virtual ~MemoryBackend() = default;
        
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
    }; // class MemoryBackend
} // namespace IncarnatingRadius::Memory

#endif // MEMORY_BACKEND_H
