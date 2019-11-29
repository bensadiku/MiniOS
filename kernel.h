#ifndef KERNEL_H
#define KERNEL_H

//def VGA address
#define VGA_ADRESS 0xB8000

//a default color to display chars
#define WHITE_COLOR 15

//define a 16 bit unsigned type
typedef unsigned short UINT16;

//the buffer that points to a VGA , VGA_BUFFER -> alt name
UINT16 *TERMINAL_BUFFER;

#endif

