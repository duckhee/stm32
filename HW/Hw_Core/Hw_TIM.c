#define HW_TIM_LOCAL

#include "Hw_TIM.h"

HW_TIM_DEF void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
HW_TIM_DEF void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
HW_TIM_DEF void TIM_Start_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
HW_TIM_DEF void TIM_Configuration(void);
HW_TIM_DEF void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t prescaler, uint16_t TIM_PscReloadMode);
HW_TIM_DEF void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
HW_TIM_DEF void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);


HW_TIM_DEF void TIM_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    /* TIM2 configuration */
    TIM_TimeBaseStructure.TIM_Period = 0x4AF;          
    TIM_TimeBaseStructure.TIM_Prescaler = 0xEA5F;       
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0x0000;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    /* TIM3 configuration */
    TIM_TimeBaseStructure.TIM_Period = 0x95F;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    /* TIM4 configuration */
    TIM_TimeBaseStructure.TIM_Period = 0xE0F;
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
    /* TIM2 enable counter */
    TIM_Start_Cmd(TIM2, ENABLE);
    /* TIM3 enable counter */
    TIM_Start_Cmd(TIM3, ENABLE);
    /* TIM4 enable counter */
    TIM_Start_Cmd(TIM4, ENABLE);
    /* Immediate load of TIM2 Precaler value */
    TIM_PrescalerConfig(TIM2, 0xEA5F, TIM_PSCReloadMode_Immediate);
    /* Immediate load of TIM3 Precaler value */
    TIM_PrescalerConfig(TIM3, 0xEA5F, TIM_PSCReloadMode_Immediate);
    /* Immediate load of TIM4 Precaler value */
    TIM_PrescalerConfig(TIM4, 0xEA5F, TIM_PSCReloadMode_Immediate);
    /* Clear TIM2 update pending flag */
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    /* Clear TIM3 update pending flag */
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
    /* Clear TIM4 update pending flag */
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);
    /* Enable TIM2 Update interrupt */
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    /* Enable TIM3 Update interrupt */
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    /* Enable TIM4 Update interrupt */
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    
}

HW_TIM_DEF void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT)
{
    /* Clear the IT pending Bit */
    TIMx->SR = (uint16_t)~TIM_IT;
}

HW_TIM_DEF void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
    TIMx->CR1 &= TIM_CR1_CKD_Mask & TIM_CR1_CounterMode_Mask;
    TIMx->CR1 |= (uint32_t)TIM_TimeBaseInitStruct->TIM_ClockDivision | TIM_TimeBaseInitStruct->TIM_CounterMode;
    /* Set the Autoreload value */
    TIMx->ARR = TIM_TimeBaseInitStruct->TIM_Period;
    /* Set the Prescaler value */
    TIMx->PSC = TIM_TimeBaseInitStruct->TIM_Prescaler;
    if ((((uint32_t) TIMx) == TIM1_BASE) || (((uint32_t) TIMx) == TIM8_BASE))
    {
        /* Set the Repetition Counter value */
        TIMx->RCR = TIM_TimeBaseInitStruct->TIM_RepetitionCounter;
    }
    /* Generate an update event to reload the Prescaler value immediatly */
    TIMx->EGR = TIM_PSCReloadMode_Immediate;          

}

HW_TIM_DEF void TIM_Start_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        /* Enable the TIM Counter */
        TIMx->CR1 |= TIM_CR1_CEN_Set;
    }
    else
    {
        /* Disable the TIM Counter */
        TIMx->CR1 &= TIM_CR1_CEN_Reset;
    }
}

HW_TIM_DEF void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t prescaler, uint16_t TIM_PscReloadMode)
{
    /* Set the Prescaler value */
    TIMx->PSC = prescaler;
    /* Set or reset the UG Bit */
    TIMx->EGR = TIM_PscReloadMode;
}

HW_TIM_DEF void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG)
{
    /* Clear the flags */
    TIMx->SR = (uint16_t)~TIM_FLAG;
}

HW_TIM_DEF void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        /* Enable the Interrupt sources */
        TIMx->DIER |= TIM_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        TIMx->DIER &= (uint16_t)~TIM_IT;
    }
}