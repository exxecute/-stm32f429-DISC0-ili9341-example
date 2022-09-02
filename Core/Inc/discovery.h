
#ifndef INC_DISCOVERY_H_
#define INC_DISCOVERY_H_

#include "main.h"
#include "defines.h"
#include "stm32f4xx_hal_def.h"

/*-----------------------------------------------------------LCD-----------------------------------------------------------*/
void LCD_IO_Init(void);
void LCD_IO_WriteData(uint16_t RegValue);
void LCD_IO_WriteReg(uint8_t Reg);
uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize);
void LCD_Delay(uint32_t Delay);

/*-----------------------------------------------------------SPI-----------------------------------------------------------*/
void SPIx_MspInit(SPI_HandleTypeDef *hspi);
void SPIx_Write(uint16_t Value);
uint8_t SPIx_WriteRead(uint8_t Byte);
void SPIx_Error(void);
void SPIx_Init(void);
void SPIx_Error(void);
static uint32_t SPIx_Read(uint8_t ReadSize);

#endif /* INC_DISCOVERY_H_ */
