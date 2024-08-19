#include <keyboard.h>

// Очистка буффера нажатых символов
void key_buffer_clear() {
  for (int j = 0; j < 250; j++) {
    key_buffer[j] = '\0';
  }

  key_buffer_index = 0;
}


// Получить клавишу клавиатуры
char* get_key() {
  
  while (1) {
    char* symbol = get_char();

    if (!str_equal(symbol, "NULL")) {
      return symbol;
    }
  }

}

// Получить нажатие клавишы
char* get_char() {
  uint8_t status = inportb(KEYBOARD_STATUS_PORT);

  if (status & 0x1) {
    uint8_t scancode = inportb(KEYBOARD_DATA_PORT);

    char* symbol = scancode_convert(scancode);

    return symbol;
  }
  outportb(PIC_MASTER_CMD, PIC_EOI);

  return "NULL";  
}
