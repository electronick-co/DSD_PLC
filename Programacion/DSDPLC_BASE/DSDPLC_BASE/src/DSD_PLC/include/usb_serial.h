/*
 * usb_serial.h
 *
 * Created: 25/07/2013 11:39:55 p.m.
 *  Author: Nick
 */ 


#ifndef USB_SERIAL_H_
#define USB_SERIAL_H_

#include "./../DSD_PLC.h"

#define MAX_TIMEOUT 1000

void usb_init(void);
void usb_putchar(char a);
char usb_getchar(void);
int usb_readchar(char * a);
int usb_is_rx_ready(void);
int usb_get_line(char * data);
int usb_read_line(char * data);
void usb_write_line(char * string);

#ifdef PRINTF_USB
	int usb_putchar_printf(char var, FILE *stream);
	int usb_getchar_scanf(FILE *stream);
	static FILE mystdout = FDEV_SETUP_STREAM(usb_putchar_printf, usb_getchar_scanf, _FDEV_SETUP_RW);
#endif


#endif /* USB_SERIAL_H_ */