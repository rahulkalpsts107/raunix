##################################
#	Raunix Top-Level Makefile
##################################

help:
	@echo "Makefile for Raunix Operating System."
	@echo "Usage: make [ all | clean | distclean | help ] " 
	@echo "For toolchain specify make toolchain ARCH = x86"
	@echo

all:
	@echo "Building Kernel!"
	make -C ./src all

clean:
	make -C ./src clean

distclean:
	rm -rf cross/
	make -C ./src clean

toolchain:
	./scripts/arch_$(ARCH)/build_toolchain.sh

isoimage:
	./scripts/build_iso_image.sh
