/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include "DSD_PLC/DSD_PLC.h"

int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).

	init_DSD_PLC();
	
	for(;;)
	{
		ioport_set_pin_level(Y1,1);
		delay_ms(1000);
		ioport_set_pin_level(Y1,0);
		delay_ms(1000);
		
	}

	
}
