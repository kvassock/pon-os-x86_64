#include <irq.h>
#include <constants.h>
#include <ports.h>

void set_mask_IRQ() {
  uint16_t port;
  unsigned char IRQline = KEYBOARD_IRQ;
  uint8_t value;

  if (IRQline < 8) {
    port = PIC_MASTER_DATA;
  } else {
    port = PIC_SLAVE_DATA;
    IRQline -= 8;
  }
  
  value = inportb(port) | (1 << IRQline);
  outportb(port, value);        
}