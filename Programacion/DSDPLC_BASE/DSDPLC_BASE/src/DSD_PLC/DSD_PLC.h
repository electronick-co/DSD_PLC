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

#define X1 IOPORT_CREATE_PIN(PORTR, 1)
#define X2 IOPORT_CREATE_PIN(PORTR, 0)
#define X3 IOPORT_CREATE_PIN(PORTE, 3)
#define X4 IOPORT_CREATE_PIN(PORTE, 2)
#define X5 IOPORT_CREATE_PIN(PORTE, 1)
#define X6 IOPORT_CREATE_PIN(PORTE, 0)
#define X7 IOPORT_CREATE_PIN(PORTD, 5)
#define X8 IOPORT_CREATE_PIN(PORTD, 4)
#define X9 IOPORT_CREATE_PIN(PORTC, 7)
#define X10 IOPORT_CREATE_PIN(PORTC, 6)
#define X11 IOPORT_CREATE_PIN(PORTC, 5)
#define X12 IOPORT_CREATE_PIN(PORTC, 4) 

#define Y1 IOPORT_CREATE_PIN(PORTA, 4) 
#define Y2 IOPORT_CREATE_PIN(PORTA, 3) 
#define Y3 IOPORT_CREATE_PIN(PORTA, 6) 
#define Y4 IOPORT_CREATE_PIN(PORTA, 5) 
#define Y5 IOPORT_CREATE_PIN(PORTB, 0) 
#define Y6 IOPORT_CREATE_PIN(PORTA, 7) 
#define Y7 IOPORT_CREATE_PIN(PORTB, 2) 
#define Y8 IOPORT_CREATE_PIN(PORTB, 1) 
#define Y9 IOPORT_CREATE_PIN(PORTC, 0) 
#define Y10 IOPORT_CREATE_PIN(PORTB, 3) 
#define Y11 IOPORT_CREATE_PIN(PORTC, 2) 
#define Y12 IOPORT_CREATE_PIN(PORTC, 1) 


/************************************************************************/
/* Configuration in initiation. To disable one of the following options, comment it.*/
/************************************************************************/
//#define ENABLE_USB
//#define ENABLE_RTC

/************************************************************************/
/* Printf and scan f function can be use with usb Choose the communication method you are going to use*/
/************************************************************************/
//#define PRINTF_USB



void init_DSD_PLC(void);





#endif /* DSD_PLC_H_ */