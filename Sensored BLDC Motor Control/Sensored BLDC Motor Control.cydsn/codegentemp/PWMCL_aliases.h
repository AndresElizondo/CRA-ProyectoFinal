/*******************************************************************************
* File Name: PWMCL.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PWMCL_ALIASES_H) /* Pins PWMCL_ALIASES_H */
#define CY_PINS_PWMCL_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PWMCL_0			(PWMCL__0__PC)
#define PWMCL_0_PS		(PWMCL__0__PS)
#define PWMCL_0_PC		(PWMCL__0__PC)
#define PWMCL_0_DR		(PWMCL__0__DR)
#define PWMCL_0_SHIFT	(PWMCL__0__SHIFT)
#define PWMCL_0_INTR	((uint16)((uint16)0x0003u << (PWMCL__0__SHIFT*2u)))

#define PWMCL_INTR_ALL	 ((uint16)(PWMCL_0_INTR))


#endif /* End Pins PWMCL_ALIASES_H */


/* [] END OF FILE */
