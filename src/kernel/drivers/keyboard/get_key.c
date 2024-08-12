#include <keyboard.h>

// Получить клавишу клавиатуры
char* get_key() {
  
  while (1) {
    char* symbol = get_char();

    if (!str_equal(symbol, "NULL")) {
      return symbol;
    }
  }

}