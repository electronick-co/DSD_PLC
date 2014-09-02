/*
 * usb_serial.c
 *
 * Created: 26/07/2013 04:52:17 p.m.
 *  Author: Nick
 */ 

#include "./../include/usb_serial.h"

void usb_init(void)
{
	irq_initialize_vectors();
	cpu_irq_enable();
	udc_start();
	udc_attach();
	
	#ifdef PRINTF_USB
	// setup our stdio stream
	stdout = &mystdout;
	stdin = &mystdout;
#endif
	
}

void usb_putchar(char a)
{
	udi_cdc_putc(a);
}

char usb_getchar(void)
{
	return udi_cdc_getc();
}

int usb_is_rx_ready(void)
{
	return udi_cdc_is_rx_ready();
}

int usb_read_line(char * data)
{
	char aux;
	int i=0;
	int end=0;
	int timeout = 0;
	while(end==0)
	{
		timeout = 0;
		while(1)
		{
			if(usb_is_rx_ready())
			{
				break;
			}
			if(timeout>MAX_TIMEOUT)
			{
				data[i]=0;
				return 0;//USART_FAILURE;
			}
			delay_ms(1);
			timeout ++;
		}
		
		aux=usb_getchar();
		if (aux==0x0D)
		{
			data[i]=0;
			end=1;
		}
		else
		{
			data[i]=aux;
		}
		i+=1;
	}
	return 1;//USART_SUCCESS;
}

int usb_get_line(char * data)
{
	char aux;
	int i=0;
	int end=0;

	while(end==0)
	{
		aux=usb_getchar();
		if (aux==0x0D)
		{
			data[i]=0;
			end=1;
		}
		else
		{
			data[i]=aux;
		}
		i+=1;
	}
	return 1;//USART_SUCCESS;
}

void usb_write_line(char * string)
{
	while (*string != '\0')
	usb_putchar(*string++);
}


#ifdef PRINTF_USB
int usb_putchar_printf(char var, FILE *stream) {
	// translate \n to \r for br@y++ terminal
	if (var == '\n') usb_putchar('\r');
	usb_putchar(var);
	return 0;
}

int usb_getchar_scanf(FILE *stream)
{
	uint8_t u8Data;
	// Wait for byte to be received
	while (usb_is_rx_ready()==0);
	u8Data=usb_getchar();
	//echo input data
	usb_putchar_printf(u8Data,stream);
	// Return received data
	return u8Data;
}
#endif