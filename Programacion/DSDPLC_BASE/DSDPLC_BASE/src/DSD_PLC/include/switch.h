/*
 * switch.h
 *
 * DeepSea Developments
 *
 * Developed for the OctopusBot BTonly version. Open Source
 *
 * Created: 25/07/2013 11:36:53 p.m.
 *  Author: Nick
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "./../DSD_PLC.h"

#define SW1_PIN IOPORT_CREATE_PIN(PORTC, 3)

enum{
	SW1
	};

void switch_init(void);
int switch_state(int sw);



#endif /* SWITCH_H_ */