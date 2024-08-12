#include <keyboard.h>

// Получить символ с клавиатуры
char getch() {
  while (1) {
    char* symbol = get_char();

    if (strlen(symbol) < 2) {
      return symbol[0];
    }
  }

}
