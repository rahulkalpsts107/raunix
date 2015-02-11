/*************/
  Raunix -OS
/*************/

This repository consists source code of Raunix Operating System
Raunix Operating System is written to be compatible with Unix hence the name.
Raunix is only for educational purpose only to demonstrate a unix like OS.

All code in this repository is subject to the terms in the
LICENSE document.

Raunix will be completely documented over the course of development in /doc folder

Raunix is built over BasicOS and all credit goes to Aun-Ali Zaidi to help startup and build on this.
Follow here : https://github.com/aunali1/BasicOS

Raunix is compiled for x86 processor and will be tested under Bochs Emulator.
Different ports are welcome to add their patches without bricking any existing code.

IMP!! Before Building make sure these utilities are present
* GNU MAKE
* binutils
* GNU GMP
* GNU MPFR
* GNU MPC


Raunix will start its descent into the memory banks once its primary features are implemented

* Paging
* GDT Initialization
* VGA setup 
* Serial Port Initialization
* A Simple Command Interpreter with Unix Style commands.

Dirent Structure :

+	src		/*Source Code*/
+	include		/*C/C++ Includes*/
+	out		/*Build output*/
+	scripts		/*Scripts for isoimage creation*/
+	doc		/*documentation*/
