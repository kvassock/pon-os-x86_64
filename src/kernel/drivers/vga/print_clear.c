#include <vga.h>

void print_clear() {
  for (size_t i = 0; i < NUM_ROWS; i++) {
    clear_row(i);
  }
  row = 0;
  col = 0;
  update_cursor();
}

