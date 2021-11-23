/*Buzzer Definition*/
#ifndef _BUZ_H
#define _BUZ_H

#include	"includes.h"

#define	BUZ_DDR						DDRC
#define	BUZ_PORT					PORTC
#define	BUZ_PIN						PC1

#define	buzon()			BUZ_PORT |= _BV(BUZ_PIN)
#define	buzoff()		BUZ_PORT &= ~_BV(BUZ_PIN)

void beep		(int8u nbeep, int16u ontime);
void buzinit	(void);

#endif

/*Delay definition*/
#ifndef DELAY_H
#define DELAY_H

#include "includes.h"
void dlyms(int16u dly);
void dlyus(int16u dly);

#endif

/*GPS Definition*/
#ifndef GPS_H
#define GPS_H

#include "includes.h"

void GPSInit	(void);
void GPSgetloc	(int8u *Lat, int8u *Lon);

#endif

/*LCD Definition*/
#ifndef LCD_H
#define LCD_H

#include "includes.h"

#define OUTPUT 		 0xFF
#define LCD_DOT		'.'
#define LCD_SPC		' '

void lcdwc			(int8u command);
void lcdwd			(char ch);
void lcdws			(char *s);
void lcdinit		(void);
void lcddinit		(void);
void lcdclrr		(int8u rowno);
void lcdclr			(void);
void lcdr1			(void);
void lcdr2			(void);
void itoa			(signed int n, char s[]);
void reverse		(char s[]);
void lcdwint		(int8u loc,signed int x);
void lcdwlng		(int8u loc,unsigned long x);
void ltoa			(unsigned long n, char s[]);
double atof			(char *s);
void lcdclrr		(int8u rowno);
void lcdscrolinit	(void);

#if defined FLOAT_T0_STRING > 0

void ftoa(float n, char *res, int afterpoint);
int intToStr(int x, char str[], int d);
void rever(char *str, int len);
#endif
