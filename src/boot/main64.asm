global long_mode_start

section .text
bits 64

extern kernel_main
extern IDT
extern shell


idt_common_handler:
  push rax
  push rcx
  push rdx
  push r8
  push r9
  push r10
  push r11
  pushfq

  call shell   ; IRQ1 handler

  popfq
  pop r11
  pop r10
  pop r9
  pop r8
  pop rdx
  pop rcx
  pop rax

  ret
  
irq1:
  call idt_common_handler
  iretq
  GLOBAL irq1

idt_descriptor:
  dw 4095
  dq IDT
  
load_IDT:
  lidt [idt_descriptor]    ; Загрузка IDTR
  sti
  ret
  GLOBAL load_IDT


long_mode_start:
  mov ax, 0        
  mov ss, ax      
  mov ds, ax 
  mov es, ax          
  mov fs, ax          
  mov gs, ax 
  
  ; Главное
  call kernel_main
  
  hlt
