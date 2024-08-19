#pragma once
#include <utils.h>
#include <vga.h>
#include <constants.h>
#include <common.h>
#include <keyboard.h>
#include <fs.h>
#include <nano.h>
#include <memory.h>
#include <acpi.h>

// Напечатать оболочку (ну типа сам поймешь че это)
void print_shell();

// Оболочка
void shell(void);

// Цикл оболочки
void shell_loop();