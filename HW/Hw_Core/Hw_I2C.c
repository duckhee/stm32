#define I2C_LOCAL

#include "Hw_I2C.h"

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

I2_DEF void I2C_DeInit(I2C_TypeDef* I2Cx)
{
    if(I2Cx == I2C1)
    {
        /* Enable I2C1 reset state */
        APB1Enable(RCC_APB1Periph_I2C1, ENABLE);
        /* Release I2C1 from reset state */
        APB1Enable(RCC_APB1Periph_I2C1, DISABLE);
    }
    else
    {
        /* Enable I2C2 reset state */
        APB1Enable(RCC_APB1Periph_I2C2, ENABLE);
        /* Release I2C2 from reset state */
        APB1Enable(RCC_APB1Periph_I2C2, DISABLE);
    }
}

I2_DEF void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct)
{
    uint16_t tmpreg = 0, freqrange = 0;
    uint16_t result = 0x04;
    uint32_t pclk1 = 80000000;
    RCC_ClocksTypeDef rcc_clocks;
    /*---------------------------- I2Cx CR2 Configuration ------------------------*/
  /* Get the I2Cx CR2 value */
  tmpreg = I2Cx -> CR2;
  /* Clear frequency FREQ[5:0] bits */
  tmpreg &= I2C_CR2_FREQ_Reset;
  /* Get pclk1 frequency value */
  RCC_GetClocksFreq(&rcc_clocks);
  pclk1 = rcc_clocks.PCLK1_Frequency;
  /* Set frequency bits depending on pclk1 value */
  pclk1 = (uint16_t)(pclk1/1000000);
  tmpreg |= freqrange;
  /* Write to I2Cx CR2 */
  I2Cx->CR2 = tmpreg;
  /*---------------------------- I2Cx CCR Configuration ------------------------*/
  /* Disable the selected I2C peripheral to configure TRISE */
  I2Cx->CR1 &= I2C_CR1_PE_Reset;
  /* Reset tmpreg value */
  /* Clear F/S, DUTY and CCR[11:0] bits */
  tmpreg = 0;
  /* Configure speed in standard mode */
  if(I2C_InitStruct->I2C_ClockSpeed <= 100000)
  {
      /* Standard mode speed calculate */
      result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed << 1));
      /* Test if CCR value is under 0x4*/
      if(result < 0x04)
      {
          /* Set minimum allowed value */
          result = 0x04;
      }
      /* Set speed value for standard mode */
      tmpreg |= result;
      /* Set Maximum Rise Time for standard mode */
      I2Cx->TRISE = freqrange + 1;
  }
  /* Configure speed in fast mode */
  else /*(I2C_InitStruct->I2C_ClockSpeed <= 400000)*/
  {
      if(I2C_InitStruct->I2C_DutyCycle == I2C_DutyCycle_2)
      {
          /* Fast mode speed calculate: Tlow/Thigh = 2 */
          result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 3));
      }
      else /*I2C_InitStruct->I2C_DutyCycle == I2C_DutyCycle_16_9*/
      {
          /* Fast mode speed calculate: Tlow/Thigh = 16/9 */
          result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 25));
          /* Set DUTY bit */
          result |= I2C_DutyCycle_16_9;
      }
      /* Test if CCR value is under 0x1*/
      if((result & I2C_CCR_CCR_Set) == 0)
      {
          /* Set minimum allowed value */
          result |= (uint16_t)0x0001;
      }
      /* Set speed value and set F/S bit for fast mode */
      tmpreg |= (uint16_t)(result | I2C_CCR_FS_Set);
      /* Set Maximum Rise Time for fast mode */
      I2Cx->TRISE = (uint16_t)(((freqrange * (uint16_t)300) /(uint16_t)1000) + (uint16_t)1);
  }
  /* Write to I2Cx CCR */
  I2Cx->CCR |= tmpreg;
  /* Enable the selected I2C peripheral */
  I2Cx->CR1 |= I2C_CR1_PE_Set;
  /*---------------------------- I2Cx CR1 Configuration ------------------------*/
  /* Get the I2Cx CR1 value */
  tmpreg = I2Cx->CR1;
  /* Clear ACK, SMBTYPE and  SMBUS bits */
  tmpreg &= I2C_CR1_CLEAR_Mask;
  /* Configure I2Cx: mode and acknowledgement */
  /* Set SMBTYPE and SMBUS bits according to I2C_Mode value */
  /* Set ACK bit according to I2C_Ack value */
  tmpreg |= (uint16_t)((uint32_t)I2C_InitStruct->I2C_Mode | I2C_InitStruct->I2C_Ack);
  /* Write to I2Cx CR1 */
  I2Cx->CR1 = tmpreg;
  /*---------------------------- I2Cx OAR1 Configuration -----------------------*/
  /* Set I2Cx Own Address1 and acknowledged address */
  I2Cx->OAR1 = (I2C_InitStruct->I2C_AcknowledgedAddress | I2C_InitStruct->I2C_OwnAddress1);
}

I2_DEF void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct)
{

}

I2_DEF void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
    
}

I2_DEF void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, uint8_t Address)
{

}

I2_DEF void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState)
{

}

I2_DEF void I2C_SendData(I2C_TypeDef* I2Cx, Nuint8_t Data)
{

}

I2_DEF uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx)
{

}

I2_DEF void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction)
{

}

I2_DEF uint16_t I2C_ReadRegister(I2C_TypeDef* I2Cx, uint8_t I2C_Register)
{

}

I2_DEF void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_NACKPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_NACKPosition)
{

}

I2_DEF void I2C_SMBusAlertConfig(I2C_TypeDef* I2Cx, uint16_t I2C_SMBusAlert)
{

}

I2_DEF void I2C_TransmitPEC(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_PECPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_PECPosition)
{

}

I2_DEF void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF uint8_t I2C_GetPEC(I2C_TypeDef* I2Cx)
{

}

I2_DEF void I2C_ARPCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{

}

I2_DEF void I2C_FastModeDutyCycleConfig(I2C_TypeDef* I2Cx, uint16_t I2C_DutyCycle)
{
    
}