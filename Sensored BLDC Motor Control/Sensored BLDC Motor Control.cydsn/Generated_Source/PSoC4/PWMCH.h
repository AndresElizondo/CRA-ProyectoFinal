/*******************************************************************************
* File Name: PWMCH.h  
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

#if !defined(CY_PINS_PWMCH_H) /* Pins PWMCH_H */
#define CY_PINS_PWMCH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMCH_aliases.h"


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
} PWMCH_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PWMCH_Read(void);
void    PWMCH_Write(uint8 value);
uint8   PWMCH_ReadDataReg(void);
#if defined(PWMCH__PC) || (CY_PSOC4_4200L) 
    void    PWMCH_SetDriveMode(uint8 mode);
#endif
void    PWMCH_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMCH_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PWMCH_Sleep(void); 
void PWMCH_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PWMCH__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PWMCH_DRIVE_MODE_BITS        (3)
    #define PWMCH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMCH_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PWMCH_SetDriveMode() function.
         *  @{
         */
        #define PWMCH_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PWMCH_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PWMCH_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PWMCH_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PWMCH_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PWMCH_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PWMCH_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PWMCH_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PWMCH_MASK               PWMCH__MASK
#define PWMCH_SHIFT              PWMCH__SHIFT
#define PWMCH_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMCH_SetInterruptMode() function.
     *  @{
     */
        #define PWMCH_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PWMCH_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PWMCH_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PWMCH_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PWMCH__SIO)
    #define PWMCH_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PWMCH__PC) && (CY_PSOC4_4200L)
    #define PWMCH_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PWMCH_USBIO_DISABLE              ((uint32)(~PWMCH_USBIO_ENABLE))
    #define PWMCH_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PWMCH_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PWMCH_USBIO_ENTER_SLEEP          ((uint32)((1u << PWMCH_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PWMCH_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMCH_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PWMCH_USBIO_SUSPEND_SHIFT)))
    #define PWMCH_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PWMCH_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMCH_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PWMCH__PC)
    /* Port Configuration */
    #define PWMCH_PC                 (* (reg32 *) PWMCH__PC)
#endif
/* Pin State */
#define PWMCH_PS                     (* (reg32 *) PWMCH__PS)
/* Data Register */
#define PWMCH_DR                     (* (reg32 *) PWMCH__DR)
/* Input Buffer Disable Override */
#define PWMCH_INP_DIS                (* (reg32 *) PWMCH__PC2)

/* Interrupt configuration Registers */
#define PWMCH_INTCFG                 (* (reg32 *) PWMCH__INTCFG)
#define PWMCH_INTSTAT                (* (reg32 *) PWMCH__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PWMCH_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PWMCH__SIO)
    #define PWMCH_SIO_REG            (* (reg32 *) PWMCH__SIO)
#endif /* (PWMCH__SIO_CFG) */

/* USBIO registers */
#if !defined(PWMCH__PC) && (CY_PSOC4_4200L)
    #define PWMCH_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PWMCH_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PWMCH_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PWMCH_DRIVE_MODE_SHIFT       (0x00u)
#define PWMCH_DRIVE_MODE_MASK        (0x07u << PWMCH_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PWMCH_H */


/* [] END OF FILE */
