
#include "ili9341.h"
#include "fonts.h"

void ili9341_Init(void)
{
  /* Initialize ILI9341 low level bus layer ----------------------------------*/
  LCD_IO_Init();

//  /* Configure LCD */
 ili9341_WriteReg(0x01);				//		software reset
 HAL_Delay(120);						//	delay 120ms
 ili9341_WriteReg(0x28);				//		display off
 ili9341_WriteReg(LCD_POWERB);			//		power control :
 ili9341_WriteData(0x00);				//	-
 ili9341_WriteData(0xC1);				/*	PC and EQ operation for power saving enable
 	  	  	  	  	  	  	  	  	  	  	for VCOM driving ability enhancement
 	  	  	  	  	  	  	  	  	  	  	power control 0b00																				*/
 ili9341_WriteData(0x30);				//	enable high for ESD protection and vice versa
 ili9341_WriteReg(LCD_POWER_SEQ);		//		power on sequence control:
 ili9341_WriteData(0x64);				/*	soft start keep 1 frame
 	  	  	  	  	  	  	  	  	  	  	1st frame enable 																				*/
 ili9341_WriteData(0x03);
 ili9341_WriteData(0x12);
 ili9341_WriteData(0x81);
 ili9341_WriteReg(LCD_DTCA);
 ili9341_WriteData(0x85);
 ili9341_WriteData(0x00);
 ili9341_WriteData(0x78);
 ili9341_WriteReg(LCD_POWERA);
 ili9341_WriteData(0x39);
 ili9341_WriteData(0x2C);
 ili9341_WriteData(0x00);
 ili9341_WriteData(0x34);				//	Vcore 1.6V
 ili9341_WriteData(0x02);				//	DDVDH 5.6V
 ili9341_WriteReg(LCD_PRC);			//		pump ratio control:
 ili9341_WriteData(0x20);				//	DDVDH=2xVCI
 ili9341_WriteReg(LCD_DTCB);			//		driver timing control B:
 ili9341_WriteData(0x00);				//	0 unit
 ili9341_WriteData(0x00);
 ili9341_WriteReg(LCD_FRMCTR1);		//		frame rate control:
 ili9341_WriteData(0x00);				//	division ratio fosc
 ili9341_WriteData(0x1B);				//	70Hz (default)
 ili9341_WriteReg(LCD_DFC);			//		display function control:
 ili9341_WriteData(0x0A);				//	interval scan, set with AGND, AGND, vcom output AGND, AGND
 ili9341_WriteData(0xA2);				/*	liquid crystal type - normally white
 	  	  	  	  	  	  	  	  	  	  	gate output scan direction G1->G320
  	   	   	   	   	   	   	   	   	   	   	source output scan direction S720->S1
  	   	   	   	   	   	   	   	   	   	   	G1->G2->G3->G4->.....->G319->G320
  	   	   	   	   	   	   	   	   	   	   	scan cycle - 5 frames, fFLM = 60Hz - 85ms														*/
 ili9341_WriteReg(LCD_POWER1);			//		power control 1:
 ili9341_WriteData(0x10);				//	GVDD - 3.65V
 ili9341_WriteReg(LCD_POWER2);			//		power control 2:
 ili9341_WriteData(0x10);				//	???????????????????????????????
 ili9341_WriteReg(LCD_VCOM1);			//		VCOM control 1:
 ili9341_WriteData(0x45);				//	VCOMH -  4.425V
 ili9341_WriteData(0x15);				//	VCOML - -1.975V
 ili9341_WriteReg(LCD_VCOM2);			//		VCOM control 2:
 ili9341_WriteData(0x90);				/*	setting of VMF valid and VCOMH/VCOML can be adjusted
  	   	   	   	   	   	   	   	   	   	   	VMH - 48, VML - 48																				*/
 ili9341_WriteReg(LCD_MAC);			//		memory access control:
 ili9341_WriteData(0xC8);				/*	MY - 1, MX - 1, MV - 0, ML - 0, BGR - 1, MH - 0
 	  	  	  	  	  	  	  	  	  		normal vertical refresh
 	  	  	  	  	  	  	  	  	  		normal vertical send
 	  	  	  	  	  	  	  	  	  		RGB-BGR order control enable
 	  	  	  	  	  	  	  	  	  		normal horizontal send																			*/
 ili9341_WriteReg(LCD_3GAMMA_EN);		//		3 gamma control:
 ili9341_WriteData(0x00);				//	disable 3 gamma control
 ili9341_WriteReg(LCD_RGB_INTERFACE);	//		RGB interface signal control:
 ili9341_WriteData(0xC2);				/*	ByPass_MODE - 1, RCM - 10, VSPL - 0, HSPL - 0, DPL - 1, EPL - 0
 	  	  	  	  	  	  	  	  	  	    memory is display data path when RGB interface is used
 	  	  	  	  	  	  	  	  	  	    VSYNC polarity low level sync clock
 	  	  	  	  	  	  	  	  	  	    HSYNC polarity low level sync clock
 	  	  	  	  	  	  	  	  	  	    DOTCLK polarity data fetched at the falling time
 	  	  	  	  	  	  	  	  	  	    DE polarity hugh enable for RG interface														*/
 ili9341_WriteReg(LCD_DFC);			//		display function control:
 ili9341_WriteData(0x0A);				//	interval scan, set with AGND, AGND, vcom output AGND, AGND
 ili9341_WriteData(0xA7);				/*	REV - 1, GS - 0, SS - 1, SM - 0, ISC - 0111
 	  	  	  	  	  	  	  	  	  	  	liquid crystal type normally white
 	  	  	  	  	  	  	  	  	  	  	gate output scan direction G1->G320
 	  	  	  	  	  	  	  	  	  	  	source output scan direction S720->S1
 	  	  	  	  	  	  	  	  	  	  	G1->G2->G3->G4->.....->G319->G320
 	  	  	  	  	  	  	  	  	  	  	scan cycle -> 15 frames, fFLM = 60Hz - 255ms													*/
 ili9341_WriteData(0x27);				//	LCD driver line 192 lines
 ili9341_WriteData(0x04);
 ili9341_WriteReg(LCD_COLUMN_ADDR);	/* Colomn address set 																				*/
 ili9341_WriteData(0x00);
 ili9341_WriteData(0x00);
 ili9341_WriteData(0x00);
 ili9341_WriteData(0xEF);
 ili9341_WriteReg(LCD_PAGE_ADDR);		/* Page address set 																				*/
 ili9341_WriteData(0x00);
 ili9341_WriteData(0x00);
 ili9341_WriteData(0x01);
 ili9341_WriteData(0x3F);
 ili9341_WriteReg(LCD_GRAM);
 LCD_Delay(200);
 ili9341_WriteReg(LCD_GAMMA);
 ili9341_WriteData(0x01);
 ili9341_WriteReg(LCD_PGAMMA);
 ili9341_WriteData(0x0F);
 ili9341_WriteData(0x29);
 ili9341_WriteData(0x24);
 ili9341_WriteData(0x0C);
 ili9341_WriteData(0x0E);
 ili9341_WriteData(0x09);
 ili9341_WriteData(0x4E);
 ili9341_WriteData(0x78);
 ili9341_WriteData(0x3C);
 ili9341_WriteData(0x09);
 ili9341_WriteData(0x13);
 ili9341_WriteData(0x05);
 ili9341_WriteData(0x17);
 ili9341_WriteData(0x11);
 ili9341_WriteData(0x00);
 ili9341_WriteReg(LCD_NGAMMA);
 ili9341_WriteData(0x00);
 ili9341_WriteData(0x16);
 ili9341_WriteData(0x1B);
 ili9341_WriteData(0x04);
 ili9341_WriteData(0x11);
 ili9341_WriteData(0x07);
 ili9341_WriteData(0x31);
 ili9341_WriteData(0x33);
 ili9341_WriteData(0x42);
 ili9341_WriteData(0x05);
 ili9341_WriteData(0x0C);
 ili9341_WriteData(0x0A);
 ili9341_WriteData(0x28);
 ili9341_WriteData(0x2F);
 ili9341_WriteData(0x0F);

 LCD_Delay(100);
 ili9341_WriteReg(LCD_SLEEP_OUT);
 LCD_Delay(200);
 ili9341_WriteReg(LCD_DISPLAY_ON);
}

