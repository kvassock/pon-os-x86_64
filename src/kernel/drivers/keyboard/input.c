#include <keyboard.h>

// Полуить введённую пользователем строку
char* input() {

  key_buffer_clear();

  while(1) {

    // Введено больше 50 символов
    if (key_buffer_index >= 50) {
      return key_buffer;
    }
    
    char* symbol = get_char();

    // Нажата клавиша backspace
    if (str_equal(symbol, "\b")) {

      if (key_buffer_index != 0) {
        key_buffer[key_buffer_index-1] = '\0';
        key_buffer_index--;      
        print_char(symbol[0]);
      }
      
    } else

    // Нажата клавиша enter
    if (str_equal(symbol, "ENTER")) {

      if (key_buffer_index == 0) {
        return NULL_KEY;
      }

      return key_buffer;

    } else

    // Если клавиша это допустимый символ, то добавляем значение в буффер
    if (strlen(symbol) < 2) {
      key_buffer[key_buffer_index] = symbol[0];
      print_char(symbol[0]);
      key_buffer_index++;
    } 

  }

}

