#include <memory.h>

void memset(void *dest, char value, size_t count)
{
  char *dest_ptr = (char *)dest;
  for (size_t i = 0; i < count; ++i)
  {
    dest_ptr[i] = value;
  }
}