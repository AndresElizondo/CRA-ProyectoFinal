/*******************************************************************************
* File Name: Hall1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Hall1_H) /* Pins Hall1_H */
#define CY_PINS_Hall1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Hall1_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Hall1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Hall1_Read(void);
void    Hall1_Write(uint8 value);
uint8   Hall1_ReadDataReg(void);
#if defined(Hall1__PC) || (CY_PSOC4_4200L) 
    void    Hall1_SetDriveMode(uint8 mode);
#endif
void    Hall1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Hall1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Hall1_Sleep(void); 
void Hall1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Hall1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Hall1_DRIVE_MODE_BITS        (3)
    #define Hall1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Hall1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Hall1_SetDriveMode() function.
         *  @{
         */
        #define Hall1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Hall1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Hall1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Hall1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Hall1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Hall1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Hall1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Hall1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Hall1_MASK               Hall1__MASK
#define Hall1_SHIFT              Hall1__SHIFT
#define Hall1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Hall1_SetInterruptMode() function.
     *  @{
     */
        #define Hall1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Hall1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Hall1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Hall1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Hall1__SIO)
    #define Hall1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Hall1__PC) && (CY_PSOC4_4200L)
    #define Hall1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Hall1_USBIO_DISABLE              ((uint32)(~Hall1_USBIO_ENABLE))
    #define Hall1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Hall1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Hall1_USBIO_ENTER_SLEEP          ((uint32)((1u << Hall1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Hall1_USBIO_SUSPEND_DEL_SHIFT)))
    #define Hall1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Hall1_USBIO_SUSPEND_SHIFT)))
    #define Hall1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Hall1_USBIO_SUSPEND_DEL_SHIFT)))
    #define Hall1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Hall1__PC)
    /* Port Configuration */
    #define Hall1_PC                 (* (reg32 *) Hall1__PC)
#endif
/* Pin State */
#define Hall1_PS                     (* (reg32 *) Hall1__PS)
/* Data Register */
#define Hall1_DR                     (* (reg32 *) Hall1__DR)
/* Input Buffer Disable Override */
#define Hall1_INP_DIS                (* (reg32 *) Hall1__PC2)

/* Interrupt configuration Registers */
#define Hall1_INTCFG                 (* (reg32 *) Hall1__INTCFG)
#define Hall1_INTSTAT                (* (reg32 *) Hall1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Hall1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Hall1__SIO)
    #define Hall1_SIO_REG            (* (reg32 *) Hall1__SIO)
#endif /* (Hall1__SIO_CFG) */

/* USBIO registers */
#if !defined(Hall1__PC) && (CY_PSOC4_4200L)
    #define Hall1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Hall1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Hall1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Hall1_DRIVE_MODE_SHIFT       (0x00u)
#define Hall1_DRIVE_MODE_MASK        (0x07u << Hall1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Hall1_H */


/* [] END OF FILE */
