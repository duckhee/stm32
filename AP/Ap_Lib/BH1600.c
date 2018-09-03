#define BH1600_LOCAL

#include "BH1600.h"

#define ADC1_DR_Address             ((uint32_t)0x4001244C)

__IO uint32_t Bh1600Value;

BH1600_DEF void BH1600_Init(void);
BH1600_DEF void BH1600_Set_Mode_Shutdown(void);
BH1600_DEF void BH1600_Set_Mode_H_Gain(void);
BH1600_DEF void BH1600_Set_Mode_L_Gain(void);
BH1600_DEF void BH1600_Set_Mode_Test(void);
BH1600_DEF void Get_Light_H_Gain(void);
BH1600_DEF void Get_Light_L_Gain(void);

BH1600_DEF void BH1600_Init(void)
{
    GPIO_InitTypeDef Gpio_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;
    APB2Enable(IOPORT_B_ENABLE, ENABLE);
    APB2Enable(IOPORT_A_ENABLE, ENABLE);
    APB2Enable(AFIO_ENABLE, ENABLE);
    
}

BH1600_DEF void BH1600_Set_Mode_Shutdown(void)
{
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC1_PIN);
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC2_PIN);
}

BH1600_DEF void BH1600_Set_Mode_H_Gain(void)
{
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC1_PIN);
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC2_PIN);
}

BH1600_DEF void BH1600_Set_Mode_L_Gain(void)
{
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC1_PIN);
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC2_PIN);
}
BH1600_DEF void BH1600_Set_Mode_Test(void)
{
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC1_PIN);
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_GC2_PIN);
}

BH1600_DEF void Get_Light_H_Gain(void)
{
    uint16_t Bh1600_Sensor_AD_Data, Board_Detect_AD_Data;

    BH1600_Set_Mode_H_Gain();

    while(1)
    {
        Bh1600_Sensor_AD_Data = (uint16_t)(Bh1600Value >> 16);
        Board_Detect_AD_Data = (uint16_t)(Bh1600Value & 0xFFFF);
        printf("Light Sensor : [ %x ], Board Detect : [ %x ]\n", Bh1600_Sensor_AD_Data, Board_Detect_AD_Data);
        Hw_1_second();
    }
}

BH1600_DEF void Get_Light_L_Gain(void)
{
    uint16_t Bh1600_Sensor_AD_Data, Board_Detect_AD_Data;

    BH1600_Set_Mode_L_Gain();

    while(1)
    {
        Bh1600_Sensor_AD_Data = (uint16_t)(Bh1600Value >> 16);
        Board_Detect_AD_Data = (uint16_t)(Bh1600Value & 0xFFFF);
        printf("Light Sensor : [ %x ], Board Detect : [ %x ]\n", Bh1600_Sensor_AD_Data, Board_Detect_AD_Data);
    }
}