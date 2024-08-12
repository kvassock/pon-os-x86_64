#include <memory.h>

void memcpy(void *dest, void *src, size_t count) {
  char *dest_ptr = (char *)dest;
  char *src_ptr = (char *)src;
  for (size_t i = 0; i < count; ++i)
  {
    dest_ptr[i] = src_ptr[i];
  }
}
