#define BMA150_LOCAL

#include "BMA150.h"


BMA150_DEF void three_axis_acc_sensor_Initialize(void);
BMA150_DEF void three_axis_acc_sensor_test2(void);
BMA150_DEF void three_axis_acc_sensor_test(void);
BMA150_DEF void three_axis_acc_sensor_read_id(void);


BMA150_DEF void three_axis_acc_sensor_Initialize(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    I2C_InitTypeDef I2C_InitStructure;
    APB2Enable(IOPORT_B_ENABLE, ENABLE);
    APB2Enable(AFIO_ENABLE, ENABLE);
    APB1Enable(I2C1_ENABLE, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;

    
}
BMA150_DEF void three_axis_acc_sensor_test2(void);
BMA150_DEF void three_axis_acc_sensor_test(void);
BMA150_DEF void three_axis_acc_sensor_read_id(void);
