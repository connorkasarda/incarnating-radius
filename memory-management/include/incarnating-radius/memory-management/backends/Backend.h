#ifndef BACKEND_H
#define BACKEND_H

namespace IncarnatingRadius::MemoryManagement::Backends
{
    struct Backend
    {
        virtual ~Backend() = default;
    }; // struct Backend
} // namespace IncarnatingRadius::MemoryManagement::Backends

#endif // BACKEND_H
