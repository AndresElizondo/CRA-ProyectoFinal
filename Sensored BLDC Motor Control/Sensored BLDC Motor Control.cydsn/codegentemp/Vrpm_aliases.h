/*******************************************************************************
* File Name: Vrpm.h  
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

#if !defined(CY_PINS_Vrpm_ALIASES_H) /* Pins Vrpm_ALIASES_H */
#define CY_PINS_Vrpm_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Vrpm_0			(Vrpm__0__PC)
#define Vrpm_0_PS		(Vrpm__0__PS)
#define Vrpm_0_PC		(Vrpm__0__PC)
#define Vrpm_0_DR		(Vrpm__0__DR)
#define Vrpm_0_SHIFT	(Vrpm__0__SHIFT)
#define Vrpm_0_INTR	((uint16)((uint16)0x0003u << (Vrpm__0__SHIFT*2u)))

#define Vrpm_INTR_ALL	 ((uint16)(Vrpm_0_INTR))


#endif /* End Pins Vrpm_ALIASES_H */


/* [] END OF FILE */