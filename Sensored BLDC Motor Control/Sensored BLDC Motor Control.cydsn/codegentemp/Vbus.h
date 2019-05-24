/*******************************************************************************
* File Name: Vbus.h  
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

#if !defined(CY_PINS_Vbus_H) /* Pins Vbus_H */
#define CY_PINS_Vbus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vbus_aliases.h"


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
} Vbus_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Vbus_Read(void);
void    Vbus_Write(uint8 value);
uint8   Vbus_ReadDataReg(void);
#if defined(Vbus__PC) || (CY_PSOC4_4200L) 
    void    Vbus_SetDriveMode(uint8 mode);
#endif
void    Vbus_SetInterruptMode(uint16 position, uint16 mode);
uint8   Vbus_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Vbus_Sleep(void); 
void Vbus_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Vbus__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Vbus_DRIVE_MODE_BITS        (3)
    #define Vbus_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vbus_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Vbus_SetDriveMode() function.
         *  @{
         */
        #define Vbus_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Vbus_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Vbus_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Vbus_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Vbus_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Vbus_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Vbus_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Vbus_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Vbus_MASK               Vbus__MASK
#define Vbus_SHIFT              Vbus__SHIFT
#define Vbus_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Vbus_SetInterruptMode() function.
     *  @{
     */
        #define Vbus_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Vbus_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Vbus_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Vbus_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Vbus__SIO)
    #define Vbus_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Vbus__PC) && (CY_PSOC4_4200L)
    #define Vbus_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Vbus_USBIO_DISABLE              ((uint32)(~Vbus_USBIO_ENABLE))
    #define Vbus_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Vbus_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Vbus_USBIO_ENTER_SLEEP          ((uint32)((1u << Vbus_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Vbus_USBIO_SUSPEND_DEL_SHIFT)))
    #define Vbus_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Vbus_USBIO_SUSPEND_SHIFT)))
    #define Vbus_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Vbus_USBIO_SUSPEND_DEL_SHIFT)))
    #define Vbus_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Vbus__PC)
    /* Port Configuration */
    #define Vbus_PC                 (* (reg32 *) Vbus__PC)
#endif
/* Pin State */
#define Vbus_PS                     (* (reg32 *) Vbus__PS)
/* Data Register */
#define Vbus_DR                     (* (reg32 *) Vbus__DR)
/* Input Buffer Disable Override */
#define Vbus_INP_DIS                (* (reg32 *) Vbus__PC2)

/* Interrupt configuration Registers */
#define Vbus_INTCFG                 (* (reg32 *) Vbus__INTCFG)
#define Vbus_INTSTAT                (* (reg32 *) Vbus__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Vbus_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Vbus__SIO)
    #define Vbus_SIO_REG            (* (reg32 *) Vbus__SIO)
#endif /* (Vbus__SIO_CFG) */

/* USBIO registers */
#if !defined(Vbus__PC) && (CY_PSOC4_4200L)
    #define Vbus_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Vbus_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Vbus_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Vbus_DRIVE_MODE_SHIFT       (0x00u)
#define Vbus_DRIVE_MODE_MASK        (0x07u << Vbus_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Vbus_H */


/* [] END OF FILE */
