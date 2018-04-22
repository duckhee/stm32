#define HW_SEGMENT_LOCAL

#include "Hw_Segment.h"

SEG_DEF void Power_SEG_On(void);
SEG_DEF void Power_SEG_Off(void);
SEG_DEF void On_7SEG_OnePin(uint16_t PinNum);
SEG_DEF void Off_7SEG_OnePin(uint16_t PinNum);
SEG_DEF void All_7SEG_On(void);
SEG_DEF void All_7SEG_Off(void);
SEG_DEF void Output_7SEG_Number(unsigned int Num);
SEG_DEF void Seven_SEG_TEST(void);