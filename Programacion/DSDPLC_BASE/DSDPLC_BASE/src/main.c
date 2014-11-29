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

//--------Define Alias for the IOS
//INPUTS
#define S1A X1 //switch 1 de 3 posiciones contacto 1
#define S1B X2 //switch 1 de 3 posiciones contacto 2
#define PEDAL X3 //Pedal de pie
//#define S2B X4 //switch 2 de 3 posiciones contacto 2
#define B1 X5 //Boton para corrida manual
#define S_MV X6 //señal de la maquina MV
#define OUT1 X7 //SMC- señal out1 del actuador
#define OUT2 X8 //SMC-señal out2 del actuador
#define INP X9 //SCM-señal INP del actuador
#define BUSY X10 //SMC-señal busy del actuador
//OUTPUTS
#define VJ_T1 Y1 //Videojet Trigger 1
#define VJ_T2 Y2 //Videojet Trigger 2
#define DRIVE Y7 // SMC-señal drive del actuador
#define IN0 Y8 //SMC-señal IN0 del actuador
#define IN1 Y9 // SMC-señal IN1 del actuador
#define SVON Y10// SCM-señal SVON para encender o apagar el motor del actuador
#define SETUP Y11// SMC-señal SETUP se utiliza al principio del ciclo para que vuela a posición inicial.

//Posiciones posibles
#define POS_inicial




#define DELAY_ON 10
#define M1_DELAY1_A 200 //DELAY 1 DEL MODO 1 EN DIRECCIÓN FORWARD
#define M1_DELAY2_A 170 //DELAY 2 DEL MODO 1 EN DIRECCIÓN FORWARD
#define M1_DELAY3_A 160 //DELAY 3 DEL MODO 1 EN DIRECCIÓN FORWARD
#define M1_DELAY1_B 200 //DELAY 1 DEL MODO 1 EN DIRECCIÓN BACKWARDS
#define M1_DELAY2_B 140 //DELAY 2 DEL MODO 1 EN DIRECCIÓN BACKWARDS
#define M1_DELAY3_B 170 //DELAY 3 DEL MODO 1 EN DIRECCIÓN BACKWARDS

#define M2_DELAY1_A 180 //DELAY 1 DEL MODO 2 EN DIRECCIÓN FORWARD
#define M2_DELAY1_B 180 //DELAY 1 DEL MODO 2 EN DIRECCIÓN BACKWARDS

#define MODO_1 1
#define MODO_2 0

void setup_inicial(void); //Setup del equipo al encenderce
void modo1(int dir); //Impresión de 3 secuencias a velocidad media. CODIFICACION binaria 00
void modo2(int dir); //Impresión de 3 secuencias a velocidad alta.  CODIFICACION binaria 01
void modo3(void); //Impresión de 1 secuencia a velocidad media.  Codificacion binaria 10

void imprimir(int dir);
void mover_actuador(int pos);
int current_mode = 1;


int main (void)
{

	init_DSD_PLC();
	setup_inicial();
	delay_ms(500);
	if(S1B())
	{
		mover_actuador(0);
		current_mode=MODO_1;
	}
	else
	{
		mover_actuador(2);
		current_mode=MODO_2;
	}
	
	int dir=1;
	for (;;)
	{
		while (PEDAL()==OFF && S_MV()==OFF && B1()==OFF)
		{
			if (current_mode!=S1B())
			{
				if (current_mode==MODO_1)
				{
					if (dir==1)
					{
						mover_actuador(2);
					}
					else
					{
						mover_actuador(3);
					}
					current_mode=MODO_2;
				}
				else if(current_mode==MODO_2)
				{
					if (dir==1)
					{
						mover_actuador(0);
					}
					else
					{
						mover_actuador(1);
					}
					current_mode=MODO_1;	
				}
			}
				
		} //end while
		
		if(current_mode==MODO_1)
		{
			modo1(dir);
		}
		else if(current_mode==MODO_2)
		{
			modo2(dir);
		}
		delay_ms(500);
		if(dir == 1)
		{
			dir=0;
		}
		else
		{
			dir =1;
		}
		
	}

}

void setup_inicial(void)
{
	SVON(SET);
	delay_s(10);
	SETUP(SET);
	delay_ms(200);
	SETUP(RESET);
	while(BUSY()==ON);
// 	delay_ms(200);
// 	SVON(RESET);
}

