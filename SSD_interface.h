/******************************************************************************
 *                                                                            *
 *************************  SWC     : SSD_interface   *************************
 *************************  Date    : 25/02/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */

#include "SSD_config.h"
#include "SSD_private.h"


/* Macros for SSD id */
#define SSD_A			1
#define SSD_B		    2


                   /*************** APIS PROTO TYPES ***************/

void SSD_voidInit                    (void);
void SSD_voidDisplayNumber           (u8 copy_u8DesiredNumber, u8 copy_u8Id);
void SSD_voidDisplayMultiplexedNumber(u8 copy_u8DesiredNumber);

#endif /* SSD_INTERFACE_H_ */
