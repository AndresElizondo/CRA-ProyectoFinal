/*******************************************************************************
* File Name: Hall3.h  
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

#if !defined(CY_PINS_Hall3_ALIASES_H) /* Pins Hall3_ALIASES_H */
#define CY_PINS_Hall3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Hall3_0			(Hall3__0__PC)
#define Hall3_0_PS		(Hall3__0__PS)
#define Hall3_0_PC		(Hall3__0__PC)
#define Hall3_0_DR		(Hall3__0__DR)
#define Hall3_0_SHIFT	(Hall3__0__SHIFT)
#define Hall3_0_INTR	((uint16)((uint16)0x0003u << (Hall3__0__SHIFT*2u)))

#define Hall3_INTR_ALL	 ((uint16)(Hall3_0_INTR))


#endif /* End Pins Hall3_ALIASES_H */


/* [] END OF FILE */
