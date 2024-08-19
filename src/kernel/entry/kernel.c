#include <vga.h> 
#include <utils.h> 
#include <common.h> 
#include <constants.h> 
#include <fs.h> 
#include <nano.h> 
#include <shell.h>
#include <idt.h>
#include <math.h>

void kernel_main() {
  print_clear();
  init_fs();
  vga_test();

  print_set_color(YELLOW, BLACK);
  printf("PonOS by kvassock \n\n");
  printf("Fake File System Init\n\n");

  // print_clear();
  // while(1) {
  //   char* t = get_char();
  // };
  // return;

  // char* test_file_content = "Hello world! This is example text.";
  // create_file("example.txt", test_file_content);
 
  shell_loop();
}
