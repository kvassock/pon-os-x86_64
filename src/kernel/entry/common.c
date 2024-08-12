#include <common.h>
#include <vga.h>

uint32_t one = 1;
uint32_t zero = 0;

size_t col = 0;
size_t row = 0;

char* SHELL_NAME = ">> ";

char* key_buffer = {0};
int key_buffer_index = 0;

char file_system[50][50];

int shell_active = 1;

uint8_t color = WHITE | BLACK << 4;

struct Char* buffer = (struct Char*) 0xb8000;
uint8_t* screen = (uint8_t*) 0xA0000;




