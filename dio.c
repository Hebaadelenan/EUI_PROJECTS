/*
 * dio.c
 *
 *  Created on: Oct 15, 2023
 *      Author: DELL
 */
#include "dio.h"


void DIO_Init(uint8 port_no)
{
    set_bit(SYSCTL_RCGCGPIO_R,port_no);
    while(!(get_bit(SYSCTL_RCGCGPIO_R,port_no))){};
    switch(port_no)
    {
    case PORTA:
        GPIO_PORTA_LOCK_R =0x4c4f434b;
        GPIO_PORTA_CR_R  =0xf0;
        break;
    case PORTB:
        GPIO_PORTB_LOCK_R =0x4c4f434b;
        GPIO_PORTB_CR_R  =0xf0;
        break;
    case PORTC:
        GPIO_PORTC_LOCK_R =0x4c4f434b;
        GPIO_PORTC_CR_R  =0xf0;
        break;
    case PORTD:
          GPIO_PORTD_LOCK_R =0x4c4f434b;
          set_bit(GPIO_PORTD_CR_R ,5);
          set_bit(GPIO_PORTD_CR_R ,6);
          set_bit(GPIO_PORTD_CR_R ,7);
        break;
    case PORTE:
        GPIO_PORTE_LOCK_R =0x4c4f434b;
        GPIO_PORTE_CR_R  =0xf0;
        break;
    case PORTF:
        GPIO_PORTF_LOCK_R =0x4c4f434b;
        GPIO_PORTF_CR_R  =0x1f;
        break;
    }
}

void DIO_Configure_Pin(uint8 port_no,uint8 pin_no,GPIO_PinDigitalEN digital,GPIO_PinInternalPullEN pull)
{
    switch(port_no)
    {
    case PORTA:
        if(digital==DIGITAL_ENABLE)
        {
            set_bit(GPIO_PORTA_DEN_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTA_DEN_R,pin_no);
        }
        if(pull==PULL_ENABLE)
        {
            set_bit(GPIO_PORTA_PUR_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTA_PUR_R,pin_no);
        }
        break;
    case PORTB:
        if(digital==DIGITAL_ENABLE)
        {
            set_bit(GPIO_PORTB_DEN_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTB_DEN_R,pin_no);
        }
        if(pull==PULL_ENABLE)
        {
            set_bit(GPIO_PORTB_PUR_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTB_PUR_R,pin_no);
        }
        break;
    case PORTC:
        if(digital==DIGITAL_ENABLE)
        {
            set_bit(GPIO_PORTC_DEN_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTC_DEN_R,pin_no);
        }
        if(pull==PULL_ENABLE)
        {
            set_bit(GPIO_PORTC_PUR_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTC_PUR_R,pin_no);
        }
        break;
    case PORTD:
        if(digital==DIGITAL_ENABLE)
        {
            set_bit(GPIO_PORTD_DEN_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTD_DEN_R,pin_no);
        }
        if(pull==PULL_ENABLE)
        {
            set_bit(GPIO_PORTD_PUR_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTD_PUR_R,pin_no);
        }
        break;
    case PORTE:
        if(digital==DIGITAL_ENABLE)
        {
            set_bit(GPIO_PORTE_DEN_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTE_DEN_R,pin_no);
        }
        if(pull==PULL_ENABLE)
        {
            set_bit(GPIO_PORTE_PUR_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTE_PUR_R,pin_no);
        }
        break;
    case PORTF:
        if(digital==DIGITAL_ENABLE)
        {
            set_bit(GPIO_PORTF_DEN_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTF_DEN_R,pin_no);
        }
        if(pull==PULL_ENABLE)
        {
            set_bit(GPIO_PORTF_PUR_R,pin_no);
        }
        else
        {
            clear_bit(GPIO_PORTF_PUR_R,pin_no);
        }
        break;
    }
}

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType value;
    if(ChannelId >=0 || ChannelId <8)
    {
        value=get_bit(GPIO_PORTA_DATA_R,ChannelId);
    }
    else if(ChannelId >=8 || ChannelId <8*2)
    {
        value=get_bit(GPIO_PORTB_DATA_R,ChannelId);
    }
    else if(ChannelId >=8*2 || ChannelId <8*3)
    {
        value=get_bit(GPIO_PORTC_DATA_R,ChannelId);
    }
    else if(ChannelId >=8*3 || ChannelId <8*4)
    {
        value=get_bit(GPIO_PORTD_DATA_R,ChannelId);
    }
    else if(ChannelId >=8*4 || ChannelId <(8*4+6))
    {
        value=get_bit(GPIO_PORTE_DATA_R,ChannelId);
    }
    else if(ChannelId >=(8*4+6) || ChannelId <(8*5+6))
    {
        value=get_bit(GPIO_PORTF_DATA_R,ChannelId);
    }
    return value;

}

