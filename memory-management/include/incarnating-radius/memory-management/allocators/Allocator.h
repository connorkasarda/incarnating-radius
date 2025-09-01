#ifndef ALLOCATOR_H
#define ALLOCATOR_H

namespace IncarnatingRadius::MemoryManagement::Allocators
{
    struct Allocator
    {
       virtual ~Allocator() = default;
    }; // struct Allocator
} // namespace IncarnatingRadius::MemoryManagement::Allocators

#endif // ALLOCATOR_H
