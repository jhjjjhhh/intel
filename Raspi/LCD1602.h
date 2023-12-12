#define LCD1602_H

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>

#define I2C_ADDR  0x3f
#define LCD_CHR   1
#define LCD_CMD   0
#define LINE1  0x80
#define LINE2  0xC0
#define LCD_BACKLIGHT   0x08
#define ENABLE 0x04

extern int xio;

void lcd_init(void);
void lcd_byte(int bits, int mode);
void lcd_toggle_enable(int bits);
void typeInt(int i);
void typeFloat(float myFloat);
void lcdLoc(int line);
void lcdClear(void);
void typeChar(char val);
void typeIn(const char* s);
