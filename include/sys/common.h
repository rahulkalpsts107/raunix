/************************************************************
 * Raunix Operating System
 * 
 * File: include/sys/common.h
 * 
 * Description:
 * 	Defines common data types and I/O manipulation function 
 * 	prototypes.
 * 
 ************************************************************/

#ifndef COMMON_H
#define COMMON_H

// Common 32-bit x86 Data types

typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;
typedef unsigned int   size_t;

// Essential Low-level I/O Control Functions

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);
void io_wait(void);

//Utilities
void *memcpy(void *dest, const void *src, size_t n);
void *memset ( void * ptr, int value, size_t num );
#endif // COMMON_H
