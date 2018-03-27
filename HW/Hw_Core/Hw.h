#ifndef __HW_H__
#define __HW_H__



#include "Ld_printf.h"

#ifdef HW_LOCAL
#define HW_DEF
#else
#define HW_DEF           extern
#endif


HW_DEF void HW_Init(void);

#endif