##################################
#	Raunix Kernel Makefile
##################################

CC=../cross/os-toolchain/bin/i686-elf-gcc
AS=nasm

INCLUDE=../include/
CFLAGS=-std=gnu99 -I$(INCLUDE) -ffreestanding -nostdlib -O2 -Wall -Wextra
ASFLAGS=-felf
LDFLAGS=-T core/linker.ld

CSOURCES= ./core/common.c ./core/driver/vga.c ./core/gdt.c ./core/page.c ./core/kernel.c
ASMSOURCES= ./core/boot.s
OBJDIR=../out/

COBJECTS=$(CSOURCES:.c=.o)
ASMOBJECTS=$(ASMSOURCES:.s=.o)

KERNEL=$(OBJDIR)raunix.bin

all: $(CSOURCES) $(ASMSOURCES) $(KERNEL)

$(KERNEL): $(COBJECTS) $(ASMOBJECTS)
	$(CC) $(LDFLAGS) $(CFLAGS) $(COBJECTS) $(ASMOBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.s.o:
	$(AS) $(ASFLAGS)  $< -o $@

clean:
	rm -f $(COBJECTS) $(ASMOBJECTS) $(KERNEL) ../out/raunix.iso ../out/raunix.bin ../out/bochsout.txt

