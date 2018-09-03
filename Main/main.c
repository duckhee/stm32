#include "main.h"

#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

PUTCHAR_PROTOTYPE
{
        /* Write a character to the USART */  
    if( ch == '\n') {
        USART_SendData(USART1, '\r');
        while(USART_GetFlagStatus(USART1, ((uint16_t)0x0080)) == RESET);
        USART_SendData(USART1, '\n');
    }else {
        USART_SendData(USART1, (uint8_t)ch);
    }

    /* Loop until the end of transmission */
    while(USART_GetFlagStatus(USART1, ((uint16_t)0x0080)) == RESET);

    return ch;
}

RCC_ClocksTypeDef rcc_clocks;

int main(void)
{
    HW_Init();
    RCC_GetClocksFreq(&rcc_clocks);
    System_Information();
    // Key_Test();
    // Test_LED();
    //command_main();

}