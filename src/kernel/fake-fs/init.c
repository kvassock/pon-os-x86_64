#include <fs.h>

// Инициализировать
int init_fs() { 
  for (int i = 0; i <= 50; i++) {
    for (int j = 0; j <= 50; j++) {
      file_system[i][j] = '\0';
    }
  }
  
  return 1;
}