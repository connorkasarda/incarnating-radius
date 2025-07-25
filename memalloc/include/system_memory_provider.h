#ifndef SYSTEM_MEMORY_PROVIDER_H
#define SYSTEM_MEMORY_PROVIDER_H

#include <memory_provider.h>

namespace IncarnatingRadius::Memory
{
    /// Acquires raw pages from the OS for memory allocators to use
    class SystemMemoryProvider : public MemoryProvider
    {
    public:
        /// Constructor
        SystemMemoryProvider() = default;
        /// Destructor
        ~SystemMemoryProvider() override = default;
        /**
         * @brief Hands off raw memory from the OS
         * @param size Amount of raw memory to acquire
         * @param alignment Alignment of the raw memory
         * @return Pointer to the raw memory
         */
        void* provide(size_t size, size_t alignment) override;
        /**
         * @brief Releases access to raw memory from OS
         * @param ptr Pointer to the raw memory
         * @param size Amount of raw memory to release
         */
        void release(void* ptr, std::size_t size) override;
    }; // class SystemMemoryProvider
} // namespace IncarnatingRadius::Memory

#endif
