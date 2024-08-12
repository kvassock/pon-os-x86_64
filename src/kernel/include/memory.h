#pragma once

#ifndef MEMORY_H
#define MEMORY_H
#include <stddef.h>
#include <stdbool.h>
#include <constants.h>

void memcpy(void *dest, void *src, size_t count);

void memset(void *dest, char value, size_t count);

void *malloc(size_t size);

void free(void* ptr);

void* realloc(void* ptr, size_t new_size);

#endif