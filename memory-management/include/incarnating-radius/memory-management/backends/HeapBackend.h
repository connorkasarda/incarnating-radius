#ifndef HEAP_BACKEND_H
#define HEAP_BACKEND_H

#include <incarnating-radius/memory-management/backends/Backend.h>

namespace IncarnatingRadius::MemoryManagement::Backends
{
    class HeapBackend : public Backend
    {
    public:
        HeapBackend() = default;
        ~HeapBackend() override = default;
    }; // class HeapBackend
} // namespace IncarnatingRadius::MemoryManagement::Backends

#endif // HEAP_BACKEND_H
