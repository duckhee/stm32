#ifndef __PRESS_SENSOR_H__
#define __PRESS_SENSOR_H__

#include "Ap.h"


#ifndef PRESS_SENSOR_LOCAL
#define PRESS_SENSOR_DEF
#else
#define PRESS_SENSOR_DEF          extern
#endif

PRESS_SENSOR_DEF void SHT2x_test(void);
PRESS_SENSOR_DEF uint8_t SHT2x_SoftReset(void);
PRESS_SENSOR_DEF uint8_t SHT2x_GetSerialNumber(uint8_t u8SerialNumber[]);
PRESS_SENSOR_DEF uint8_t SHT2x_ReadUserRegister(uint8_t *pRegisterValue);
PRESS_SENSOR_DEF uint8_t SHT2x_WriteUserRegister(uint8_t *pRegisterValue);
PRESS_SENSOR_DEF uint8_t SHT2x_MeasureHM(uint8_t eSHT2xMeasureType, uint8_t* pMeasurand);
PRESS_SENSOR_DEF uint8_t SHT2x_MeasurePoll(uint8_t eSHT2xMeasureType, uint8_t* pMeasurand);
PRESS_SENSOR_DEF float SHT2x_CalcRH(uint8_t* psRH);
PRESS_SENSOR_DEF float SHT2x_CalcTemperatureC(uint8_t* psT);



#endif