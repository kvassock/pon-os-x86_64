#pragma once

#include <stdint.h>
#include <stddef.h>
#include <ports.h>
#include <constants.h>
#include <common.h>
#include <vga.h>
#include <keyboard.h>
#include <utils.h>
#include <shell.h>
#include <stdarg.h>

struct Char {
  uint8_t character;
  uint8_t color;
};

enum {
  BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15,
};

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;
const static size_t TAB_SIZE = 1;

void print_clear();
void clear_row(size_t row);
void print_char(char character);
void print_str(char* string);
void print_set_color(uint8_t foreground, uint8_t background);
void print_int(int num);
void print_backspace();
void print_tab();
void print_newline();
void update_cursor();
void print_fill(int color_fill);
void print_rect(int left, int top, int right, int bottom, int color);
void set_buffer(struct Char* new_buffer);
void print_symbol(int x, int y, char symbol);
void vga_test();

void printf(const char *format, ...);

