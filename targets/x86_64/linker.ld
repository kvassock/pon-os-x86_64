ENTRY(start)

SECTIONS
{
    . = 1M;

    .boot : ALIGN(4K)
    {
        /* multiboot header is the first thing to boot up*/
        KEEP(*(.multiboot_header))
    }

    .text : ALIGN(4K)
    {
        /* Then the text main section */
        *(.text)
    }

   .rodata : ALIGN(4K)
    {
        /* Then the read only data section */
        *(.rodata)
    }

    .data : ALIGN(4K)
    {
        /* Then the data main section */
        *(.data)
    }

    .bss : ALIGN(4K)
    {
        /* Then start of the bss stack section */
        __bss_start = .;
        
        /* Include common symbols */
        *(COMMON)
        
        /* Include the standard .bss section */
        *(.bss)
        
        /* End of the bss stack section */
        bss_end = .;
    }

    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
        IDT = .;
        . = . + 0x1000;
    }
}