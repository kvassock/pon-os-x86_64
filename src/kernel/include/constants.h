#pragma once

#ifndef CONSTANTS_H
#define CONTSTANTS_H

#define IDT_SIZE 256
#define MAX_SIZE 30

#define KEYBOARD_DATA_PORT 0x60                   /* IO Ports for Keyboard */
#define KEYBOARD_STATUS_PORT 0x64

#define MASK_ALL_INTS 0xFF                        /* Mask all interupts in PIC */

#define PIC_MASTER_CMD 0x20                       /* IO base address for master PIC */
#define PIC_MASTER_DATA 0x21    

#define PIC_SLAVE_CMD 0xA0                        /* IO base address for slave PIC */
#define PIC_SLAVE_DATA 0xA1

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

#define INTERRUPT_GATE 0x8E                       
#define KERNEL_CODE_SEGMENT_OFFSET 0x08            /* CS address */

#define VGA_MAX_WIDTH 80
#define VGA_MAX_HEIGHT 25

#define ICW1_ICW4_INIT 0x11		                     /* Indicates that ICW4 will be present */
                                                   /* Initialization - ired! */
#define ICW1_SINGLE	0x02		                       /* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		                   /* Call address interval 4 (8) */
#define ICW1_LEVEL	0x08		                       /* Level triggered (edge) mode */

#define ICW4_8086	0x01		                         /* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		                         /* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		                   /* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		                   /* Buffered mode/master */
#define ICW4_SFNM	0x10		                         /* Special fully nested (not) */

#define PIC_EOI		0x20		                         /* End-of-interrupt command code */
#define KEYBOARD_IRQ 1                             /* Standard ISA Interupt est 1 - Keyboard Interupt*/

#define MEMORY_POOL_SIZE 1024

#define true 1
#define false 0

#define NULL_KEY "NULL_KEY_020394"


#endif