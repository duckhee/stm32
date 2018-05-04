#ifndef __DHT11_H__
#define __DHT11_H__


#include "Ap.h"



#ifdef DHT11_LOCAL
#define DHT11_DEF
#else
#define DHT11_DEF            extern
#endif

#define MAX     5

typedef struct {
    uint8_t Data[MAX];
    uint8_t Error;
    uint8_t DataValid;
    uint8_t Humidity;
    uint8_t Temperature;
}DHT11_InitTypedef;

DHT11_DEF void DHT11_Init(void);
DHT11_DEF void DHT11_Start(void);
DHT11_DEF void DHT11_Stop(void);

DHT11_DEF uint8_t DHT11_GetHumidity(void);
DHT11_DEF uint8_t DHT11_GetTemperature(void);

#endif