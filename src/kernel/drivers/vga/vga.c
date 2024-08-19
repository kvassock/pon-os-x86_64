#include <vga.h>

// Очистить ряд
void clear_row(size_t row) {
  struct Char empty = (struct Char) {
    character: ' ',
    color: color
  };

  for (size_t col = 0; col < NUM_COLS; col++) {
    buffer[col + NUM_COLS * row] = empty;
  }

  update_cursor();
}

// Очистить всё
void print_clear() {
  for (size_t i = 0; i < NUM_ROWS; i++) {
    clear_row(i);
  }
  row = 0;
  col = 0;
  update_cursor();
}

// Изменить цвет вывода 
void print_set_color(uint8_t foreground, uint8_t background) {
  color = foreground + (background << 4);
}

// Напечатать символ
void print_char(char character) {
  // Если символ - перенос строки
  if (character == '\n') {
    print_newline();
    return;
  }

  // Если символ - backspace
  if (character == '\b') {
    print_backspace();
    return;
  }

  // Если символ - таб
  if (character == '\t') {
    print_tab();
    return;
  }

  buffer[col + NUM_COLS * row] = (struct Char) {
    character: (uint8_t) character,
    color: color,
  };

  col++;
  update_cursor();
}

// Напечатать строку
void print_str(char* str) {
  for (size_t i = 0; 1; i++) {
    char character = (uint8_t) str[i];

    if (character == '\0') {
      return;
    }

    print_char(character);
  }
}

// Напечатать число
void print_int(int num) {
  char num_str[12];
  num_to_str(num, num_str);

  printf(num_str);
}

// Напечатать таб
void print_tab() {
  col += TAB_SIZE;
  update_cursor();
}

// Напечатать backspace
void print_backspace() {
  col--;
  struct Char empty = {
      .character = ' ',
      .color = color,
  };
  buffer[col + NUM_COLS * row] = empty;
  update_cursor();
}

// Напечатать новую строку
void print_newline() {
  col = 0;

  if (row < NUM_ROWS - 1) {
    row++;
    return;
  }

  for (size_t row = 1; row < NUM_ROWS; row++) {
    for (size_t col = 0; col < NUM_COLS; col++) {
      struct Char character = buffer[col + NUM_COLS * row];
      buffer[col + NUM_COLS * (row - 1)] = character;
    }
  }

  clear_row(NUM_ROWS - 1);
}

// Напечатать символ  
void print_symbol(int x, int y, char symbol) {
  buffer[x + NUM_COLS * y] = (struct Char) {
    character: symbol,
    color: color
  };
}

void vga_test() {
    
}
