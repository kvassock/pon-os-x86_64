#include <keyboard.h>

// Очистка буффера нажатых символов
void key_buffer_clear() {
  for (int j = 0; j < 250; j++) {
    key_buffer[j] = '\0';
  }

  key_buffer_index = 0;
}
