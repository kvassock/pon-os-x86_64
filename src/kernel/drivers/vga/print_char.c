#include <vga.h>

void print_char(char character) {
  // Если символ - перенос строки
  if (character == '\n') {
    print_newline();
    return;
  }

  // Если символ - backspace
  if (character == '\b') {
    print_back_space();
    return;
  }

  // Если символ - таб
  if (character == '\t') {
    print_tab();
    return;
  }

  buffer[col + NUM_COLS * row] = (struct Char) {
    character: (uint8_t) character,
    color: color,
  };

  col++;
  update_cursor();
}
