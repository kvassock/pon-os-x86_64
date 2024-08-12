#include <ports.h>

uint8_t inportb(uint16_t _port) {
  uint8_t result;
  asm volatile("inb %1, %0" : "=a" (result) : "dN" (_port));
  return result;
}

void outportb(uint16_t _port, uint8_t _data) {
  asm volatile("outb %0, %1" : : "a" (_data), "dN" (_port));
}

void outportw(uint16_t port, uint16_t value) {
  asm volatile("outw %0, %1" : : "a"(value), "Nd"(port));
}
