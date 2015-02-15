/************************************************************
 * Raunix Operating System
 * 
 * File: include/sys/vga.h
 * 
 * Description:
 * 	Defines VGA screen buffer, memory locations, and other
 * 	VGA screen related constants.
 * 
 ************************************************************/

#ifndef VGA_H
#define VGA_H

#include <sys/common.h>

	/* Value	Color	*/
enum {
	 VGA_BLACK 		= 0,
	 VGA_BLUE 		= 1,
	 VGA_GREEN		= 2,
	 VGA_CYAN		= 3,
	 VGA_RED 		= 4,	
	 VGA_MAGENTA 		= 5,	
	 VGA_BROWN 		= 6,	
	 VGA_LIGHT_GREY 	= 7,
	 VGA_DARK_GREY 		= 8,
	 VGA_LIGHT_BLUE 	= 9,
	 VGA_LIGHT_GREEN 	= 10,
	 VGA_LIGHT_CYAN 	= 11,
	 VGA_LIGHT_RED 		= 12,
	 VGA_LIGHT_MAGENTA 	= 13,
	 VGA_LIGHT_BROWN 	= 14,
	 VGA_WHITE 		= 15
};

/** Function Declerations **/

// Write a single character out to the screen.
void vga_put(char c);

// Clear the screen to all black.
void vga_clear();

// Output a null-terminated ASCII string to the vga.
void vga_write(char *c);

//Following texts will use the new color set
void vga_setColor(u32int fgColor , u32int bgColor);

//vga driver init
void vga_init();
#endif // VGA_H