uint16_t ili9341_ReadID(void)
{
  LCD_IO_Init();
  return ((uint16_t)ili9341_ReadData(LCD_READ_ID4, LCD_READ_ID4_SIZE));
}

void ili9341_DisplayOn(void)
{
  /* Display On */
  ili9341_WriteReg(LCD_DISPLAY_ON);
}

void ili9341_DisplayOff(void)
{
  /* Display Off */
  ili9341_WriteReg(LCD_DISPLAY_OFF);
}

void ili9341_WriteReg(uint8_t LCD_Reg)
{
  LCD_IO_WriteReg(LCD_Reg);
}

void ili9341_WriteData(uint16_t RegValue)
{
  LCD_IO_WriteData(RegValue);
}

void ili9341_WriteData16(uint16_t RegValue) {
	LCD_IO_WriteData(RegValue >> 8);
	LCD_IO_WriteData(RegValue & 0xff);
}

uint32_t ili9341_ReadData(uint16_t RegValue, uint8_t ReadSize)
{
  /* Read a max of 4 bytes */
  return (LCD_IO_ReadData(RegValue, ReadSize));
}

uint16_t ili9341_GetLcdPixelWidth(void)
{
  /* Return LCD PIXEL WIDTH */
  return ILI9341_LCD_PIXEL_WIDTH;
}

