#ifndef __HW_FLASH_H__
#define __HW_FLASH_H__

#include "Hw.h"



#define FLASH_FLAG_BANK1_BSY                 FLASH_FLAG_BSY       /*!< FLASH BANK1 Busy flag*/
#define FLASH_FLAG_BANK1_EOP                 FLASH_FLAG_EOP       /*!< FLASH BANK1 End of Operation flag */
#define FLASH_FLAG_BANK1_PGERR               FLASH_FLAG_PGERR     /*!< FLASH BANK1 Program error flag */
#define FLASH_FLAG_BANK1_WRPRTERR            FLASH_FLAG_WRPRTERR  /*!< FLASH BANK1 Write protected error flag */
/* Flash Control Register bits */
#define FLASH_CR_PG_Set                ((uint32_t)0x00000001)
#define FLASH_CR_PG_Reset              ((uint32_t)0x00001FFE)
#define FLASH_CR_PER_Set               ((uint32_t)0x00000002)
#define FLASH_CR_PER_Reset             ((uint32_t)0x00001FFD)
#define FLASH_CR_MER_Set               ((uint32_t)0x00000004)
#define FLASH_CR_MER_Reset             ((uint32_t)0x00001FFB)
#define FLASH_CR_OPTPG_Set             ((uint32_t)0x00000010)
#define FLASH_CR_OPTPG_Reset           ((uint32_t)0x00001FEF)
#define FLASH_CR_OPTER_Set             ((uint32_t)0x00000020)
#define FLASH_CR_OPTER_Reset           ((uint32_t)0x00001FDF)
#define FLASH_CR_STRT_Set              ((uint32_t)0x00000040)
#define FLASH_CR_LOCK_Set              ((uint32_t)0x00000080)
/*******************  Bit definition for FLASH_ACR register  ******************/
#define  FLASH_ACR_LATENCY                   ((uint8_t)0x03)               /*!< LATENCY[2:0] bits (Latency) */
#define  FLASH_ACR_LATENCY_0                 ((uint8_t)0x00)               /*!< Bit 0 0 < SYSCLK <= 24MHz */
#define  FLASH_ACR_LATENCY_1                 ((uint8_t)0x01)               /*!< Bit 0 24 < SYSCLK <= 48MHz */
#define  FLASH_ACR_LATENCY_2                 ((uint8_t)0x02)               /*!< Bit 1 48 < SYSCLK <= 72MHz */
/* Flash Access Control Register bits */
#define FLASH_ACR_LATENCY_Mask         ((uint32_t)0x00000038)
#define FLASH_ACR_HLFCYA_Mask          ((uint32_t)0xFFFFFFF7)
#define FLASH_ACR_PRFTBE_Mask          ((uint32_t)0xFFFFFFEF)

/** @defgroup Prefetch_Buffer_Enable_Disable
  * @{
  */

#define FLASH_PrefetchBuffer_Enable    ((uint32_t)0x00000010)  /*!< FLASH Prefetch Buffer Enable */
#define FLASH_PrefetchBuffer_Disable   ((uint32_t)0x00000000)  /*!< FLASH Prefetch Buffer Disable */
#define FLASH_FLAG_BSY                 ((uint32_t)0x00000001)  /*!< FLASH Busy flag */
#define FLASH_FLAG_EOP                 ((uint32_t)0x00000020)  /*!< FLASH End of Operation flag */
#define FLASH_FLAG_PGERR               ((uint32_t)0x00000004)  /*!< FLASH Program error flag */
#define FLASH_FLAG_WRPRTERR            ((uint32_t)0x00000010)  /*!< FLASH Write protected error flag */
#define FLASH_FLAG_OPTERR              ((uint32_t)0x00000001)  /*!< FLASH Option Byte error flag */

/* Delay definition */
#define EraseTimeout          ((uint32_t)0x000B0000)
#define ProgramTimeout        ((uint32_t)0x00002000)


#ifdef HW_FLASH_LOCAL
#define HW_FLASH_DEF
#else
#define HW_FLASH_DEF                    extern
#endif

HW_FLASH_DEF FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
HW_FLASH_DEF FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout);
HW_FLASH_DEF FLASH_Status FLASH_GetBank1Status(void);
HW_FLASH_DEF void FLASH_SetLatency(uint32_t FLASH_Latency);


#endif