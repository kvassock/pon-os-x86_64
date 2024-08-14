# PonOS - операционная система

## Сборка

Для сборки понадобятся устаноить библеотеки:

`nasm`, `xorisso`, `grub-pc-bin`, `grub-common`.

### Nasm

```
sudo apt-get install nasm
```

### Xorriso

```
sudo apt-get install xorriso
```

### Grub-pc-Bin

```
sudo apt-get install grub-pc-bin
```

### Grub-common

```
sudo apt-get install grub-common
```

### Сборка

```
make build-x86_64
```

# Эмуляция

Чтобы эмулировать

Можете использовать любой виртуализатор, например qemu

```
sudo qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso
```
