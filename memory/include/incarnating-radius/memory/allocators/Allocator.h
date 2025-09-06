#ifndef ALLOCATOR_H
#define ALLOCATOR_H

namespace IncarnatingRadius::Memory::Allocators
{
    struct Allocator
    {
       virtual ~Allocator() = default;
    }; // struct Allocator
} // namespace IncarnatingRadius::Memory::Allocators

#endif // ALLOCATOR_H
