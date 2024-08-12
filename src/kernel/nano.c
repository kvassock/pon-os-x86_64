// Тут короче есть некоторые проблемки, но мне лень их решать
#include <vga.h>
#include <common.h>
#include <utils.h>
#include <keyboard.h>
#include <fs.h>

#define BACKGROUND_MAIN BLACK

int nano(char* file_name) {

  // Header
  void print_header() {
    vga_rect(0, 0, NUM_COLS, 1, WHITE);
    print_set_color(BLACK, WHITE);

    char* header_text_app = "PON NANO";

    for (int i = 0; i < strlen(header_text_app); i++) {
      print_symbol_with_char(i+1, 0, header_text_app[i]);
    }

    char* header_text_file = file_name;

    for (int i = 0; i < strlen(header_text_file); i++) {
      print_symbol_with_char((NUM_COLS-strlen(header_text_file))/2+i, 0, header_text_file[i]);
    }
  }

  // Footer
  void print_footer() {
    vga_rect(0, NUM_ROWS-1, NUM_COLS, NUM_ROWS, WHITE);
    print_set_color(BLACK, WHITE);

    char* footer_text = "Ctrl + Q: Exit  |  Ctrl + O: Save";

    for (int i = 0; i < strlen(footer_text); i++) {
      print_symbol_with_char((NUM_COLS-strlen(footer_text))/2+i, NUM_ROWS-1, footer_text[i]);
    }

  }

  if (is_file_exists(file_name) == 0) {
    print_str("\nNo such file or directory");
    return 0;
  }

  // Main
  print_clear();
  print_header();
  print_footer();
  vga_rect(0, 1, NUM_COLS, NUM_ROWS-1, BACKGROUND_MAIN);

  char* file_old_content = get_file(file_name);
  char* buffer_nano_text = file_old_content;
  free(file_old_content);
  int buffer_nano_index = strlen(buffer_nano_text);

  col = 0;
  row = 1;
  print_set_color(WHITE, BLACK);

  for (int i = 0; i < buffer_nano_index; i++) {
    print_char(buffer_nano_text[i]);
  }

  col = strlen(buffer_nano_text);
  update_cursor();

  while(1) {
    char* key = get_key();

    // Горячие клавиши
    if (str_equal(key, "CTRL")) {
      char* key_ctrl = get_key();

      if (str_equal(key_ctrl, "q")) {
        print_set_color(WHITE, BLACK);
        print_clear();
        free(buffer_nano_text);
        return 0;
      }

      if (str_equal(key_ctrl, "o") || str_equal(key_ctrl, "s")) {
        print_set_color(WHITE, BLACK);
        print_clear();
        edit_file(file_name, buffer_nano_text);
        free(buffer_nano_text);
        return 1;
      }
    }

    // Перенос строки
    if (str_equal(key, "ENTER")) {
      print_set_color(WHITE, BACKGROUND_MAIN);
      print_char('\n');
      buffer_nano_text[buffer_nano_index] = '\n';
      buffer_nano_index++;
    }

    if (strlen(key) < 2) {

      // Стереть символ
      if (str_equal(key, "\b")) {

        if (buffer_nano_index != 0) {
          print_char('\b');
          buffer_nano_text[buffer_nano_index] = '\0';
          buffer_nano_index--;
        }
      }

      else {
        print_set_color(WHITE, BACKGROUND_MAIN);
        print_char(key[0]);
        buffer_nano_text[buffer_nano_index] = key[0];
        buffer_nano_index++;
      }
    }
  free(buffer_nano_text);

    update_cursor();
  }

  free(buffer_nano_text);
  return 0;
}