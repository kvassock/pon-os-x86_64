#pragma once

#ifndef PORTS_H
#define PORTS_H
#include <stdint.h>

uint8_t inportb(uint16_t _port);

void outportb(uint16_t _port, uint8_t _data);

void outportw(uint16_t port, uint16_t value);

#endif