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
	ioport_set_pin_dir(X_1,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_2,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_3,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_4,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_5,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_6,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_7,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_8,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_9,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_10,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_11,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(X_12,IOPORT_DIR_INPUT);
	
	ioport_set_pin_dir(Y_1,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_2,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_3,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_4,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_5,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_6,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_7,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_8,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_9,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_10,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_11,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Y_12,IOPORT_DIR_OUTPUT);
	
	Y1(RESET);
	Y2(RESET);
	Y3(RESET);
	Y4(RESET);
	Y5(RESET);
	Y6(RESET);
	Y7(RESET);
	Y8(RESET);
	Y9(RESET);
	Y10(RESET);
	Y11(RESET);
	Y12(RESET);
	
}

void Y1(int state)
{
	switch(state)
	{
		case SET:
			ioport_set_pin_level(Y_1,0);
		break;
		case RESET:
			ioport_set_pin_level(Y_1,1);
		break;
		case TOGGLE:
			ioport_toggle_pin_level(Y_1);
		break;
	}
}

void Y2(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_2,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_2,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_2);
		break;
	}
}

void Y3(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_3,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_3,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_3);
		break;
	}
}

void Y4(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_4,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_4,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_4);
		break;
	}
}

void Y5(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_5,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_5,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_5);
		break;
	}
}

void Y6(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_6,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_6,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_6);
		break;
	}
}

void Y7(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_7,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_7,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_7);
		break;
	}
}

void Y8(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_8,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_8,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_8);
		break;
	}
}

void Y9(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_9,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_9,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_9);
		break;
	}
}

void Y10(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_10,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_10,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_10);
		break;
	}
}

void Y11(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_11,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_11,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_11);
		break;
	}
}

void Y12(int state)
{
	switch(state)
	{
		case SET:
		ioport_set_pin_level(Y_12,0);
		break;
		case RESET:
		ioport_set_pin_level(Y_12,1);
		break;
		case TOGGLE:
		ioport_toggle_pin_level(Y_12);
		break;
	}
}

int X1(void)
{
	int aux;
	if (ioport_get_pin_level(X_1) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X2(void)
{
	int aux;
	if (ioport_get_pin_level(X_2) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}


int X3(void)
{
	int aux;
	if (ioport_get_pin_level(X_3) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X4(void)
{
	int aux;
	if (ioport_get_pin_level(X_4) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X5(void)
{
	int aux;
	if (ioport_get_pin_level(X_5) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X6(void)
{
	int aux;
	if (ioport_get_pin_level(X_6) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X7(void)
{
	int aux;
	if (ioport_get_pin_level(X_7) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X8(void)
{
	int aux;
	if (ioport_get_pin_level(X_8) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X9(void)
{
	int aux;
	if (ioport_get_pin_level(X_9) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X10(void)
{
	int aux;
	if (ioport_get_pin_level(X_10) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X11(void)
{
	int aux;
	if (ioport_get_pin_level(X_11) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}

int X12(void)
{
	int aux;
	if (ioport_get_pin_level(X_12) == 1)
	{
		aux=OFF;
	}
	else
	{
		aux=ON;
	}
	return aux;
}