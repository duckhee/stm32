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

HW_TIMER_DEF void Hw_Timer_Init(void);
HW_TIMER_DEF void Hw_Timer_Tick(void);
HW_TIMER_DEF void Hw_Timer_Set(uint8_t TimerNum, uint16_t TimerData, void(*Fnct)(void), void *arg);
HW_TIMER_DEF void Hw_Timer_Start(uint8_t TmrNum);
HW_TIMER_DEF void Hw_Timer_Stop(uint8_t TmrNum);
HW_TIMER_DEF void Hw_Timer_Reset(uint8_t TmrNum);
HW_TIMER_DEF void Hw_Timer_Delay_ms(uint16_t DelayData);
HW_TIMER_DEF signed short Hw_Timer_GetHandle(void);
HW_TIMER_DEF unsigned int Hw_Timer_GetCountValue(void);

HW_TIMER_DEF void Hw_Timer_TimeStart(Hw_Timer_InitTypedef* Timer_Init);
HW_TIMER_DEf unsigned int Hw_Timer_TimeGetElapse(Hw_Timer_InitTypedef* Timer_preInit) ;



#endif