uint16_t ili9341_GetLcdPixelHeight(void)
{
  /* Return LCD PIXEL HEIGHT */
  return ILI9341_LCD_PIXEL_HEIGHT;
}

// setting cursur for drawing 
void ili9341_SetCursor(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
	ili9341_WriteReg(LCD_COLUMN_ADDR);
	ili9341_WriteData(0);
	ili9341_WriteData(x1);
	ili9341_WriteData(0);
	ili9341_WriteData(x2);
	ili9341_WriteReg(LCD_PAGE_ADDR);
	ili9341_WriteData(0);
	ili9341_WriteData(y1);
	ili9341_WriteData(0);
	ili9341_WriteData(y2);
}

// drawing one pixel
void ili9341_DrawPixel(uint16_t x, uint16_t y, uint16_t colour) {
	ili9341_SetCursor(x, y, x + 1, y + 1);
	ili9341_WriteReg(LCD_GRAM);
	ili9341_WriteData16(colour);
}

//writing char using 2 dimential font list
void ili9341_WriteChar(uint16_t x, uint16_t y, uint16_t colour_text, uint16_t colour_bg, char *text, uint16_t Font) {
	font *sfont = Font_GetFont(Font);
	uint16_t LetterX = x;
	uint16_t LetterY = y;
	uint16_t index = 0;
	while(text[index] != 0) {
		ili9341_SetCursor(LetterX, LetterY, LetterX + sfont-> width, LetterY + sfont -> height);
		ili9341_WriteReg(LCD_GRAM);
		for(int height = 0; height < sfont->height; height++) {
			uint8_t Page = Font_GetPage(Font, text[index], height);
				for(int width = 0; width < sfont->width + 1; width++) {
					switch( (Page>> (sfont->width - width)) & 1 ) {
					case 0:
						ili9341_WriteData16(colour_bg);
						break;
					case 1:
						ili9341_WriteData16(colour_text);
						break;
					}
				}

		}
		LetterX += sfont->width + 1;
		index++;
	}
}

//writing char using 1 dimential font list
void ili9341_WriteChar2(uint16_t x, uint16_t y, uint16_t colour_text, uint16_t colour_bg, char *text, uint16_t Font) {
	font *sfont = Font_GetFont(Font);
	uint16_t LetterX = x;
	uint16_t LetterY = y;
	uint16_t index = 0;
	while(text[index] != 0) {
		ili9341_SetCursor(LetterX, LetterY, LetterX + sfont->width, LetterY + sfont->height);
		ili9341_WriteReg(LCD_GRAM);
		for(int height = 0; height < sfont->height; height++) {
			for(int width = 0; width < sfont->width + 1; width++) {
				switch(( sfont->ascii[((text[index] - 32) * sfont->height) + height] >> (sfont->width - width)) & 1 ) {
				case 0:
					ili9341_WriteData16(colour_bg);
					break;
				case 1:
					ili9341_WriteData16(colour_text);
					break;
				}
			}
		}
		LetterX += sfont->width + 1;
		index++;
	}
}

//drawing cube
void ili9341_DrawCube(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour) {
	ili9341_SetCursor(x1, y1, x2, y2);
	ili9341_WriteReg(LCD_GRAM);
	for(int i = 0; i < (x2 - x1) * (y2 - y1); i++) {
		ili9341_WriteData16(colour);
	}
}

