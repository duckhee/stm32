#define DHT11_LOCAL

#include "DHT11.h"


#define BITMAX     45

DHT11_DEF void DHT11_Init(void);
DHT11_DEF void DHT11_Start(void);
DHT11_DEF void DHT11_Stop(void);

DHT11_DEF uint8_t DHT11_GetHumidity(void);
DHT11_DEF uint8_t DHT11_GetTemperature(void);

void Hw_DHT11_Timer_Setup(void);
void Hw_DHT11_IO_Setup(void);
void Hw_DHT11_IO_SetupISR(void);
void Hw_DHT11_IO_SetOutput(void);
void Hw_DHT11_IO_SetInput(void);
void Hw_DHT11_IO_SetHigh(void);
void Hw_DHT11_IO_SetLow(void);
uint8_t Hw_DHT11_IO_Get(void);

void Hw_DHT11_IO_EnableISR(void);
void Hw_DHT11_IO_DisableISR(void);


DHT11_InitTypedef DHT11_Struct;

uint32_t DHT11_BitIndex = 0;
uint16_t DHT11_BitTbl[BITMAX];


DHT11_DEF void DHT11_Init(void)
{
    for(int i = 0; i < MAX; i++)
    {
        DHT11_Struct.Data[i] = 0;
    }
    DHT11_Struct.Error = 0;
    DHT11_Struct.DataValid = false;
    DHT11_Struct.Humidity = 0;
    DHT11_Struct.Temperature = 0;
}

DHT11_DEF void DHT11_Start(void);
DHT11_DEF void DHT11_Stop(void);
DHT11_DEF uint8_t DHT11_GetHumidity(void);
DHT11_DEF uint8_t DHT11_GetTemperature(void);

void Hw_DHT11_Timer_Setup(void);
void Hw_DHT11_IO_Setup(void);
void Hw_DHT11_IO_SetupISR(void);
void Hw_DHT11_IO_SetOutput(void);
void Hw_DHT11_IO_SetInput(void);
void Hw_DHT11_IO_SetHigh(void);
void Hw_DHT11_IO_SetLow(void);
uint8_t Hw_DHT11_IO_Get(void);
void Hw_DHT11_IO_EnableISR(void);
void Hw_DHT11_IO_DisableISR(void);

