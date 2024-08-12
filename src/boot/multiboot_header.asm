section .multiboot_header
header_start:
    ;magic number 
    dd 0xe85250d6

    dd 0    ;0 = 32-bit protected mode of i386 cpu
            ;4 = 32-bit MIPS64

    dd header_end - header_start

    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))  

    dw 0    ; type
    dw 0    ; flags
    dd 8    ; size
    
header_end: