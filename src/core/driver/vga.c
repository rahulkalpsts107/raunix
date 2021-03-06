 /* Raunix Operating System
 * 
 * File: kernel/vga.c
 * 
 * Description:
 * 	Functions used to control ASCII-text on a VGA Display.
 * 
 ************************************************************/

#include <sys/vga.h>

// Color organization in VGA upper 8 byte -> character , color scheme 4 byte (2^4) = 16colors 

/* [15**12	11**8	    7******0]
   Backcolor	Forecolor   Character */

//Define colors 
//TODO: Linking error , need to resolve and add it in header file

// VGA Framebuffer
u16int *video_memory ;

// Character Cursor Position Variables
u8int cursor_x = 0;
u8int cursor_y = 0;

//Background and foreground attributes
u32int bg_color ;
u32int fg_color ;

// Updates the hardware cursor.
static void move_cursor()
{
    // The screen is 80 characters wide...
    u16int cursorLocation = cursor_y * 80 + cursor_x; //equation y*width + x
    outb(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
    outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
    outb(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
    outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

// Scrolls the text on the screen up by one line.
static void scroll()
{

    // Get a space character with the default colour attributes.

    u8int attributeByte = (bg_color << 4) | (fg_color & 0x0F);
    u16int blank = 0x20 /* space */ | (attributeByte << 8);

    // Row 25 is the end, this means we need to scroll up
    if(cursor_y >= 25)
    {
        // Move the current text chunk that makes up the screen
        // back in the buffer by a line

        int i;
        for (i = 0*80; i < 24*80; i++)
        {
            video_memory[i] = video_memory[i+80];
        }

        // The last line should now be blank. Do this by writing
        // 80 spaces to it.
        for (i = 24*80; i < 25*80; i++)
        {
            video_memory[i] = blank;
        }
        // The cursor should now be on the last line.
        cursor_y = 24;
    }
}

// Writes a single character out to the screen.
void vga_put(char c)
{
    // The attribute byte is made up of two nibbles - the lower being the 
    // foreground colour, and the upper the background colour.
    u8int  attributeByte = (bg_color << 4) | (fg_color & 0x0F);
    // The attribute byte is the top 8 bits of the word we have to send to the
    // VGA board.
    u16int attribute = attributeByte << 8;
    u16int *location;

    // Handle a backspace, by moving the cursor back one space
    if (c == 0x08 && cursor_x)
    {
        cursor_x--;
    }

    // Handle a tab by increasing the cursor's X, but only to a point
    // where it is divisible by 8.
    else if (c == 0x09)
    {
        cursor_x = (cursor_x+8) & ~(8-1);
    }

    // Handle carriage return
    else if (c == '\r')
    {
        cursor_x = 0;
    }

    // Handle newline by moving cursor back to left and increasing the row
    else if (c == '\n')
    {
        cursor_x = 0;
        cursor_y++;
    }
    // Handle any other printable character.
    else if(c >= ' ')
    {
        location = video_memory + (cursor_y*80 + cursor_x);
        *location = c | attribute;
        cursor_x++;
    }

    // Check if we need to insert a new line because we have reached the end
    // of the screen.
    if (cursor_x >= 80)
    {
        cursor_x = 0;
        cursor_y ++;
    }

    // Scroll the screen if needed.
    scroll();
    // Move the hardware cursor.
    move_cursor();

}

// Clears the screen, by copying lots of spaces to the framebuffer.
void vga_clear()
{
    // Make an attribute byte for the default colours

    //vga_setColor(VGA_WHITE,VGA_BLACK);
    vga_setColor(VGA_LIGHT_CYAN ,VGA_BLACK);

    u8int attributeByte = (bg_color << 4) | (fg_color & 0x0F);
    u16int blank = 0x20 /* space */ | (attributeByte << 8);
     
    memset(video_memory,blank,80*25);
    // Move the hardware cursor back to the start.
    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

// Outputs a null-terminated ASCII string to the monitor.
void vga_write(char *c)
{
    int i = 0;
    while (c[i])
    {
        vga_put(c[i++]);
    }
}

void vga_setColor(u32int fgColor , u32int bgColor)
{
	fg_color = fgColor;
	bg_color = bgColor;
}

void vga_init()
{
	video_memory = (u16int *)0xB8000; //TODO:Maintain a table for each phy address and pick up from there
	vga_clear();
	vga_write("  Finished VGA Driver Init \n");
}
