#include <vga.h>

void print_symbol(int x, int y, int color) {
  buffer[x + NUM_COLS * y] = (struct Char) {
    character: ' ',
    color: WHITE + (color << 4)
  };
}

void print_symbol_with_char(int x, int y, char symbol) {
  buffer[x + NUM_COLS * y] = (struct Char) {
    character: symbol,
    color: color
  };
}
