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
    return printf("\nFile name too long");
  }

  // Создаие
  int created_file_status = create_file(file_name, "\0");
}

// Прочитать файл
void cat(char* file_name) {
  char* file;
  file = get_file(file_name);

  printf("\n%s", file);
}


// Напечатать строчку терминала
void print_shell() {
  print_set_color(LIGHT_BLUE, BLACK);
  printf("\n%s", SHELL_NAME);
  print_set_color(WHITE, BLACK);
}

void print_text_help_main() {
  print_set_color(MAGENTA, BLACK);
  printf("\nMain:\n");
  print_set_color(WHITE, BLACK);
  printf("help - help\n");
  printf("help-fs - file system commands\n");
  printf("help-soon - feature commands\n");
  printf("help-other - other commands\n");
  printf("clear - clear the screen\n");
}

void print_text_help_fs() {
  print_set_color(MAGENTA, BLACK);
  printf("\nFile System:\n");
  print_set_color(WHITE, BLACK);
  printf("ls - list files\n");
  printf("touch - create file\n");
  printf("nano - edit file\n");
}

void print_text_help_soon() {
  print_set_color(MAGENTA, BLACK);
  printf("\nSoon:\n");
  print_set_color(WHITE, BLACK);
  printf("rm - remove file\n");
  printf("shutdown - shutdown pc\n");
}

void print_text_help_other() {
  print_set_color(MAGENTA, BLACK);
  printf("\nOther:\n");
  print_set_color(WHITE, BLACK);
  printf("ping - pong\n");
  printf("ru - russian flag\n");
}
    
// Команда для вывода российского флага 
void command_ru() {
  print_clear();
  print_fill(BLACK);
  int y = NUM_ROWS;
  int x = NUM_COLS;

  print_rect(3, 3, x-3, 6 , WHITE);
  print_rect(3, 6, x-3, 9, BLUE);
  print_rect(3, 9, x-3, 12, RED);
  row = row+12;
  printf("\n   Flag ru\n");
}


// Команда для очистки экрана
void command_clear() {
  print_clear();
}

// Команда пинг
void command_ping() {
  printf("pong!");
}

// Команда помощи
void command_help(int type) {
  printf("\nThis is the Pon Operating System (PonOS) created by kvassock.\n\n");
  print_set_color(RED, BLACK);
  printf("Commands:\n");

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
  shutdown();
}

void command_touch(char* command) {
  printf("Enter file name: ");
  char* file_name = input();
  touch(file_name);
  free(file_name);
}

void command_cat(char* command) {
  printf("Enter file name: ");
  char* file_name = input();
  cat(file_name);
  free(file_name);
}

void command_nano(char* command) {
  printf("Enter file name: ");
  char* file_name = input();
  nano(file_name);
  free(file_name);
}

void command_ls() {
  char* files = get_files();
  printf("%s", files);
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
    printf("command '%s' not found", command);
  }
}

// Терминал
void shell() {
  print_shell();  
  print_set_color(GREEN, BLACK);
  char* command = input();
  print_set_color(WHITE, BLACK);

  if (!str_equal(command, NULL_KEY)) {
    printf("\n");
    command_handler(command);
  }
}






