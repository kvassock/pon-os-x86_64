#include <memory.h>

static char memory_pool[MEMORY_POOL_SIZE];
static size_t used_memory = 0;

void *malloc(size_t size) {
  if (size == 0) {
    return NULL;
  }

  size = (size + 7) & ~7;

  if (used_memory + size > MEMORY_POOL_SIZE) {
    return NULL;
  }

  void *ptr = memory_pool + used_memory;
  used_memory += size;

  return ptr;
}
