#include <vga.h>

void print_int(int num) {
  char num_str[12];
  num_to_str(num, num_str);

  print_str(num_str);
}
