#include <fs.h>

// Получить все файлы
char* get_files() {
  char* result = "Files: \n";
  int index_file = 0;

  for (int i = 0; i <= 50; i += 2) {
    if (!str_equal(char_to_str(file_system[i][0]), "\0")) {
      char* index_str = "0";
      num_to_str(index_file, index_str);

      result = concat_str(result, "File ");
      result = concat_str(result, index_str);
      result = concat_str(result, ": ");
      result = concat_str(result, file_system[i]);
      result = concat_str(result, "\n");
      
      index_file++;
    }
  }

  return result;
}