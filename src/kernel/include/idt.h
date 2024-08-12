#pragma once

#ifndef IDT_H
#define IDT_H
#include <stdint.h>

struct IDT_entry {
  uint16_t offset_low;     // Lower 16 bits of the interrupt handler function
  uint16_t selector;       // Code segment selector
  uint8_t ist;             // Interrupt Stack Table (only used on x86_64)
  uint8_t type_attr;       // Type and attributes
  uint16_t offset_mid;     // Middle 16 bits of the interrupt handler function
  uint32_t offset_high;    // Upper 32 bits of the interrupt handler function
  uint32_t zero;           // Reserved, set to zero
};

void idt_init(void);
void remapPIC(void);

#endif