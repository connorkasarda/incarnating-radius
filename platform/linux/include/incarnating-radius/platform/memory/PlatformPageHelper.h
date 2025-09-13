#ifndef PLATFORM_PAGE_HELPER_H
#define PLATFORM_PAGE_HELPER_H

namespace IncarnatingRadius::Platform::Memory
{
    class PlatformPageHelper
    {
    public:
        /**
         * @brief Acquiring function
         * @param size Amount of memory to acquire
         * @param alignment Defines pattern for acceptable memory addresses
         * @return pointer to acquired OS page memory block
         */
        static void* acquire(std::size_t size, std::size_t alignment);

        /**
         * @brief Releasing function
         * @param pointer Location of OS page memory block
         * @param size Amount of memory to free
         * @param alignment Defines pattern for acceptable addresses
         */
        static void release(void* pointer, std::size_t size, std::size_t alignment) noexcept;
    }; // class PlatformPageHelper
} // namespace IncarnatingRadius::Platform::Memory

#endif
