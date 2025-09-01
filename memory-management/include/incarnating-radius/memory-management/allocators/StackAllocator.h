#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include <incarnating-radius/memory-management/allocators/Allocator.h>

namespace IncarnatingRadius::MemoryManagement::Allocators
{
    class StackAllocator : public Allocator
    {
    public:
        StackAllocator() = default;
        ~StackAllocator() override = default; 
    }; // class StackAllocator
} // namespace IncarnatingRadius::MemoryManagement::Allocators

#endif // STACK_ALLOCATOR_H
