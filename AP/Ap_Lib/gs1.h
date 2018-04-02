#ifndef __GS1_H__
#define __GS1_H__

#include "Ap.h"

#ifdef GS1_LOCAL
#define GS1_DEF
#else
#define GS1_DEF                  extern
#endif

GS1_DEF void Gs_Init(void);


#endif