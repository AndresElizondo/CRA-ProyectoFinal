/*******************************************************************************
* File Name: PWMBH.h  
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

#if !defined(CY_PINS_PWMBH_H) /* Pins PWMBH_H */
#define CY_PINS_PWMBH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMBH_aliases.h"


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
} PWMBH_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PWMBH_Read(void);
void    PWMBH_Write(uint8 value);
uint8   PWMBH_ReadDataReg(void);
#if defined(PWMBH__PC) || (CY_PSOC4_4200L) 
    void    PWMBH_SetDriveMode(uint8 mode);
#endif
void    PWMBH_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMBH_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PWMBH_Sleep(void); 
void PWMBH_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PWMBH__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PWMBH_DRIVE_MODE_BITS        (3)
    #define PWMBH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMBH_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PWMBH_SetDriveMode() function.
         *  @{
         */
        #define PWMBH_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PWMBH_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PWMBH_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PWMBH_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PWMBH_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PWMBH_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PWMBH_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PWMBH_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PWMBH_MASK               PWMBH__MASK
#define PWMBH_SHIFT              PWMBH__SHIFT
#define PWMBH_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMBH_SetInterruptMode() function.
     *  @{
     */
        #define PWMBH_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PWMBH_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PWMBH_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PWMBH_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PWMBH__SIO)
    #define PWMBH_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PWMBH__PC) && (CY_PSOC4_4200L)
    #define PWMBH_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PWMBH_USBIO_DISABLE              ((uint32)(~PWMBH_USBIO_ENABLE))
    #define PWMBH_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PWMBH_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PWMBH_USBIO_ENTER_SLEEP          ((uint32)((1u << PWMBH_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PWMBH_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMBH_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PWMBH_USBIO_SUSPEND_SHIFT)))
    #define PWMBH_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PWMBH_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWMBH_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PWMBH__PC)
    /* Port Configuration */
    #define PWMBH_PC                 (* (reg32 *) PWMBH__PC)
#endif
/* Pin State */
#define PWMBH_PS                     (* (reg32 *) PWMBH__PS)
/* Data Register */
#define PWMBH_DR                     (* (reg32 *) PWMBH__DR)
/* Input Buffer Disable Override */
#define PWMBH_INP_DIS                (* (reg32 *) PWMBH__PC2)

/* Interrupt configuration Registers */
#define PWMBH_INTCFG                 (* (reg32 *) PWMBH__INTCFG)
#define PWMBH_INTSTAT                (* (reg32 *) PWMBH__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PWMBH_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PWMBH__SIO)
    #define PWMBH_SIO_REG            (* (reg32 *) PWMBH__SIO)
#endif /* (PWMBH__SIO_CFG) */

/* USBIO registers */
#if !defined(PWMBH__PC) && (CY_PSOC4_4200L)
    #define PWMBH_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PWMBH_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PWMBH_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PWMBH_DRIVE_MODE_SHIFT       (0x00u)
#define PWMBH_DRIVE_MODE_MASK        (0x07u << PWMBH_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PWMBH_H */


/* [] END OF FILE */
