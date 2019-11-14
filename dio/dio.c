/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
/*TODO: include the header file that contains register definitions */
#include "../mcu_hw.h"
#include "dio.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    STD_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Return the Input Channel Value */
    switch (PortId)
    {
    case Dio_Port_A:
        ret = GET_BIT(PORTA_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_B:
        ret = GET_BIT(PORTB_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_C:
        ret = GET_BIT(PORTC_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_D :
        ret = GET_BIT(PORTD_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_E :
        ret = GET_BIT(PORTE_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_F :
        ret = GET_BIT(PORTF_REG.GPIODATA,ChannelPos);
        break;
    }
    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*TODO: Write the input value in the corresponding ChannelId */
    switch (PortId)
    {
    case Dio_Port_A:
        if (STD_low == Level)
        {
            CLR_BIT(PORTA_REG.GPIODATA,ChannelPos);
            break;
        }
        else if (STD_high == Level)
        {
            SET_BIT(PORTA_REG.GPIODATA,ChannelPos);
            break;
        }
    case Dio_Port_B:
        if (STD_low == Level)
        {
            CLR_BIT(PORTB_REG.GPIODATA,ChannelPos);
            break;
        }
        else if (STD_high == Level)
        {
            SET_BIT(PORTB_REG.GPIODATA,ChannelPos);
            break;
        }
    case Dio_Port_C:
        if (STD_low == Level)
        {
            CLR_BIT(PORTC_REG.GPIODATA,ChannelPos);
            break;
        }
        else if (STD_high == Level)
        {
            SET_BIT(PORTC_REG.GPIODATA,ChannelPos);
            break;
        }
    case Dio_Port_D :
        if (STD_low == Level)
        {
            CLR_BIT(PORTD_REG.GPIODATA,ChannelPos);
            break;
        }
        else if (STD_high == Level)
        {
            SET_BIT(PORTD_REG.GPIODATA,ChannelPos);
            break;
        }
    case Dio_Port_E :
        if (STD_low == Level)
        {
            CLR_BIT(PORTE_REG.GPIODATA,ChannelPos);
            break;
        }
        else if (STD_high == Level)
        {
            SET_BIT(PORTE_REG.GPIODATA,ChannelPos);
            break;
        }
    case Dio_Port_F :
        if (STD_low == Level)
        {
            CLR_BIT(PORTF_REG.GPIODATA,ChannelPos);
            break;
        }
        else if (STD_high == Level)
        {
            SET_BIT(PORTF_REG.GPIODATA,ChannelPos);
            break;
        }
    }
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    /*TODO: Return the Port Value*/
    switch (PortId)
    {
    case Dio_Port_A:
        ret = PORTA_REG.GPIODATA;
        break;
    case Dio_Port_B:
        ret = PORTB_REG.GPIODATA;
        break;
    case Dio_Port_C:
        ret = PORTC_REG.GPIODATA;
        break;
    case Dio_Port_D :
        ret = PORTD_REG.GPIODATA;
        break;
    case Dio_Port_E :
        ret = PORTE_REG.GPIODATA;
        break;
    case Dio_Port_F :
        ret = PORTF_REG.GPIODATA;
        break;
    }
    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    /*TODO: Write the input value in the corresponding PortId */
    switch (PortId)
    {
    case Dio_Port_A:
        PORTA_REG.GPIODATA = value;
        break;

    case Dio_Port_B:
        PORTB_REG.GPIODATA = value;
        break;

    case Dio_Port_C:
        PORTC_REG.GPIODATA = value;
        break;

    case Dio_Port_D :
        PORTD_REG.GPIODATA = value;
        break;

    case Dio_Port_E :
        PORTE_REG.GPIODATA = value;
        break;

    case Dio_Port_F :
        PORTF_REG.GPIODATA = value;
        break;
    }


}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    /* TODO: toggle the corresponding ChannelId */
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    switch (PortId)
    {
    case Dio_Port_A:
        TOGGLE_BIT(PORTA_REG.GPIODATA, ChannelPos);
        break;
    case Dio_Port_B:
        TOGGLE_BIT(PORTB_REG.GPIODATA, ChannelPos);
        break;
    case Dio_Port_C:
        TOGGLE_BIT(PORTC_REG.GPIODATA, ChannelPos);
        break;
    case Dio_Port_D:
        TOGGLE_BIT(PORTD_REG.GPIODATA, ChannelPos);
        break;
    case Dio_Port_E:
        TOGGLE_BIT(PORTE_REG.GPIODATA, ChannelPos);
        break;
    case Dio_Port_F:
        TOGGLE_BIT(PORTF_REG.GPIODATA, ChannelPos);
        break;
    }

}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*TODO: toggle the port value */
    switch (PortId)
    {
    case Dio_Port_A:
        PORTA_REG.GPIODATA = ~PORTA_REG.GPIODATA;
        break;
    case Dio_Port_B:
        PORTB_REG.GPIODATA = ~PORTB_REG.GPIODATA;
        break;
    case Dio_Port_C:
        PORTC_REG.GPIODATA = ~PORTC_REG.GPIODATA;
        break;
    case Dio_Port_D:
        PORTD_REG.GPIODATA = ~PORTD_REG.GPIODATA;
        break;
    case Dio_Port_E:
        PORTE_REG.GPIODATA = ~PORTE_REG.GPIODATA;
        break;
    case Dio_Port_F:
        PORTF_REG.GPIODATA = ~PORTF_REG.GPIODATA;
        break;
    }
}



