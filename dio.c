/*
 * dio.c
 *
 *  Created on: Oct 15, 2023
 *      Author: DELL
 */
#include "dio.h"

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
        if(Level=STD_HIGH)
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
        if(Level=STD_HIGH)
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
        if(Level=STD_HIGH)
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
        if(Level=STD_HIGH)
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
        if(Level=STD_HIGH)
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
        if(Level=STD_HIGH)
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
    return value;
}

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)
{

}

