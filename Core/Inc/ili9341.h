#ifndef INC_ILI9341_H_
#define INC_ILI9341_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include "main.h"
#include "defines.h"
#include "discovery.h"
#include "fonts.h"

void ili9341_Init(void);
uint16_t ili9341_ReadID(void);
void ili9341_DisplayOn(void);
void ili9341_DisplayOff(void);
void ili9341_WriteReg(uint8_t LCD_Reg);
void ili9341_WriteData(uint16_t RegValue);
void ili9341_WriteData16(uint16_t RegValue);
uint32_t ili9341_ReadData(uint16_t RegValue, uint8_t ReadSize);
uint16_t ili9341_GetLcdPixelWidth(void);
uint16_t ili9341_GetLcdPixelHeight(void);
void ili9341_SetCursor(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void ili9341_DrawPixel(uint16_t x, uint16_t y, uint16_t colour);
void ili9341_FillAll(void);
void ili9341_WriteChar(uint16_t x, uint16_t y, uint16_t colour_text, uint16_t colour_bg, char *text, uint16_t sfont);
void ili9341_DrawCube(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour);
void ili9341_MainDraw(void);
void ili9341_DrawChank(uint16_t chankX, uint16_t chankY, uint16_t color);
void ili9341_Print(uint16_t seed);
void ili9341_Picture(uint32_t pic, uint16_t XChank);
void ili9341_WriteChar2(uint16_t x, uint16_t y, uint16_t colour_text, uint16_t colour_bg, char *text, uint16_t Font);
void ili9341_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour);
void ili9341_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t colour) ;
void ili9341_DrawCircle(uint16_t x, uint16_t y, uint16_t radius, uint16_t colour);

#ifdef __cplusplus
}
#endif

#endif /* INC_ILI9341_H_ */
