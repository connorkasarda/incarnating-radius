#ifndef HEAP_STORAGE_H
#define HEAP_STORAGE_H

#include <incarnating-radius/memory-management/storage/Storage.h>

namespace IncarnatingRadius::MemoryManagement::Storage
{
    class HeapStorage : public Storage
    {
    public:
        HeapStorage() = default;
        ~HeapStorage() override = default;
    }; // class HeapStorage
} // namespace IncarnatingRadius::MemoryManagement::Storage

#endif // HEAP_STORAGE_H
