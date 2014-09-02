/*
 * DSD_PLC.c
 *
 * Created: 01/09/2014 12:16:41 p.m.
 *  Author: Nick
 *	
 * Revision A: NA
 * Revision B: NA
 * Revision C: NA
 * Revision D: NA
  *Revision E: NA
 */ 

#include "../DSD_PLC.h"

void init_DSD_PLC(void)
{
	sysclk_init();
	ioport_init();
	switch_init();
	
	#ifdef ENABLE_RTC
		rtc_init();
	#endif
	#ifdef ENABLE_USB
		usb_init();
	#endif
	
	/************************************************************************/
	/* Direcion of IOs                                                                     */
	/************************************************************************/
	ioport_set_pin_dir(X1,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X2,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X3,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X4,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X5,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X6,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X7,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X8,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X9,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X10,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X11,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X12,IOPORT_DIR_INPUT);
	
	ioport_set_pin_dir(Y1,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y2,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y3,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y4,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y5,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y6,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y7,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y8,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y9,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y10,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y11,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y12,IOPORT_DIR_OUTPUT);
	
	
}