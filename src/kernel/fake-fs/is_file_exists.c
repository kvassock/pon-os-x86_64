#include <fs.h>

// Проверка на существование
int is_file_exists(char* name) {
  for (int i = 0; i <= 50; i += 2) {
    if (str_equal(file_system[i], name)) {
      return 1;
    }
  }

  return 0;
}