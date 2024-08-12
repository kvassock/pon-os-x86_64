#include <vga.h>

void print_newline() {
  col = 0;

  if (row < NUM_ROWS - 1) {
    row++;
    return;
  }

  for (size_t row = 1; row < NUM_ROWS; row++) {
    for (size_t col = 0; col < NUM_COLS; col++) {
      struct Char character = buffer[col + NUM_COLS * row];
      buffer[col + NUM_COLS * (row - 1)] = character;
    }
  }

  clear_row(NUM_ROWS - 1);
}