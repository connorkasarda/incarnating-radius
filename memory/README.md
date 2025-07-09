# 💾 Memory Allocation

Implements control strategies for blocks of memory

# Milestones

- [ ] **bump** (moves pointer forward, only reset)
- [ ] **stack** (bump w/ dealloc of last alloc, LIFO)
- [ ] **double-ended stack** (two stack pointers growing towards the middle)
- [ ] **pool** (fixed blocks, useful for particles, bullets, etc.)
- [ ] **free list** (list of free blocks)
- [ ] **slab** (pool w/ unfixed block sizes)
- [ ] **buddy** (allocs in powers of 2, for fragmentation control)
- [ ] **TLSF** (Two-Level Segregated Fit)
- [ ] **region** (linear but allocs in chunks, frees all at once)
- [ ] **arena** (collection of memory blocks)
- [ ] **paged** (large allocs or streaming resources)
- [ ] **general** (slow, for strange unusual cases)
