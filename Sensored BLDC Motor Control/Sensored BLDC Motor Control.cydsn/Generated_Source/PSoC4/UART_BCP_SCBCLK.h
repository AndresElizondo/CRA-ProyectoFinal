/*******************************************************************************
* File Name: UART_BCP_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_UART_BCP_SCBCLK_H)
#define CY_CLOCK_UART_BCP_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void UART_BCP_SCBCLK_StartEx(uint32 alignClkDiv);
#define UART_BCP_SCBCLK_Start() \
    UART_BCP_SCBCLK_StartEx(UART_BCP_SCBCLK__PA_DIV_ID)

#else

void UART_BCP_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void UART_BCP_SCBCLK_Stop(void);

void UART_BCP_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 UART_BCP_SCBCLK_GetDividerRegister(void);
uint8  UART_BCP_SCBCLK_GetFractionalDividerRegister(void);

#define UART_BCP_SCBCLK_Enable()                         UART_BCP_SCBCLK_Start()
#define UART_BCP_SCBCLK_Disable()                        UART_BCP_SCBCLK_Stop()
#define UART_BCP_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    UART_BCP_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define UART_BCP_SCBCLK_SetDivider(clkDivider)           UART_BCP_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define UART_BCP_SCBCLK_SetDividerValue(clkDivider)      UART_BCP_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define UART_BCP_SCBCLK_DIV_ID     UART_BCP_SCBCLK__DIV_ID

#define UART_BCP_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define UART_BCP_SCBCLK_CTRL_REG   (*(reg32 *)UART_BCP_SCBCLK__CTRL_REGISTER)
#define UART_BCP_SCBCLK_DIV_REG    (*(reg32 *)UART_BCP_SCBCLK__DIV_REGISTER)

#define UART_BCP_SCBCLK_CMD_DIV_SHIFT          (0u)
#define UART_BCP_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define UART_BCP_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define UART_BCP_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define UART_BCP_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << UART_BCP_SCBCLK_CMD_DISABLE_SHIFT))
#define UART_BCP_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << UART_BCP_SCBCLK_CMD_ENABLE_SHIFT))

#define UART_BCP_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define UART_BCP_SCBCLK_DIV_FRAC_SHIFT (3u)
#define UART_BCP_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define UART_BCP_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define UART_BCP_SCBCLK_DIV_REG        (*(reg32 *)UART_BCP_SCBCLK__REGISTER)
#define UART_BCP_SCBCLK_ENABLE_REG     UART_BCP_SCBCLK_DIV_REG
#define UART_BCP_SCBCLK_DIV_FRAC_MASK  UART_BCP_SCBCLK__FRAC_MASK
#define UART_BCP_SCBCLK_DIV_FRAC_SHIFT (16u)
#define UART_BCP_SCBCLK_DIV_INT_MASK   UART_BCP_SCBCLK__DIVIDER_MASK
#define UART_BCP_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_UART_BCP_SCBCLK_H) */

/* [] END OF FILE */
