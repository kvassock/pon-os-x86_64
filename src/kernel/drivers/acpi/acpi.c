#include <acpi.h>

void shutdown() {
  outportb(0xB2, 0x00);
  outportb(0xCF9, 0x06);
}

void reboot() {
  outportb(0x64, 0xFE);
}