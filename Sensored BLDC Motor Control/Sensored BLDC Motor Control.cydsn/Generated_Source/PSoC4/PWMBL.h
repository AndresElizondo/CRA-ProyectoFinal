/*******************************************************************************
* File Name: PWMBL.h  
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

#if !defined(CY_PINS_PWMBL_H) /* Pins PWMBL_H */
#define CY_PINS_PWMBL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMBL_aliases.h"


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
} PWMBL_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PWMBL_Read(void);
void    PWMBL_Write(uint8 value);
uint8   PWMBL_ReadDataReg(void);
#if defined(PWMBL__PC) || (CY_PSOC4_4200L) 
    void    PWMBL_SetDriveMode(uint8 mode);
#endif
void    PWMBL_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMBL_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PWMBL_Sleep(void); 
void PWMBL_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PWMBL__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PWMBL_DRIVE_MODE_BITS        (3)
    #define PWMBL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMBL_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PWMBL_SetDriveMode() function.
         *  @{
         */
        #define PWMBL_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PWMBL_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PWMBL_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PWMBL_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PWMBL_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PWMBL_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PWMBL_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PWMBL_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PWMBL_MASK               PWMBL__MASK
#define PWMBL_SHIFT              PWMBL__SHIFT
#define PWMBL_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMBL_SetInterruptMode() function.
     *  @{
     */
        #define PWMBL_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PWMBL_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PWMBL_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PWMBL_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PWMBL__SIO)
    #define PWMBL_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PWMBL__PC) && (CY_PSOC4_4200L)
    #define PWMBL_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PWMBL_USBIO_DISABLE              ((uint32)(~PWMBL_USBIO_ENABLE))
    #define PWMBL_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PWMBL_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PWMBL_USBIO_ENTER_SLEEP          ((uint32)((1u << PWMBL_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PWMBL_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMBL_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PWMBL_USBIO_SUSPEND_SHIFT)))
    #define PWMBL_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PWMBL_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMBL_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PWMBL__PC)
    /* Port Configuration */
    #define PWMBL_PC                 (* (reg32 *) PWMBL__PC)
#endif
/* Pin State */
#define PWMBL_PS                     (* (reg32 *) PWMBL__PS)
/* Data Register */
#define PWMBL_DR                     (* (reg32 *) PWMBL__DR)
/* Input Buffer Disable Override */
#define PWMBL_INP_DIS                (* (reg32 *) PWMBL__PC2)

/* Interrupt configuration Registers */
#define PWMBL_INTCFG                 (* (reg32 *) PWMBL__INTCFG)
#define PWMBL_INTSTAT                (* (reg32 *) PWMBL__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PWMBL_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PWMBL__SIO)
    #define PWMBL_SIO_REG            (* (reg32 *) PWMBL__SIO)
#endif /* (PWMBL__SIO_CFG) */

/* USBIO registers */
#if !defined(PWMBL__PC) && (CY_PSOC4_4200L)
    #define PWMBL_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PWMBL_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PWMBL_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PWMBL_DRIVE_MODE_SHIFT       (0x00u)
#define PWMBL_DRIVE_MODE_MASK        (0x07u << PWMBL_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PWMBL_H */


/* [] END OF FILE */
