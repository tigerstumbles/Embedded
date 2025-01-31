/*
 * cxw.c
 *
 *  Created on: 2015-6-29
 *      Author: suoni
 */


/*
 * cxw.c
 *
 *  Created on: 2015-6-24
 *      Author: suoni
 */


/*
 * cxw.c
 *
 *  Created on: 2015-6-23
 *      Author: suoni
 */


#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"

#define LED_DELAY     1000000000


//====================================================

int main (void)
{

    XGpio led, control;
	int i, psb_check,pss_check;
	long status;

    xil_printf("-- Start of the Program --\r\n");

    XGpio_Initialize(&led, XPAR_LED_DEVICE_ID);
	XGpio_SetDataDirection(&led, 1, 0x00000000);

	XGpio_Initialize(&control, XPAR_CONTROL_DEVICE_ID);
	XGpio_SetDataDirection(&control, 1, 0xffffffff);



	while (1)
	{

		status = XGpio_DiscreteRead(&control, 1);
		xil_printf("Total %x\r\n", status);
		pss_check=status>>4;
		psb_check=status&0x0f;
		xil_printf("Dip Switched Status %x\r\n", pss_check);
	    xil_printf("Push Buttons Status %x\r\n", psb_check);

	  	XGpio_DiscreteWrite(&led, 1,pss_check|psb_check);


	  for (i=0; i<9999999; i++);
	}

}


