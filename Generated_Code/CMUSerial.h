/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CMUSerial.h
**     Project     : CrusherS3Bien
**     Processor   : MCF51QE128CLK
**     Component   : AsynchroSerial
**     Version     : Component 02.611, Driver 01.33, CPU db: 3.00.078
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2018-05-07, 16:43, # CodeGen: 9
**     Abstract    :
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
**     Settings    :
**         Serial channel              : SCI2
**
**         Protocol
**             Init baud rate          : 9600baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 8
**             Output buffer size      : 8
**
**         Registers
**             Input buffer            : SCI2D     [0xFFFF9877]
**             Output buffer           : SCI2D     [0xFFFF9877]
**             Control register        : SCI2C1    [0xFFFF9872]
**             Mode register           : SCI2C2    [0xFFFF9873]
**             Baud setting reg.       : SCI2BD    [0xFFFF9870]
**             Special register        : SCI2S1    [0xFFFF9874]
**
**         Input interrupt
**             Vector name             : Vsci2rx
**             Priority                : 240
**
**         Output interrupt
**             Vector name             : Vsci2tx
**             Priority                : 240
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     64               |  PTC6_RGPIO14_RxD2_ACMP2PLUS
**            Output  |     63               |  PTC7_RGPIO15_TxD2_ACMP2MINUS
**         ----------------------------------------------------------
**
**
**
**     Contents    :
**         RecvChar        - byte CMUSerial_RecvChar(CMUSerial_TComData *Chr);
**         SendChar        - byte CMUSerial_SendChar(CMUSerial_TComData Chr);
**         RecvBlock       - byte CMUSerial_RecvBlock(CMUSerial_TComData *Ptr, word Size, word *Rcv);
**         SendBlock       - byte CMUSerial_SendBlock(CMUSerial_TComData *Ptr, word Size, word *Snd);
**         ClearRxBuf      - byte CMUSerial_ClearRxBuf(void);
**         ClearTxBuf      - byte CMUSerial_ClearTxBuf(void);
**         GetCharsInRxBuf - word CMUSerial_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word CMUSerial_GetCharsInTxBuf(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file CMUSerial.h
** @version 01.33
** @brief
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
*/         
/*!
**  @addtogroup CMUSerial_module CMUSerial module documentation
**  @{
*/         

#ifndef __CMUSerial
#define __CMUSerial

/* MODULE CMUSerial. */

#include "Cpu.h"




#ifndef __BWUserType_CMUSerial_TError
#define __BWUserType_CMUSerial_TError
  /*lint -save  -esym(960,18.4) Disable MISRA rule (18.4) checking. */
  typedef union {
    byte err;
    struct {
      /*lint -save  -e46 Disable MISRA rule (6.4) checking. */
      bool OverRun  : 1;               /* Overrun error flag */
      bool Framing  : 1;               /* Framing error flag */
      bool Parity   : 1;               /* Parity error flag */
      bool RxBufOvf : 1;               /* Rx buffer full error flag */
      bool Noise    : 1;               /* Noise error flag */
      bool Break    : 1;               /* Break detect */
      bool LINSync  : 1;               /* LIN synchronization error */
      bool BitError  : 1;              /* Bit error flag - mismatch to the expected value happened. */
      /*lint -restore Enable MISRA rule (6.4) checking. */
    } errName;
  } CMUSerial_TError;                  /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
  /*lint -restore  +esym(960,18.4) Enable MISRA rule (18.4) checking. */
#endif

#ifndef __BWUserType_CMUSerial_TComData
#define __BWUserType_CMUSerial_TComData
  typedef byte CMUSerial_TComData ;    /* User type for communication. Size of this type depends on the communication data width. */
#endif

#define CMUSerial_INP_BUF_SIZE 0x08U   /* Input buffer size */
#define CMUSerial_OUT_BUF_SIZE 0x08U   /* Output buffer size */

extern byte CMUSerial_OutLen;          /* Length of the output buffer content */
extern byte CMUSerial_InpLen;          /* Length of the input buffer content */

byte CMUSerial_RecvChar(CMUSerial_TComData *Chr);
/*
** ===================================================================
**     Method      :  CMUSerial_RecvChar (component AsynchroSerial)
**     Description :
**         If any data is received, this method returns one character,
**         otherwise it returns an error code (it does not wait for
**         data). This method is enabled only if the receiver property
**         is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence the
**         information about an exception in interrupt mode is returned
**         only if there is a valid character ready to be read.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service> property
**                           is disabled and the <Break signal> property
**                           is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
** ===================================================================
*/

byte CMUSerial_SendChar(CMUSerial_TComData Chr);
/*
** ===================================================================
**     Method      :  CMUSerial_SendChar (component AsynchroSerial)
**     Description :
**         Sends one character to the channel. If the component is
**         temporarily disabled (Disable method) SendChar method only
**         stores data into an output buffer. In case of a zero output
**         buffer size, only one character can be stored. Enabling the
**         component (Enable method) starts the transmission of the
**         stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/

byte CMUSerial_RecvBlock(CMUSerial_TComData *Ptr,word Size,word *Rcv);
/*
** ===================================================================
**     Method      :  CMUSerial_RecvBlock (component AsynchroSerial)
**     Description :
**         If any data is received, this method returns the block of
**         the data and its length (and incidental error), otherwise it
**         returns an error code (it does not wait for data).
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is enabled.
**         If less than requested number of characters is received only
**         the available data is copied from the receive buffer to the
**         user specified destination. The value ERR_EXEMPTY is
**         returned and the value of variable pointed by the Rcv
**         parameter is set to the number of received characters.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of received data
**         Size            - Size of the block
**       * Rcv             - Pointer to real number of the received data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - The receive buffer didn't
**                           contain the requested number of data. Only
**                           available data has been returned.
**                           ERR_COMMON - common error occurred (the
**                           GetError method can be used for error
**                           specification)
** ===================================================================
*/

byte CMUSerial_SendBlock(const CMUSerial_TComData * Ptr,word Size,word *Snd);
/*
** ===================================================================
**     Method      :  CMUSerial_SendBlock (component AsynchroSerial)
**     Description :
**         Sends a block of characters to the channel.
**         This method is available only if non-zero length of the
**         output buffer is defined and the transmitter property is
**         enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of data to send
**         Size            - Size of the block
**       * Snd             - Pointer to number of data that are sent
**                           (moved to buffer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - It was not possible to send
**                           requested number of bytes
** ===================================================================
*/

byte CMUSerial_ClearRxBuf(void);
/*
** ===================================================================
**     Method      :  CMUSerial_ClearRxBuf (component AsynchroSerial)
**     Description :
**         Clears the receive buffer.
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte CMUSerial_ClearTxBuf(void);
/*
** ===================================================================
**     Method      :  CMUSerial_ClearTxBuf (component AsynchroSerial)
**     Description :
**         Clears the transmit buffer.
**         This method is available only if non-zero length of the
**         output buffer is defined and the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define CMUSerial_GetCharsInRxBuf() \
((word) CMUSerial_InpLen)              /* Return number of chars in receive buffer */
/*
** ===================================================================
**     Method      :  CMUSerial_GetCharsInRxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the input buffer. This
**         method is available only if the receiver property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/

#define CMUSerial_GetCharsInTxBuf() \
((word) CMUSerial_OutLen)              /* Return number of chars in the transmitter buffer */
/*
** ===================================================================
**     Method      :  CMUSerial_GetCharsInTxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the output buffer. This
**         method is available only if the transmitter property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/

__interrupt void CMUSerial_InterruptRx(void);
/*
** ===================================================================
**     Method      :  CMUSerial_InterruptRx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void CMUSerial_InterruptTx(void);
/*
** ===================================================================
**     Method      :  CMUSerial_InterruptTx (component AsynchroSerial)
**
**     Description :
**         The method services the transmit interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void CMUSerial_InterruptError(void);
/*
** ===================================================================
**     Method      :  CMUSerial_InterruptError (component AsynchroSerial)
**
**     Description :
**         The method services the error interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


void CMUSerial_Init(void);
/*
** ===================================================================
**     Method      :  CMUSerial_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the component's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END CMUSerial. */

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

#endif /* ifndef __CMUSerial */
