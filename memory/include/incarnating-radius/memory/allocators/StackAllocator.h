#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include <incarnating-radius/memory/allocators/Allocator.h>

namespace IncarnatingRadius::Memory::Allocators
{
    class StackAllocator : public Allocator
    {
    public:
        StackAllocator() = default;
        ~StackAllocator() override = default; 
    }; // class StackAllocator
} // namespace IncarnatingRadius::Memory::Allocators

#endif // STACK_ALLOCATOR_H
