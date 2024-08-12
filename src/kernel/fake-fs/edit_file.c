#include <fs.h>

// Отредактировать файл
// 1 - файл отредактирова
// 0 - файла не существует
int edit_file(char* name, char* content) {
  for (int i = 0; i <= 50; i += 2) {

    // Если ячейка найдена
    if (str_equal(file_system[i], name)) {

      // Заполняем содержимое
      for (int j = 0; j < strlen(content); j++) {
        file_system[i+1][j] = content[j];
      }

      return 1;
    }
  }
};
