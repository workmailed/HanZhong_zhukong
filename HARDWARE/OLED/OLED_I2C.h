#ifndef __OLED_I2C_H
#define	__OLED_I2C_H

#include "sys.h"

#define OLED_ADDRESS	0x78 //ͨ������0R����,������0x78��0x7A������ַ -- Ĭ��0x78

#define CLK_H  PCout(7) = 1
#define CLK_L  PCout(7) = 0

#define DIO_H  PCout(6) = 1
#define DIO_L  PCout(6) = 0

#define DIO_in  PCin(6)


void I2C_WriteByte(uint8_t data);
void WriteCmd(unsigned char I2C_Command);
void WriteDat(unsigned char I2C_Data);
void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
void OLED_Print(u8 x,u8 y, u8 TextSize,char* fmt,...);
extern unsigned char BMP1[];
#endif