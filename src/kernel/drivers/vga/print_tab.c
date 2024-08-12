#include <vga.h>

void print_tab() {
  col += TAB_SIZE;
  update_cursor();
}
