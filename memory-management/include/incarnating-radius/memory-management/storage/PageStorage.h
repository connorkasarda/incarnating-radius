#ifndef PAGE_STORAGE_H
#define PAGE_STORAGE_H

#include <incarnating-radius/memory-management/storage/Storage.h>

namespace IncarnatingRadius::MemoryManagement::Storage
{
    class PageStorage : public Storage
    {
    public:
        PageStorage() = default;
        ~PageStorage() override = default;
    }; // class PageStorage
}; // namespace IncarnatingRadius::MemoryManagement::Storage

#endif // PAGE_STORAGE_H
