#ifndef __HW_FLASH_H__
#define __HW_FLASH_H__

#include "Hw.h"

/*******************  Bit definition for FLASH_ACR register  ******************/
#define  FLASH_ACR_LATENCY                   ((uint8_t)0x03)               /*!< LATENCY[2:0] bits (Latency) */
#define  FLASH_ACR_LATENCY_0                 ((uint8_t)0x00)               /*!< Bit 0 0 < SYSCLK <= 24MHz */
#define  FLASH_ACR_LATENCY_1                 ((uint8_t)0x01)               /*!< Bit 0 24 < SYSCLK <= 48MHz */
#define  FLASH_ACR_LATENCY_2                 ((uint8_t)0x02)               /*!< Bit 1 48 < SYSCLK <= 72MHz */



#ifdef HW_FLASH_LOCAL
#define HW_FLASH_DEF
#else
#define HW_FLASH_DEF                    extern
#endif



#endif