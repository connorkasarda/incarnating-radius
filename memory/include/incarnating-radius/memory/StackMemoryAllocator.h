#ifndef STACK_MEMORY_ALLOCATOR_H
#define STACK_MEMORY_ALLOCATOR_H

#include <incarnating-radius/memory/MemoryAllocator.h>

namespace IncarnatingRadius::Memory
{
    class StackMemoryAllocator : public MemoryAllocator
    {
    public:
        /** @brief Constructor */
        StackMemoryAllocator() = default;

        /** @brief Destructor */
        ~StackMemoryAllocator() override = default; 
    }; // class StackMemoryAllocator
} // namespace IncarnatingRadius::Memory

#endif // STACK_MEMORY_ALLOCATOR_H
