#define SPI_SW_LOCAL

#include "SPI_Sw.h"


SPI_SW_DEF void TIMER_Wait_us(__IO uint32_t nCount);
SPI_SW_DEF void SW_SPI_MOSI_H(void);
SPI_SW_DEF void SW_SPI_MOSI_L(void);
SPI_SW_DEF void SW_SPI_CLK_H(void);
SPI_SW_DEF void SW_SPI_CLK_L(void);
SPI_SW_DEF uint8_t SW_SPI_ReadVal_MISO(void);
SPI_SW_DEF void SW_SPI_MOSI_OUT(uint8_t out);
SPI_SW_DEF void SW_SPI_CLK_Init(void);
SPI_SW_DEF void SW_SPI_CLK_Toggle(void);
SPI_SW_DEF uint8_t SW_SPI_TXRX(uint8_t tx_data);

SPI_SW_DEF void TIMER_Wait_us(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount --);
}

SPI_SW_DEF void SW_SPI_MOSI_H(void)
{
    GPIO_SetBits(GPIO_RF_SPI, GPIO_RF_SPI_MOSI_PIN);
}

SPI_SW_DEF void SW_SPI_MOSI_L(void)
{
    GPIO_ResetBits(GPIO_RF_SPI, GPIO_RF_SPI_MOSI_PIN);
}

SPI_SW_DEF void SW_SPI_CLK_H(void)
{
    GPIO_SetBits(GPIO_RF_SPI, GPIO_RF_SPI_CLK_PIN);
}

SPI_SW_DEF void SW_SPI_CLK_L(void)
{
    GPIO_ResetBits(GPIO_RF_SPI, GPIO_RF_SPI_CLK_PIN);
}

SPI_SW_DEF uint8_t SW_SPI_ReadVal_MISO(void)
{
    return GPIO_ReadInputDataBit(GPIO_RF_SPI, GPIO_RF_SPI_MISO_PIN);
}

SPI_SW_DEF void SW_SPI_MOSI_OUT(uint8_t out)
{
    if(out)
    {
        SW_SPI_MOSI_H();
    }
    else
    {
        SW_SPI_MOSI_L();
    }
    TIMER_Wait_us(SW_SPI_WAIT_TIME);
}

SPI_SW_DEF void SW_SPI_CLK_Init(void)
{
    if(0 == SW_SPI_CPOL_VAL)
    {
        SW_SPI_CLK_L();
    }
    else
    {
        SW_SPI_CLK_H();
    }
    TIMER_Wait_us(SW_SPI_WAIT_TIME);
}

SPI_SW_DEF void SW_SPI_CLK_Toggle(void)
{
    GPIO_WriteBit(GPIO_RF_SPI, GPIO_RF_SPI_CLK_PIN, (BitAction)(1-GPIO_ReadOutputDataBit(GPIO_RF_SPI, GPIO_RF_SPI_CLK_PIN)));
    TIMER_Wait_us(SW_SPI_WAIT_TIME);
}

SPI_SW_DEF unsigned char SW_SPI_TXRX(unsigned char tx_data)
{
    unsigned char rx_data = 0;

    unsigned long i;
    unsigned char bitCheckVal = 0x80;

    if(1 == SW_SPI_CPHA_VAL)
    {
        SW_SPI_CLK_Toggle();
    }
    for(i = 0; i < 8; i++)
    {
        SW_SPI_MOSI_OUT(tx_data & bitCheckVal);
        bitCheckVal >>= 1;

        SW_SPI_CLK_Toggle();

        rx_data <<= 1;
        if(SW_SPI_ReadVal_MISO() == Bit_SET)
        {
            rx_data |= 0x1;
        }
        if((7 == i) && (1 == SW_SPI_CPHA_VAL))
        {
            //In last loop, if CPHA is 1, should skip CLK Toggle....
            break;
        }
        SW_SPI_CLK_Toggle();
    }
    TIMER_Wait_us(SW_SPI_WAIT_TIME);

    return rx_data;
}
