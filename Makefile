kernel_source_files := $(shell find src/kernel -name *.c)
kernel_object_files := $(patsubst src/kernel/%.c, build/kernel/%.o, $(kernel_source_files))

boot_asm_source_files := $(shell find src/boot -name *.asm)
boot_asm_object_files := $(patsubst src/boot/%.asm, build/boot/%.o, $(boot_asm_source_files))

$(kernel_object_files): build/kernel/%.o : src/kernel/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -Werror -c -I src/kernel/include -ffreestanding $(patsubst build/kernel/%.o, src/kernel/%.c, $@) -o $@
	
$(boot_asm_object_files): build/boot/%.o : src/boot/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/boot/%.o, src/boot/%.asm, $@) -o $@

.PHONY: build-x86_64
build-x86_64: $(boot_asm_object_files) $(kernel_object_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld  -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(kernel_object_files) $(boot_asm_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso 

.PHONY: clean
clean:
	rm -rf build/
	rm -rf dist/
	rm -f targets/x86_64/iso/boot/kernel.bin