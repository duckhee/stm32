#ifndef __HW_NVIC_H__
#define __HW_NVIC_H__

#include "Hw.h"

#define NVIC_VectTab_RAM                  ((uint32_t)0x20000000)
#define NVIC_VectTab_FLASH                ((uint32_t)0x08000000)

#define NVIC_AIRCR_VECTKEY_MASK           ((uint32_t)0x05FA0000)

#define NVIC_PriorityGroup_0              ((uint32_t)0x700)

#define __NVIC_PRIO_BITS              4

/** @defgroup Preemption_Priority_Group 
  * @{
  */

#define NVIC_PriorityGroup_0         ((uint32_t)0x700) /*!< 0 bits for pre-emption priority
  4 bits for subpriority */
#define NVIC_PriorityGroup_1         ((uint32_t)0x600) /*!< 1 bits for pre-emption priority
  3 bits for subpriority */
#define NVIC_PriorityGroup_2         ((uint32_t)0x500) /*!< 2 bits for pre-emption priority
  2 bits for subpriority */
#define NVIC_PriorityGroup_3         ((uint32_t)0x400) /*!< 3 bits for pre-emption priority
  1 bits for subpriority */
#define NVIC_PriorityGroup_4         ((uint32_t)0x300) /*!< 4 bits for pre-emption priority
  0 bits for subpriority */

#ifdef HW_NVIC_LOCAL
#define HW_NVIC_DEF
#else
#define HW_NVIC_DEF                        extern
#endif

HW_NVIC_DEF void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
HW_NVIC_DEF void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
HW_NVIC_DEF void NVIC_Configuration(void);
HW_NVIC_DEF void NVIC_SetPriority(IRQn_TypeDef IRQn, uint32_t priority);
HW_NVIC_DEF void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);


#endif