void modo1(int dir) // modo Automatico-- Sella 3 bolsas
{
	SVON(SET);
	delay_ms(100);
	switch(dir)
	{
		case 1:
			IN0(SET);
			IN1(RESET);
			VJ_T2(RESET);
			delay_ms(50);
			DRIVE(SET);
			delay_ms(M1_DELAY1_A); //delay 1
			DRIVE(RESET);
			VJ_T1(SET); //impresion 1
			delay_ms(DELAY_ON);
			VJ_T1(RESET);
			delay_ms(M1_DELAY2_A); //delay 2
			VJ_T1(SET); //impresion 2
			delay_ms(DELAY_ON);
			VJ_T1(RESET);
			delay_ms(M1_DELAY3_A); //delay 3
			VJ_T1(SET); //impresion 3
			delay_ms(DELAY_ON);
			VJ_T1(RESET);
			while(BUSY==ON);
		break;
		case 0:
			IN0(RESET);
			IN1(RESET);
			VJ_T2(SET);
			delay_ms(100);
			DRIVE(SET);
			delay_ms(M1_DELAY1_B); //delay 1
			DRIVE(RESET);
			VJ_T1(SET); //impresion 1
			delay_ms(DELAY_ON);
			VJ_T1(RESET);
			delay_ms(M1_DELAY2_B); //delay 2
			VJ_T1(SET); //impresion 2
			delay_ms(DELAY_ON);
			VJ_T1(RESET);
			delay_ms(M1_DELAY3_B); //delay 3
			VJ_T1(SET); //impresion 3
			delay_ms(DELAY_ON);
			VJ_T1(RESET);
			while(BUSY==ON);
		break;
	}
}

void modo2(int dir) // modo Manual -- Sella 1 sola bolsa
{
	SVON(SET);
	delay_ms(100);
	switch(dir)
	{
		case 1:
		IN0(SET);
		IN1(SET);
		VJ_T2(RESET);
		delay_ms(5);
		DRIVE(SET);
		delay_ms(M2_DELAY1_A); //delay 1
		DRIVE(RESET);
		VJ_T1(SET); //impresion 1
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		while(BUSY==ON);
		break;
		case 0:
		IN0(RESET);
		IN1(SET);
		VJ_T2(SET);
		delay_ms(5);
		DRIVE(SET);
		delay_ms(M2_DELAY1_B); //delay 1
		DRIVE(RESET);
		VJ_T1(SET); //impresion 1
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		while(BUSY==ON);
		break;
	}
}

void imprimir(int dir)
{
	SVON(SET);
	delay_ms(100);
	switch(dir)
	{
		case 1:
		IN0(SET);
		VJ_T2(RESET);
		delay_ms(100);
		DRIVE(SET);
		delay_ms(100);
		DRIVE(RESET);
		delay_ms(M1_DELAY1_A); //delay 1
		VJ_T1(SET);
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		delay_ms(M1_DELAY2_A); //delay 2
		VJ_T1(SET);
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		delay_ms(M1_DELAY3_A); //delay 3
		VJ_T1(SET);
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		while(BUSY==ON);
		delay_ms(500);
		break;
		case 0:
		IN0(RESET);
		VJ_T2(SET);
		delay_ms(100);
		DRIVE(SET);
		delay_ms(100);
		DRIVE(RESET);
		delay_ms(M1_DELAY1_A); //delay 1
		VJ_T1(SET);
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		delay_ms(M1_DELAY2_A); //delay 2
		VJ_T1(SET);
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		delay_ms(M1_DELAY3_A); //delay 3
		VJ_T1(SET);
		delay_ms(DELAY_ON);
		VJ_T1(RESET);
		while(BUSY==ON);
		delay_ms(500);
		break;
	}
	
	
}


void mover_actuador(int pos)
{
	switch(pos)
	{
		case 0:
			IN0(RESET);
			IN1(RESET);
			break;
		case 1:
			IN0(SET);
			IN1(RESET);
			break;
		case 2:
			IN0(RESET);
			IN1(SET);
			break;
		case 3:
			IN0(SET);
			IN1(SET);
			break;
	}
	delay_ms(100);
	DRIVE(SET);
	delay_ms(500);
	DRIVE(RESET);
	while(BUSY==ON);
	delay_ms(500);
}