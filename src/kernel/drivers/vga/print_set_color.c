#include <vga.h>

void print_set_color(uint8_t foreground, uint8_t background) {
  color = foreground + (background << 4);
}
