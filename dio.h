/*
 * dio.h
 *
 *  Created on: Oct 15, 2023
 *      Author: DELL
 */

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "bitwise_operation.h"
#include "hw_gpio.h"

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;


#define  PORTA 0
#define  PORTB 1
#define  PORTC 2
#define  PORTD 3
#define  PORTE 4
#define  PORTF 5



typedef enum{
   PULL_DISABLE,PULL_ENABLE
}GPIO_PinInternalPullEN;

typedef enum{
   DIGITAL_DISABLE,DIGITAL_ENABLE
}GPIO_PinDigitalEN;


#endif /* DIO_H_ */
