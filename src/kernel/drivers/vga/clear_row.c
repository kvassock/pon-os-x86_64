#include <vga.h>

void clear_row(size_t row) {
  struct Char empty = (struct Char) {
    character: ' ',
    color: color
  };

  for (size_t col = 0; col < NUM_COLS; col++) {
    buffer[col + NUM_COLS * row] = empty;
  }

  update_cursor();
}