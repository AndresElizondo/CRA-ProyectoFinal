/*******************************************************************************
* File Name: Hall1.h  
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

#if !defined(CY_PINS_Hall1_ALIASES_H) /* Pins Hall1_ALIASES_H */
#define CY_PINS_Hall1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Hall1_0			(Hall1__0__PC)
#define Hall1_0_PS		(Hall1__0__PS)
#define Hall1_0_PC		(Hall1__0__PC)
#define Hall1_0_DR		(Hall1__0__DR)
#define Hall1_0_SHIFT	(Hall1__0__SHIFT)
#define Hall1_0_INTR	((uint16)((uint16)0x0003u << (Hall1__0__SHIFT*2u)))

#define Hall1_INTR_ALL	 ((uint16)(Hall1_0_INTR))


#endif /* End Pins Hall1_ALIASES_H */


/* [] END OF FILE */
