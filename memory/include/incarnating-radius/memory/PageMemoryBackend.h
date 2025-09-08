#ifndef PAGE_MEMORY_BACKEND_H
#define PAGE_MEMORY_BACKEND_H

#include <incarnating-radius/memory/MemoryBackend.h>

namespace IncarnatingRadius::Memory
{
    /**
     * @brief OS Page memory backend
     */
    class PageMemoryBackend : public MemoryBackend
    {
    public:
        /**
         * @brief Constructor
         */
        PageMemoryBackend() = default;

        /**
         * @brief Destructor
         */
        ~PageMemoryBackend() override = default;

        /**
         * @brief Obtains a block of OS-specific page memory
         * @param size Amount of page memory to reserve
         * @param alignment Defines pattern for aligning memory
         * @return pointer to acquired memory block
         */
        void* acquire(std::size_t size, std::size_t alignment) override;
    
        /**
         * @brief Relinquishes control of OS-specific page memory
         * @param pointer Location of memory block
         * @param size Size of memory block
         * @param alignment Defines pattern for aligning memory
         */
        void release(void* pointer, std::size_t size, std::size_t alignment) noexcept override;
    }; // class PageMemoryBackend
}; // namespace IncarnatingRadius::Memory

#endif // PAGE_MEMORY_BACKEND_H
