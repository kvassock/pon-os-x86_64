#include <vga.h>

void update_cursor() {
  uint16_t temp;

  temp = row * NUM_COLS + col;

  outportb(REG_SCREEN_CTRL, 14);
  outportb(REG_SCREEN_DATA, temp >> 8);
  outportb(REG_SCREEN_CTRL, 15);
  outportb(REG_SCREEN_DATA, temp & 0xFF);
}
