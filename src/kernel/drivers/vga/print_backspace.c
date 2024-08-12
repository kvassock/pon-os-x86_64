#include <vga.h>

void print_back_space() {
  col--;
  struct Char empty = {
      .character = ' ',
      .color = color,
  };
  buffer[col + NUM_COLS * row] = empty;
  update_cursor();
}
