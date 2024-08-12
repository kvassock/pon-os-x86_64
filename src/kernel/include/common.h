#pragma once

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>

extern uint32_t one;
extern uint32_t zero;

extern size_t col;
extern size_t row;

extern char* SHELL_NAME;

extern char* key_buffer;
extern int key_buffer_index;

extern char file_system[50][50];

extern int shell_active;

extern uint8_t color;

extern struct Char* buffer;

extern uint8_t* screen;

#endif