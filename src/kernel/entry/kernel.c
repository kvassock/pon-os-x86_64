#include <vga.h> 
#include <utils.h> 
#include <common.h> 
#include <constants.h> 
#include <fs.h> 
#include <nano.h> 
#include <shell.h>
#include <idt.h>

void kernel_main() {
  // idt_init(); 
  init_fs();
  // vga_test();
  // return;

  print_clear();
  print_set_color(YELLOW, BLACK);
  print_str("PonOS by kvassock \n");
  print_str("\n");
  print_str("Fake File System Init\n");
  print_str("\n");

  // print_clear();
  // while(1) {
  //   char* t = get_char();
  // };
  // return;

  // char* test_file_content = "Hello world! This is example text.";
  // create_file("example.txt", test_file_content);
 
  shell_loop();
}
