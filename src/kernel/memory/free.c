#include <memory.h>

typedef struct block {
    size_t size;  
    bool free;    
    struct block* next; 
} block_t;

static block_t* head = NULL;

void free(void* ptr) {
  if (ptr == NULL) {
      return; 
  }

  block_t* block = (block_t*)((char*)ptr - sizeof(block_t));
  block->free = true;
}