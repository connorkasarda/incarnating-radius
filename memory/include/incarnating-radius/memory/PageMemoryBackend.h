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
    }; // class PageMemoryBackend
}; // namespace IncarnatingRadius::Memory

#endif // PAGE_MEMORY_BACKEND_H