void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    if(ChannelId >=0 || ChannelId <8)
    {
        if(Level==STD_HIGH)
        {
            set_bit(GPIO_PORTA_DATA_R,ChannelId);
        }
        else
        {
            clear_bit(GPIO_PORTA_DATA_R,ChannelId);
        }
    }
    else if(ChannelId >=8 || ChannelId <8*2)
    {
        if(Level==STD_HIGH)
        {
            set_bit(GPIO_PORTB_DATA_R,ChannelId);
        }
        else
        {
            clear_bit(GPIO_PORTB_DATA_R,ChannelId);
        }
    }
    else if(ChannelId >=8*2 || ChannelId <8*3)
    {
        if(Level==STD_HIGH)
        {
            set_bit(GPIO_PORTC_DATA_R,ChannelId);
        }
        else
        {
            clear_bit(GPIO_PORTC_DATA_R,ChannelId);
        }
    }
    else if(ChannelId >=8*3 || ChannelId <8*4)
    {
        if(Level==STD_HIGH)
        {
            set_bit(GPIO_PORTD_DATA_R,ChannelId);
        }
        else
        {
            clear_bit(GPIO_PORTD_DATA_R,ChannelId);
        }
    }
    else if(ChannelId >=8*4 || ChannelId <(8*4+6))
    {
        if(Level==STD_HIGH)
        {
            set_bit(GPIO_PORTE_DATA_R,ChannelId);
        }
        else
        {
            clear_bit(GPIO_PORTE_DATA_R,ChannelId);
        }
    }
    else if(ChannelId >=(8*4+6) || ChannelId <(8*5+6))
    {
        if(Level==STD_HIGH)
        {
            set_bit(GPIO_PORTF_DATA_R,ChannelId);
        }
        else
        {
            clear_bit(GPIO_PORTF_DATA_R,ChannelId);
        }
    }

}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortLevelType value;
    switch(PortId)
        {
        case PORTA:
            value=GPIO_PORTA_DATA_R;
            break;
        case PORTB:
            value=GPIO_PORTB_DATA_R;
            break;
        case PORTC:
            value=GPIO_PORTC_DATA_R;
            break;
        case PORTD:
            value=GPIO_PORTD_DATA_R;
            break;
        case PORTE:
            value=GPIO_PORTE_DATA_R;
            break;
        case PORTF:
            value=GPIO_PORTF_DATA_R;
            break;
        }
    return value;
}

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)
{
    switch(PortId)
     {
     case PORTA:
         GPIO_PORTA_DATA_R=Level;
         break;
     case PORTB:
         GPIO_PORTB_DATA_R=Level;
         break;
     case PORTC:
         GPIO_PORTC_DATA_R=Level;
         break;
     case PORTD:
         GPIO_PORTD_DATA_R=Level;
         break;
     case PORTE:
         GPIO_PORTE_DATA_R=Level;
         break;
     case PORTF:
         GPIO_PORTF_DATA_R=Level;
         break;
     }
}

