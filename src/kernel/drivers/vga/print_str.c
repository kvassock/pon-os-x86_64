#include <vga.h>

void print_str(char* str) {
  for (size_t i = 0; 1; i++) {
    char character = (uint8_t) str[i];

    if (character == '\0') {
      return;
    }

    print_char(character);
  }
}

void print_str_light_blue(char* str) {
  print_set_color(LIGHT_BLUE, LIGHT_GREEN);
  print_str(str);
  print_set_color(WHITE, LIGHT_GREEN);
}
