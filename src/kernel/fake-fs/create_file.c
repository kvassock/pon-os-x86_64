#include <fs.h>

// Создать файл
// 1 - файл создан
// 0 - файл уже существует
int create_file(char* name, char* content) {
  for (int i = 0; i <= 50; i += 2) {

    if (str_equal(file_system[i], name)) {
      return 0;
    }

    // Если ячейка не занята
    if (str_equal(file_system[i], "\0")) {

      // Заполняем имя
      for (int j = 0; j < strlen(name); j++) {
        file_system[i][j] = name[j];
      }

      // Заполняем содержимое
      for (int j = 0; j < strlen(content); j++) {
        file_system[i+1][j] = content[j];
      }

      return 1;
    }
  }
}