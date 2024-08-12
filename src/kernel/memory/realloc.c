#include <memory.h>

void* realloc(void* ptr, size_t new_size) {
  void* new_ptr = malloc(new_size);
  if (new_ptr == NULL) {
    return NULL;
  }

  size_t old_size = sizeof(ptr);
  size_t copy_size = old_size < new_size? old_size : new_size;
  memcpy(new_ptr, ptr, copy_size);

  free(ptr);
  return new_ptr;
}
