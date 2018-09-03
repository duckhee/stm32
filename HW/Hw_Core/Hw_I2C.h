#ifndef __I2C_H__
#define __I2C_H__

#include "Hw.h"

#define RCC_APB1Periph_I2C1              ((uint32_t)0x00200000)
#define RCC_APB1Periph_I2C2              ((uint32_t)0x00400000)
/* I2C SPE mask */
#define I2C_CR1_PE_Set                   ((uint16_t)0x0001)
#define I2C_CR1_PE_Reset                 ((uint16_t)0xFFFE)
/* I2C FREQ mask */
#define I2C_CR2_FREQ_Reset               ((uint16_t)0xFFC0)
#define I2C_DutyCycle_16_9               ((uint16_t)0x4000) /*!< I2C fast mode Tlow/Thigh = 16/9 */
#define I2C_DutyCycle_2                  ((uint16_t)0xBFFF) /*!< I2C fast mode Tlow/Thigh = 2 */
/* I2C CCR mask */
#define I2C_CCR_CCR_Set                  ((uint16_t)0x0FFF)
/* I2C F/S mask */
#define I2C_CCR_FS_Set                   ((uint16_t)0x8000)
/* I2C registers Masks */
#define I2C_CR1_CLEAR_Mask               ((uint16_t)0xFBF5)


#ifdef I2C_LOCAL
#define I2C_DEF
#else
#define I2_DEF            extern
#endif

I2_DEF void I2C_DeInit(I2C_TypeDef* I2Cx);
I2_DEF void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
I2_DEF void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
I2_DEF void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, uint8_t Address);
I2_DEF void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState);
I2_DEF void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data);
I2_DEF uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx);
I2_DEF void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction);
I2_DEF uint16_t I2C_ReadRegister(I2C_TypeDef* I2Cx, uint8_t I2C_Register);
I2_DEF void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_NACKPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_NACKPosition);
I2_DEF void I2C_SMBusAlertConfig(I2C_TypeDef* I2Cx, uint16_t I2C_SMBusAlert);
I2_DEF void I2C_TransmitPEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_PECPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_PECPosition);
I2_DEF void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF uint8_t I2C_GetPEC(I2C_TypeDef* I2Cx);
I2_DEF void I2C_ARPCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
I2_DEF void I2C_FastModeDutyCycleConfig(I2C_TypeDef* I2Cx, uint16_t I2C_DutyCycle);



#endif