#pragma once

#include <utils.h>
#include <vga.h>
#include <memory.h>
#include <stdint.h>
#include <stddef.h>

// Соединение 2 строк
char* concat_str(char a[], char b[]);

// Число в строку
void num_to_str(int num, char str[]);

// Строку в число
int str_to_num(char str[]);

// Узнать длину строки
int strlen(char* string);

// Сравнение двух строк
int str_equal(char* string1, char* string2);

// Копирование строк
void strncpy(char* destination, char* source, size_t n);

// Копирование строк
char* strcpy(char* destination, const char* source);

// Проверка числа в строке
char* strchr(char* str, char ch);

// Scancode в символ
char* scancode_convert(uint8_t scancode);

// Символ в строку
char* char_to_str(char ch);

// Функция случайного числа
int rand(void);

// Дублирование строки
char* strdup(char* str);

// Разделить строку
int split(char *str, char delimiter, char ***result);

char* strtok(char* str, char* delimiter);