/***************************************************************************//**
* \file UART_Pi_SPI_UART_PVT.h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_UART_Pi_H)
#define CY_SCB_SPI_UART_PVT_UART_Pi_H

#include "UART_Pi_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (UART_Pi_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  UART_Pi_rxBufferHead;
    extern volatile uint32  UART_Pi_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   UART_Pi_rxBufferOverflow;
    /** @} globals */
#endif /* (UART_Pi_INTERNAL_RX_SW_BUFFER_CONST) */

#if (UART_Pi_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  UART_Pi_txBufferHead;
    extern volatile uint32  UART_Pi_txBufferTail;
#endif /* (UART_Pi_INTERNAL_TX_SW_BUFFER_CONST) */

#if (UART_Pi_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 UART_Pi_rxBufferInternal[UART_Pi_INTERNAL_RX_BUFFER_SIZE];
#endif /* (UART_Pi_INTERNAL_RX_SW_BUFFER) */

#if (UART_Pi_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 UART_Pi_txBufferInternal[UART_Pi_TX_BUFFER_SIZE];
#endif /* (UART_Pi_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void UART_Pi_SpiPostEnable(void);
void UART_Pi_SpiStop(void);

#if (UART_Pi_SCB_MODE_SPI_CONST_CFG)
    void UART_Pi_SpiInit(void);
#endif /* (UART_Pi_SCB_MODE_SPI_CONST_CFG) */

#if (UART_Pi_SPI_WAKE_ENABLE_CONST)
    void UART_Pi_SpiSaveConfig(void);
    void UART_Pi_SpiRestoreConfig(void);
#endif /* (UART_Pi_SPI_WAKE_ENABLE_CONST) */

void UART_Pi_UartPostEnable(void);
void UART_Pi_UartStop(void);

#if (UART_Pi_SCB_MODE_UART_CONST_CFG)
    void UART_Pi_UartInit(void);
#endif /* (UART_Pi_SCB_MODE_UART_CONST_CFG) */

#if (UART_Pi_UART_WAKE_ENABLE_CONST)
    void UART_Pi_UartSaveConfig(void);
    void UART_Pi_UartRestoreConfig(void);
#endif /* (UART_Pi_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in UART_Pi_SetPins() */
#define UART_Pi_UART_RX_PIN_ENABLE    (UART_Pi_UART_RX)
#define UART_Pi_UART_TX_PIN_ENABLE    (UART_Pi_UART_TX)

/* UART RTS and CTS position to be used in  UART_Pi_SetPins() */
#define UART_Pi_UART_RTS_PIN_ENABLE    (0x10u)
#define UART_Pi_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define UART_Pi_SpiUartEnableIntRx(intSourceMask)  UART_Pi_SetRxInterruptMode(intSourceMask)
#define UART_Pi_SpiUartEnableIntTx(intSourceMask)  UART_Pi_SetTxInterruptMode(intSourceMask)
uint32  UART_Pi_SpiUartDisableIntRx(void);
uint32  UART_Pi_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_UART_Pi_H) */


/* [] END OF FILE */
