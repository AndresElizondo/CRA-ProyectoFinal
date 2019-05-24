/*******************************************************************************
* File Name: Vrpm.h  
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

#if !defined(CY_PINS_Vrpm_H) /* Pins Vrpm_H */
#define CY_PINS_Vrpm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vrpm_aliases.h"


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
} Vrpm_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Vrpm_Read(void);
void    Vrpm_Write(uint8 value);
uint8   Vrpm_ReadDataReg(void);
#if defined(Vrpm__PC) || (CY_PSOC4_4200L) 
    void    Vrpm_SetDriveMode(uint8 mode);
#endif
void    Vrpm_SetInterruptMode(uint16 position, uint16 mode);
uint8   Vrpm_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Vrpm_Sleep(void); 
void Vrpm_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Vrpm__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Vrpm_DRIVE_MODE_BITS        (3)
    #define Vrpm_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vrpm_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Vrpm_SetDriveMode() function.
         *  @{
         */
        #define Vrpm_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Vrpm_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Vrpm_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Vrpm_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Vrpm_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Vrpm_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Vrpm_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Vrpm_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Vrpm_MASK               Vrpm__MASK
#define Vrpm_SHIFT              Vrpm__SHIFT
#define Vrpm_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Vrpm_SetInterruptMode() function.
     *  @{
     */
        #define Vrpm_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Vrpm_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Vrpm_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Vrpm_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Vrpm__SIO)
    #define Vrpm_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Vrpm__PC) && (CY_PSOC4_4200L)
    #define Vrpm_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Vrpm_USBIO_DISABLE              ((uint32)(~Vrpm_USBIO_ENABLE))
    #define Vrpm_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Vrpm_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Vrpm_USBIO_ENTER_SLEEP          ((uint32)((1u << Vrpm_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Vrpm_USBIO_SUSPEND_DEL_SHIFT)))
    #define Vrpm_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Vrpm_USBIO_SUSPEND_SHIFT)))
    #define Vrpm_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Vrpm_USBIO_SUSPEND_DEL_SHIFT)))
    #define Vrpm_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Vrpm__PC)
    /* Port Configuration */
    #define Vrpm_PC                 (* (reg32 *) Vrpm__PC)
#endif
/* Pin State */
#define Vrpm_PS                     (* (reg32 *) Vrpm__PS)
/* Data Register */
#define Vrpm_DR                     (* (reg32 *) Vrpm__DR)
/* Input Buffer Disable Override */
#define Vrpm_INP_DIS                (* (reg32 *) Vrpm__PC2)

/* Interrupt configuration Registers */
#define Vrpm_INTCFG                 (* (reg32 *) Vrpm__INTCFG)
#define Vrpm_INTSTAT                (* (reg32 *) Vrpm__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Vrpm_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Vrpm__SIO)
    #define Vrpm_SIO_REG            (* (reg32 *) Vrpm__SIO)
#endif /* (Vrpm__SIO_CFG) */

/* USBIO registers */
#if !defined(Vrpm__PC) && (CY_PSOC4_4200L)
    #define Vrpm_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Vrpm_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Vrpm_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Vrpm_DRIVE_MODE_SHIFT       (0x00u)
#define Vrpm_DRIVE_MODE_MASK        (0x07u << Vrpm_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Vrpm_H */


/* [] END OF FILE */
