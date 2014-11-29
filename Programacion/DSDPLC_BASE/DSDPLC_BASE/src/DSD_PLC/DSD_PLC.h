/*
 * DomOctopus.h
 *
 * Created: 10/08/2014 05:54:00 p.m.
 *  Author: Nick
 */ 


#ifndef DSD_PLC_H_
#define DSD_PLC_H_

#include <asf.h>
#include <stdio.h>
#include "include/switch.h"
#include "include/usb_serial.h"

#define X_1 IOPORT_CREATE_PIN(PORTR, 1)
#define X_2 IOPORT_CREATE_PIN(PORTR, 0)
#define X_3 IOPORT_CREATE_PIN(PORTE, 3)
#define X_4 IOPORT_CREATE_PIN(PORTE, 2)
#define X_5 IOPORT_CREATE_PIN(PORTE, 1)
#define X_6 IOPORT_CREATE_PIN(PORTE, 0)
#define X_7 IOPORT_CREATE_PIN(PORTD, 5)
#define X_8 IOPORT_CREATE_PIN(PORTD, 4)
#define X_9 IOPORT_CREATE_PIN(PORTC, 7)
#define X_10 IOPORT_CREATE_PIN(PORTC, 6)
#define X_11 IOPORT_CREATE_PIN(PORTC, 5)
#define X_12 IOPORT_CREATE_PIN(PORTC, 4) 

#define Y_1 IOPORT_CREATE_PIN(PORTA, 3) 
#define Y_2 IOPORT_CREATE_PIN(PORTA, 4) 
#define Y_3 IOPORT_CREATE_PIN(PORTA, 5) 
#define Y_4 IOPORT_CREATE_PIN(PORTA, 6) 
#define Y_5 IOPORT_CREATE_PIN(PORTA, 7) 
#define Y_6 IOPORT_CREATE_PIN(PORTB, 0) 
#define Y_7 IOPORT_CREATE_PIN(PORTB, 1) 
#define Y_8 IOPORT_CREATE_PIN(PORTB, 2) 
#define Y_9 IOPORT_CREATE_PIN(PORTB, 3) 
#define Y_10 IOPORT_CREATE_PIN(PORTC, 0) 
#define Y_11 IOPORT_CREATE_PIN(PORTC, 1) 
#define Y_12 IOPORT_CREATE_PIN(PORTC, 2) 



/************************************************************************/
/* Configuration in initiation. To disable one of the following options, comment it.*/
/************************************************************************/
//#define ENABLE_USB
//#define ENABLE_RTC

/************************************************************************/
/* Printf and scan f function can be use with usb Choose the communication method you are going to use*/
/************************************************************************/
//#define PRINTF_USB

enum{
	RESET,
	SET,
	TOGGLE
};

enum{
	OFF,
	ON
};

void init_DSD_PLC(void);
void Y1(int state);
void Y2(int state);
void Y3(int state);
void Y4(int state);
void Y5(int state);
void Y6(int state);
void Y7(int state);
void Y8(int state);
void Y9(int state);
void Y10(int state);
void Y11(int state);
void Y12(int state);
int X1(void);
int X2(void);
int X3(void);
int X4(void);
int X5(void);
int X6(void);
int X7(void);
int X8(void);
int X9(void);
int X10(void);
int X11(void);
int X12(void);


#endif /* DSD_PLC_H_ */