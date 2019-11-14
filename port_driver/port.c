
/*
 * port.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Mustafa Sayed
 */
#define MAX_NUM_OF_CH_IN_PORT       8

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];

void PORT_init(void)
{
    uint8 i;
    Port_IdType PortId;
    Port_ChIdType ChId;
    volatile PORT_RegType* PORT_Addr;
    for (i = 0; i < PORT_NUM_OF_ACTIVATED_CH; ++i)
    {
        PortId = i/ MAX_NUM_OF_CH_IN_PORT;
        ChId = i % MAX_NUM_OF_CH_IN_PORT;

        switch (PortId)
        {
        case Port_Id_A:
            PORT_Addr = &PORTA_REG;
            break;
        case Port_Id_B:
            PORT_Addr = &PORTB_REG;
            break;
        case Port_Id_C:
            PORT_Addr = &PORTC_REG;
            break;
        case Port_Id_D:
            /*TODO: Assign PORTD address to PORT_Addr variable */   /* Done*/
            PORT_Addr = &PORTD_REG;
            break;
        case Port_Id_E:
            PORT_Addr = &PORTE_REG;
            break;
        case Port_Id_F:
            PORT_Addr = &PORTF_REG;
            break;
        }

        /*TODO: set channel direction */ /* Done*/
        if (port_Dir_Input ==PortCfgArr[i].Dir)
        {
            CLR_BIT(PORT_Addr->GPIODIR, ChId);
        }
        else
        {
            SET_BIT(PORT_Addr->GPIODIR, ChId);
        }

        /*TODO: set channel mode */ /* Done*/

        if (Port_Mode_DIO == PortCfgArr[i].Mode)
        {
            CLR_BIT(PORT_Addr->GPIOAFSEL, ChId);
        }
        else
        {
            SET_BIT(PORT_Addr->GPIOAFSEL, ChId);
            /* Here i just set the alternative functions flag to enable the alternative functions.
             * After this step i will check for all the Port_ModeType Enum and assign a pattern for each mode.
             * I will continue reading alternative functions later on to be able to build the whole
             * infrastructure. As i want to configure all the alternative functions available.*/

        }


        /*TODO: set Interrupt configuration */ /* Done*/
        switch (PortCfgArr[i].Interrupt)
        {
        case Port_IntDisable:
            CLR_BIT(PORT_Addr->GPIOIM, ChId);
            /* Another method to disable interrupts can be achieved by clearing the interrupt in the GPIOICR.
             * To be able to do this, we need to unlock this register first and then set the corresponding channel
             * To unlock the channel, first we need to clear its value in GPIOLOCK register*/
            break;
        case Port_IntFallingEdge:
            SET_BIT(PORT_Addr->GPIOIM, ChId);
            CLR_BIT(PORT_Addr->GPIOIS, ChId);
            CLR_BIT(PORT_Addr->GPIOIBE, ChId);
            SET_BIT(PORT_Addr->GPIOIEV, ChId);
            break;
        case Port_IntRisingEdge:
            SET_BIT(PORT_Addr->GPIOIM, ChId);
            CLR_BIT(PORT_Addr->GPIOIS, ChId);
            CLR_BIT(PORT_Addr->GPIOIBE, ChId);
            CLR_BIT(PORT_Addr->GPIOIEV, ChId);
            break;
        case Port_IntBothEdges:
            SET_BIT(PORT_Addr->GPIOIM, ChId);
            CLR_BIT(PORT_Addr->GPIOIS, ChId);
            SET_BIT(PORT_Addr->GPIOIBE, ChId);
            break;
        }
        /*TODO: set Internal Attachment configuration */ /* Done */
        switch (PortCfgArr[i].AttachedRes)
        {
        case Port_InternalAttach_NA:
            CLR_BIT(PORT_Addr->GPIOODR, ChId);
            CLR_BIT(PORT_Addr->GPIOPDR, ChId);
            CLR_BIT(PORT_Addr->GPIOPUR, ChId);
            break;
        case Port_InternalAttach_PullUpRes:
            SET_BIT(PORT_Addr->GPIOPUR, ChId);
            break;
        case Port_InternalAttach_PullDownRes:
            SET_BIT(PORT_Addr->GPIOPDR, ChId);
            break;
        case Port_InternalAttach_OpenDrain:
            SET_BIT(PORT_Addr->GPIOODR, ChId);
            break;
        }

        /*TODO: set current strength configuration */
        switch (PortCfgArr[i].CurrentDrive)
        {
        case Port_CurrDrive_2mA:
            SET_BIT(PORT_Addr->GPIODR2R, ChId);
            break;
        case Port_CurrDrive_4mA:
            SET_BIT(PORT_Addr->GPIODR4R, ChId);
            break;
        case Port_CurrDrive_8mA:
            SET_BIT(PORT_Addr->GPIODR8R, ChId);
            break;
        }


        /*Check if analog functionality is required*/
        if(PortCfgArr[i].Mode != Port_Mode_AIN )
        {
            /*TODO: enable digital and disable ADC  */
            SET_BIT(PORT_Addr->GPIODEN, ChId);

        }
        else
        {
            /*TODO: disable digital and enable ADC */
            CLR_BIT(PORT_Addr->GPIODEN, ChId);
        }
    }
}
