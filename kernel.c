#include"kernel.h"


//a func that returns a value of each 16 bit pixel of the char that we want to display on screen witha color
//must return a 16bit value because of the TERMINAL_BUFFER which is 16bit
static UINT16 VGA_DefaultEntry(unsigned char ch_to_print)
{
	//will convert white color value to the drawable char in pixel format  encoding
	return (UINT16) ch_to_print | (UINT16)WHITE_COLOR << 8;
}


//main func that was called in boot.S file

void KERNEL_MAIN()
{
	//first init a TERMINAL_BUFFER pointer that points to VGA address, Ccast to UINT16
	TERMINAL_BUFFER = (UINT16*) VGA_ADRESS;

	//now VGA can we accessed 
	TERMINAL_BUFFER[0] = VGA_DefaultEntry('H');
	TERMINAL_BUFFER[1] = VGA_DefaultEntry('e');
	TERMINAL_BUFFER[2] = VGA_DefaultEntry('l');
	TERMINAL_BUFFER[3] = VGA_DefaultEntry('l');
	TERMINAL_BUFFER[4] = VGA_DefaultEntry('o');
	TERMINAL_BUFFER[5] = VGA_DefaultEntry(' ');
	TERMINAL_BUFFER[6] = VGA_DefaultEntry('w');
	TERMINAL_BUFFER[7] = VGA_DefaultEntry('o');
	TERMINAL_BUFFER[8] = VGA_DefaultEntry('r');
	TERMINAL_BUFFER[9] = VGA_DefaultEntry('l');
	TERMINAL_BUFFER[10] = VGA_DefaultEntry('d');
	TERMINAL_BUFFER[11] = VGA_DefaultEntry('!');


}


