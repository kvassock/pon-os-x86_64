#include <constants.h>
#include <common.h>
#include <idt.h>
#include <vga.h>
#include <ports.h>
#include <utils.h>

#pragma once

#ifndef KEYBOARD_H
#define KEYBOARD_H

// Получить нажатие клавишы
char* get_char(void);

// Получить нажатие клавишы
char* get_key(void);

// Получить клавишу клавиатуры
char getch(void);

// Получить символ с клавиатуры
char* input(void);

// Очистка буфера
void key_buffer_clear();

#endif