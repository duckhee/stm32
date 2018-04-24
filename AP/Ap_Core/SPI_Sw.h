#ifndef __SPI_SW_H__
#define __SPI_SW_H__

#include "Ap.h"

#define SW_SPI_CPHA_VAL = 0;
#define SW_SPI_CPOL_VAL = 0;
#define SW_SPI_WAIT_TIME     100

#ifdef BOARD_DEF_MANGO_Z1
    #define GPIO_RF_SPI          GPIOA
    #define GPIO_RF_RESET        GPIOC
    #define GPIO_RF_VREG_EN      GPIOC
    #define GPIO_RF_GPIO0_4      GPIOC
    #define GPIO_RF_GPIO5        GPIOD
    
    #define GPIO_RF_SPI_NCS_PIN   GPIO_Pin_4
    #define GPIO_RF_SPI_CLK_PIN   GPIO_Pin_5
    #define GPIO_RF_SPI_MISO_PIN  GPIO_Pin_6
    #define GPIO_RF_SPI_MOSI_PIN  GPIO_Pin_7
    
    #define GPIO_RF_RESET_PIN     GPIO_Pin_6
    #define GPIO_RF_VREG_EN_PIN  GPIO_Pin_7

    #define GPIO_RF_GPIO0_PIN     GPIO_Pin_8
    #define GPIO_RF_GPIO1_PIN     GPIO_Pin_9
    #define GPIO_RF_GPIO2_PIN     GPIO_Pin_10
    #define GPIO_RF_GPIO3_PIN     GPIO_Pin_11
    #define GPIO_RF_GPIO4_PIN     GPIO_Pin_12
    #define GPIO_RF_GPIO5_PIN     GPIO_Pin_2
#endif

#ifdef SPI_SW_LOCAL
#define SPI_SW_DEF
#else
#define SPI_SW_DEF                extern
#endif

SPI_SW_DEF void TIMER_Wait_us(__IO uint32_t nCount);
SPI_SW_DEF void SW_SPI_MOSI_H(void);
SPI_SW_DEF void SW_SPI_MOSI_L(void);
SPI_SW_DEF void SW_SPI_CLK_H(void);
SPI_SW_DEF void SW_SPI_CLK_L(void);
SPI_SW_DEF uint8_t SW_SPI_ReadVal_MISO(void);
SPI_SW_DEF void SW_SPI_MOSI_OUT(uint8_t out);
SPI_SW_DEF void SW_SPI_CLK_Init(void);
SPI_SW_DEF void SW_SPI_CLK_Toggle(void);
SPI_SW_DEF unsigned char SW_SPI_TXRX(unsigned char tx_data);



#endif