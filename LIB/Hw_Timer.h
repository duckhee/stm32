#ifndef __HW_TIMER_H__
#define __HW_TIMER_H__

#include "Hw.h"

#ifdef HW_TIMER_LOCAL
#define HW_TIMER_DEF
#else
#define HW_TIMER_DEF         extern
#endif

#ifndef ON
#define ON   1
#endif

#ifndef OFF
#define OFF    0
#endif

#ifndef NULL
#define NULL  0
#endif

#define TIME_MAX     10

#define ONE_TIME    1
#define LOOP_TIME   2

#define TIMER_HANDLE      signed short

typedef struct {
    uint8_t Timer_En;
    uint8_t Timer_Mode;
    uint16_t Timer_Cnt;
    uint16_t Timer_Init;
    void (*TmrFnct)(void);         // 만료될때 실행될 함수
	void *TmrFnctArg;              // 함수로 전달할 인수들
} TMR;

typedef struct {
    uint32_t Start;

}Hw_Timer_InitTypedef;



#endif