#ifndef PAGE_BACKEND_H
#define PAGE_BACKEND_H

#include <incarnating-radius/memory-management/backends/Backend.h>

namespace IncarnatingRadius::MemoryManagement::Backends
{
    class PageBackend : public Backend
    {
        PageBackend() = default;
        ~PageBackend() override = default;
    }; // class PageBackend
}; // namespace IncarnatingRadius::MemoryManagement::Backends

#endif // PAGE_BACKEND_H
