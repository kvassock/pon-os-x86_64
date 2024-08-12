// Бля ну это пиздец, она нужна только просто так, дизлайк

#include <common.h>
#include <vga.h>
#include <utils.h>

// Инициализировать
int init_fs();

// Получить все файлы
char* get_files();

// Получить файл
char* get_file(char* name);

// Создать файл
// 1 - файл создан
// 0 - файл уже существует
int create_file(char* name, char* content);

// Отредактировать файл
// 1 - файл отредактирова
// 0 - файла не существует
int edit_file(char* name, char* content);

// Удалить файл
// 1 - файл удалёен
// 0 - файла не существует
int delete_file(char* name);

// Существует ли файл
// 1 - файл существует
// 0 - файла не существует
int is_file_exists(char* name);