/* ###################################################################
**     Filename    : main.c
**     Project     : CrusherS3Bien
**     Processor   : MCF51QE128CLK
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2018-05-07, 15:10, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AS1.h"
#include "CMUSerial.h"
#include "Bit1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

unsigned char estado = ESPERAR;
unsigned int num, i;
unsigned char recibir;
unsigned char recibido[]; 
unsigned char bloque1[1] = {13};					//\r		ACK o NCK
unsigned char bloque2[5] = {76, 49, 32, 49, 13};	//L1 1\r	Prende Tracking LED
unsigned char bloque3[5] = {76, 49, 32, 48, 13};	//L1 0\r	Apada Tracking LED
unsigned char bloque4[5] = {68, 77, 32, 49, 13};	//DM 1\r	Delay 0 (One bit at the current baud rate) - de 0 a 255
unsigned char bloque5[3] = {71, 77, 13};			//GM\r		Get Mean (Color medio y desviacion)
unsigned char bloque6[3] = {77, 77, 13};			//MM\r		Middle Mass (Centroide)
unsigned char bloque7[3] = {80, 77, 13};			//PM\r		Poll Mode (Paquete Unico)
unsigned char bloque8[3] = {82, 83, 13};			//RS\r		Reset
//unsigned char bloque9[7] = {87, 83, x, y, x2, y2, 13} 	//WS x y x2 y2\r	Window Size (Max 1,1,80,143)		Esquina superior izquierda y esquina inferior derecha
//unsigned char bloque10[9] = {84, 67, Rmin, Rmax, Gmin, Gmax, Bmin, Bmax, 13}	//TC Rmin Rmax Gmin Gmax Bmin Bmax\r	Track un Color especifico
unsigned char bloque11[3] = {84, 87, 13};			//TW\r	Track el color de la region central de la ventana escogida
unsigned char bloque12[4] = {83, 77, 48, 13};		//SM 0\r	Modo del tracking de color normal tipo C
unsigned char bloque13[4] = {83, 77, 49, 13};		//SM 1\r	Modo del tracking de color alternado tipo CS

void mandarCMU(unsigned char bloque[],unsigned int tam);
void mandarSerial(unsigned char bloque[],unsigned int tam);

void mandarCMU(unsigned char bloque[],unsigned int tam){
	for(i=0;i<tam;i++){
		CMUSerial_SendChar(bloque[i]);
	}
}

void mandarSerial(unsigned char bloque[],unsigned int tam){
	for(i=0;i<tam;i++){
		AS1_SendChar(bloque[i]);
	}
}

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
for(;;) { 
	switch(estado){
		case ESPERAR:
			Cpu_Delay100US(10000);
			estado = ENVIAR;
			break;
		case ENVIAR:
			Bit1_PutVal(0);
			Cpu_Delay100US(10000);
			
			mandarCMU(bloque2,sizeof(bloque2));
			
			estado = RECIBIR;		
			break;
		case RECIBIR:
			Bit1_PutVal(1);
			i = 0;
			do{
				CMUSerial_RecvChar(&recibir);
				recibido[i] = recibir;
				i++;
			}while(CMUSerial_RecvChar(&recibir) != 13);

			//AS1_SendChar(recibir);
			//mandarSerial(recibido,sizeof(recibido));
			
			Cpu_Delay100US(10000);
			estado = ESPERAR;
		default:
			break;
				} 
 	 	 }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
