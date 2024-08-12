#include <shell.h>


// Цикл терминала
void shell_loop() {
  while(1) {
    shell();
  }
}

// Создать файл
void touch(char* file_name) {

  // Валидация
  if (strlen(file_name) > 30 || str_equal(file_name, NULL_KEY)) {
    return print_str("\nFile name too long");
  }

  // Создаие
  int created_file_status = create_file(file_name, "\0");
}

// Прочитать файл
void cat(char* file_name) {
  char* file;
  file = get_file(file_name);

  print_str("\n");
  print_str(file);
}


// Напечатать строчку терминала
void print_shell() {
  print_str("\n");
  print_set_color(LIGHT_BLUE, BLACK);
  print_str(SHELL_NAME);
  print_set_color(WHITE, BLACK);
}

void print_text_help_main() {
  print_set_color(MAGENTA, BLACK);
  print_str("\nMain:\n");
  print_set_color(WHITE, BLACK);
  print_str("help - help\n");
  print_str("help-fs - file system commands\n");
  print_str("help-soon - feature commands\n");
  print_str("help-other - other commands\n");
  print_str("clear - clear the screen\n");
}

void print_text_help_fs() {
  print_set_color(MAGENTA, BLACK);
  print_str("\nFile System:\n");
  print_set_color(WHITE, BLACK);
  print_str("ls - list files\n");
  print_str("touch - create file\n");
  print_str("nano - edit file\n");
}

void print_text_help_soon() {
  print_set_color(MAGENTA, BLACK);
  print_str("\nSoon:\n");
  print_set_color(WHITE, BLACK);
  print_str("rm - remove file\n");
  print_str("shutdown - shutdown pc\n");
}

void print_text_help_other() {
  print_set_color(MAGENTA, BLACK);
  print_str("\nOther:\n");
  print_set_color(WHITE, BLACK);
  print_str("ping - pong\n");
  print_str("ru - russian flag\n");
}
    
// Команда для вывода российского флага 
void command_ru() {
  print_clear();
  fill(BLACK);
  int y = NUM_ROWS;
  int x = NUM_COLS;

  vga_rect(3, 3, x-3, 6 , WHITE);
  vga_rect(3, 6, x-3, 9, BLUE);
  vga_rect(3, 9, x-3, 12, RED);
  row = row+12;
  print_str("\n   Flag ru\n");
}


// Команда для очистки экрана
void command_clear() {
  print_clear();
}

// Команда пинг
void command_ping() {
  print_str("pong!");
}

// Команда помощи
void command_help(int type) {
  print_str("\nThis is the Pon Operating System (PonOS) created by kvassock.\n\n");
  print_set_color(RED, BLACK);
  print_str("Commands:\n");

  if (type == 0) {
    print_text_help_main();
  }

  if (type == 1) {
    print_text_help_fs();
  }

  if (type == 2) {
    print_text_help_other();
  }

  if (type == 3) {
    print_text_help_soon();
  }
}

void command_shutdown() {
  print_str("Skoro (Soon)");
}

void command_touch(char* command) {
  print_str("Enter file name: ");
  char* file_name = input();
  touch(file_name);
  free(file_name);
}

void command_cat(char* command) {
  print_str("Enter file name: ");
  char* file_name = input();
  cat(file_name);
  free(file_name);
}

void command_nano(char* command) {
  print_str("Enter file name: ");
  char* file_name = input();
  nano(file_name);
  free(file_name);
}

void command_ls() {
  char* files = get_files();
  print_str(files);
}

void command_handler(char* command) {

  if (str_equal(command, NULL_KEY)) {
    return;
  }

  else if (str_equal(command, "help")) {
    command_help(0);
  } 

  else if (str_equal(command, "help-fs")) {
    command_help(1);
  } 

  else if (str_equal(command, "help-other")) {
    command_help(2);
  } 

  else if (str_equal(command, "help-soon")) {
    command_help(3);
  } 

  else if (str_equal(command, "shutdown")) {
    command_shutdown();
  }

  else if (str_equal(command, "clear")) {
    command_clear();
  } 
  
  else if (str_equal(command, "ping")) {
    command_ping();
  } 
  
  else if (str_equal(command, "ru")) {
    command_ru();
  } 
  
  else if (str_equal(command, "touch")) {
    command_touch(command);
  }

  else if (str_equal(command, "nano")) {
    command_nano(command);
  }

  else if (str_equal(command, "cat")) {
    command_cat(command);
  }

  else if (str_equal(command, "ls")) {
    command_ls();
  }
    
  else {
    print_str("command '");
    print_str(command);
    print_str("' ");
    print_str("not found!");
  }
}

// Терминал
void shell() {
  print_shell();  
  print_set_color(GREEN, BLACK);
  char* command = input();
  print_set_color(WHITE, BLACK);

  if (!str_equal(command, NULL_KEY)) {
    print_str("\n");
    command_handler(command);
  }
}






