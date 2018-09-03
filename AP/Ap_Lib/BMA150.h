#ifndef __BMA150_H__
#define __BMA150_H__

#include "Ap.h"

#define GPIO_SW_SPI                      GPIOA
#define GPIO_SW_SPI_NCS_PIN              GPIO_Pin_4
#define GPIO_SW_SPI_CLK_PIN              GPIO_Pin_5
#define GPIO_SW_SPI_MISO_PIN             GPIO_Pin_6
#define GPIO_SW_SPI_MISI_PIN             GPIO_Pin_7

#ifdef BMA150_LOCAL
#define BMA150_DEF
#else
#define BMA150_DEF         extern
#endif


BMA150_DEF void three_axis_acc_sensor_Initialize(void);
BMA150_DEF void three_axis_acc_sensor_test2(void);
BMA150_DEF void three_axis_acc_sensor_test(void);
BMA150_DEF void three_axis_acc_sensor_read_id(void);


#endif