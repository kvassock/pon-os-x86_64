#include <vga.h>

// Прямоугольник
void vga_rect(int left, int top, int right, int bottom, int color) {
  for (size_t col = left; col < right; col++) {
    for (size_t row = top; row < bottom; row++) {
      buffer[col + NUM_COLS * row] = (struct Char) {
        character: ' ',
        color: WHITE + (color << 4)
      };
    }
  }
}

// Заполненный
void fill(int color_fill) {
  for (size_t i = 0; i < NUM_ROWS; i++) {
    struct Char element = (struct Char) {
      character: ' ',
      color: WHITE + (color_fill << 4)
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
      buffer[col + NUM_COLS * i] = element;
    } 
  }
}
