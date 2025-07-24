#ifndef BUMP_ALLOCATOR_H
#define BUMP_ALLOCATOR_H

namespace IncarnatingRadius::Memory
{
    /// A simple linear allocator that just "bumps" a pointer forward
    class BumpAllocator : public MemoryAllocator
    {
    public:
        explicit BumpAllocator(size_t size);
        ~BumpAllocator() override;
        void* allocate(size_t size, size_t alignment) override;
        template<typename T>
        T* allocate() override;
        void deallocate(void* ptr);
        void reset() override;
    private:
        uint8_t* m_start = nullptr;
        size_t m_capacity = 0;
        size_t m_offset = 0;
    }; // class BumpAllocator
} // namespace IncarnatingRadius::Memory

#endif
