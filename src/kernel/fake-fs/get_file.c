#include <fs.h>

// Получить файл
char* get_file(char* name) {
  char* result = " ";

  for (int i = 0; i <= 50; i += 2) {
    if (!str_equal(file_system[i], "\0")) {
      for (int j = 0; j < strlen(file_system[i+1]); j++) {
        result[j] = file_system[i+1][j];
      }
    }
  }

  return result;
}