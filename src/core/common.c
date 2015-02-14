/************************************************************
 * Raunix Operating System
 * 
 * File: kernel/common.c
 * 
 * Description:
 * 	Functions used to control the manipulation I/O registers
 * 
 ************************************************************/

#include <sys/common.h>

/** Low-level I/O Handling functions **/

// Sends a 8/16/32-bit value on a I/O location
void outb(u16int port, u8int val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

// Receives a 8/16/32-bit value from an I/O location.
u8int inb(u16int port)
{
    u8int ret;
    asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

// Receives a 8/16/32-bit value from an I/O location.
u16int inw(u16int port)
{
   u16int ret;
   asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
} 

void io_wait(void)
{
    /* Port 0x80 is used for 'checkpoints' during POST. */
    /* The Linux kernel seems to think it is free for use :-/ */
    asm volatile ( "outb %%al, $0x80" : : "a"(0) );
}

void * memset ( void * ptr, int value, size_t num )
{
	u16int *dest = ptr;
	while(num-- !=0) *dest++ = value;	 	
	return ptr;
}

void *memcpy(void *dest, const void *src, size_t n)
{
	u16int *local_dest = dest;
	const u16int *local_src = src;
	while(n-- !=0)	*local_dest++ = *local_src++;
	return dest;
}
