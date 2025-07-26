#ifndef SYSTEM_MEMORY_BACKEND_H
#define SYSTEM_MEMORY_BACKEND_H

#include <backend/memory_backend.h>

namespace IncarnatingRadius::Memory
{
    /// Acquires raw pages from the OS for memory allocators to use
    class SystemMemoryBackend : public MemoryBackend
    {
    public:
        /// Constructor
        SystemMemoryBackend() = default;
        /// Destructor
        ~SystemMemoryBackend() override = default;
        /**
         * @brief Hands off raw memory from the OS
         * @param size Amount of raw memory to acquire
         * @param alignment Alignment of the raw memory
         * @return Pointer to the raw memory
         */
        void* allocate(size_t size, size_t alignment) override;
        /**
         * @brief Releases access to raw memory from OS
         * @param ptr Pointer to the raw memory
         * @param size Amount of raw memory to release
         */
        void deallocate(void* ptr, std::size_t size) override;
    }; // class SystemMemoryBackend
} // namespace IncarnatingRadius::Memory

#endif