//example drawing
void ili9341_MainDraw(void) {
	ili9341_DrawTriangle(10, 10, 20, 20, 10, 30, ILI9341_COLOR_RED);
	ili9341_DrawTriangle(30, 30, 100, 40, 50, 100, ILI9341_COLOR_YELLOW);
	ili9341_DrawTriangle(120, 40, 230, 190, 100, 100, ILI9341_COLOR_GREEN);
	ili9341_DrawTriangle(150, 10, 220, 50, 200, 100, ILI9341_COLOR_BLUE);
	Pixel_circle(30, 30, 10, 10, ILI9341_COLOR_YELLOW);

	HAL_Delay(10000);
	ili9341_WriteChar(0, 00, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFG", FONT8);
	ili9341_WriteChar(0, 10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, "HIJKLMNOPQRSTUVWXYZ", FONT8);
	ili9341_WriteChar(0, 22, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, " !$%&'()* !$%&'()* !$%&'()*", FONT12);
	ili9341_WriteChar2(0, 40, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE, " !# !#  !////////", FONT7);
	HAL_Delay(10000);
	ili9341_WriteChar(0,   0, ILI9341_COLOR_WHITE,   ILI9341_COLOR_BLACK, "WHITEWHITEWHITEWHITEWHITEWHITEWHITEWHITE", FONT8);
	ili9341_WriteChar(0,  10, ILI9341_COLOR_BLACK,   ILI9341_COLOR_WHITE, "BLACKBLACKBLACKBLACKBLACKBLACKBLACKBLACK", FONT8);
	ili9341_WriteChar(0,  20, ILI9341_COLOR_RED,     ILI9341_COLOR_WHITE, "REDREDREDREDREDREDREDREDREDREDREDREDREDR", FONT8);
	ili9341_WriteChar(0,  30, ILI9341_COLOR_GREEN,   ILI9341_COLOR_WHITE, "GREENGREENGREENGREENGREENGREENGREENGREEN", FONT8);
	ili9341_WriteChar(0,  40, ILI9341_COLOR_GREEN2,  ILI9341_COLOR_WHITE, "GREEN2GREEN2GREEN2GREEN2GREEN2GREEN2GREE", FONT8);
	ili9341_WriteChar(0,  50, ILI9341_COLOR_BLUE,    ILI9341_COLOR_WHITE, "BLUEBLUEBLUEBLUEBLUEBLUEBLUEBLUEBLUEBLUE", FONT8);
	ili9341_WriteChar(0,  60, ILI9341_COLOR_BLUE2,   ILI9341_COLOR_WHITE, "BLUE2BLUE2BLUE2BLUE2BLUE2BLUE2BLUE2BLUE2", FONT8);
	ili9341_WriteChar(0,  70, ILI9341_COLOR_YELLOW,  ILI9341_COLOR_BLACK, "YELLOWYELLOWYELLOWYELLOWYELLOWYELLOWYELL", FONT8);
	ili9341_WriteChar(0,  80, ILI9341_COLOR_ORANGE,  ILI9341_COLOR_WHITE, "ORANGEORANGEORANGEORANGEORANGEORANGEORAN", FONT8);
	ili9341_WriteChar(0,  90, ILI9341_COLOR_CYAN,    ILI9341_COLOR_BLACK, "CYANCYANCYANCYANCYANCYANCYANCYANCYANCYAN", FONT8);
	ili9341_WriteChar(0, 100, ILI9341_COLOR_MAGENTA, ILI9341_COLOR_WHITE, "MAGENTAMAGENTAMAGENTAMAGENTAMAGENTAMAGEN", FONT8);
	ili9341_WriteChar(0, 110, ILI9341_COLOR_GRAY,    ILI9341_COLOR_WHITE, "GRAYGRAYGRAYGRAYGRAYGRAYGRAYGRAYGRAYGRAY", FONT8);
	ili9341_WriteChar(0, 120, ILI9341_COLOR_BROWN,   ILI9341_COLOR_WHITE, "BROWNBROWNBROWNBROWNBROWNBROWNBROWNBROWN", FONT8);
	HAL_Delay(10000);
	ili9341_Print(1365);
	HAL_Delay(1000);
	for(uint16_t rgb = 0; rgb < 0xffff; rgb+= 113) {
		static uint8_t pg = 0;
		static uint8_t cl = 0;
		ili9341_DrawChank(cl, pg, rgb);
		cl+= 1;
		if (cl == 24) { cl = 0; pg+= 1;}
		if (pg == 24) { pg = 0; }
	}
}

//drawing one chunk of display
void ili9341_DrawChank(uint16_t chankX, uint16_t chankY, uint16_t color) {
	ili9341_DrawCube(chankX * 10, chankY * 10, ((chankX + 1) * 10) + 1, ((chankY + 1) * 10) + 1, color);
}

//random drawing chunks
void ili9341_Print(uint16_t seed) {
	for(int i = 0; i < 24; i++) {
		for (int j = 0; j < 24; j++) {
			ili9341_DrawChank(j, i, (j + i) * seed);
		}
	}
}

//drawing line
void ili9341_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t colour) {
	int x = x1-x0;
	int y = y1-y0;
	int dx = abs(x), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y), sy = y0<y1 ? 1 : -1;
	int err = dx+dy, e2;
	for (;;){
		ili9341_DrawPixel(x0, y0, colour);
		e2 = 2*err;
		if (e2 >= dy) {
			if (x0 == x1) break;
			err += dy; x0 += sx;
		}
		if (e2 <= dx) {
			if (y0 == y1) break;
			err += dx; y0 += sy;
		}
	}
}

//drawing triangle
void ili9341_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t colour) {
	ili9341_DrawLine(x1, y1, x2, y2, colour);
	ili9341_DrawLine(x2, y2, x3, y3, colour);
	ili9341_DrawLine(x3, y3, x1, y1, colour);
}
