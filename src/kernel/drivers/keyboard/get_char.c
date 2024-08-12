#include <keyboard.h>
#include <vga.h>

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
