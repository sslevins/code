#include "regs.h"
#include "common.h"
#include "stdarg.h"

#define TRANS_BUSY while(!(UTRSTAT0 & 0x2))
#define RECEV_BUSY while(!(UTRSTAT0 & 0x1))

void uart_init(void)
{
	GPACON &= ~0xff;
	GPACON |= 0x22;

	ULCON0 = 3;
	UCON0 |= (1 << 2) | 1;
	UFCON0 = 0;
	UMCON0 = 0;
	UBRDIV0 = 34;
	UDIVSLOT0 = 0xdfdd;
}

void uputchar(char c)
{
	TRANS_BUSY;
	UTXH0 = c;
}

char ugetchar(void)
{
	RECEV_BUSY;
	return URXH0;
}

void _uputs(char *buf)
{
	while(*buf != '\0'){
		uputchar(*buf);
		buf++;
	}
}

void uputs(char *buf)
{
	while(*buf != '\0'){
		uputchar(*buf);
		buf++;
	}
	uputchar('\r');
	uputchar('\n');
}

char *ugets(char *buf)
{
	char *save = buf;
	char c;
	
	while((c = ugetchar()) != '\r'){
		uputchar(c);
		*(buf++) = c;
	}
	*buf = '\0';
	uputchar('\r');
	uputchar('\n');

	return save;
}

void itoa(int d, char *buf)
{
	int i;

	if(d  < 10){
		buf[0] = d + '0';
		buf[1] = '\0';
		return;
	}
	itoa(d / 10, buf);
	for(i = 0; buf[i] != '\0'; i++){
		;
	}
	buf[i] = (d % 10) + '0';
	buf[i + 1] = '\0';
}

void xtoa(int d, char *buf)
{
	int i;
	
	if(d < 16){
		if(d < 10){
			buf[0] = d + '0';
			buf[1] = '\0';
		}else{
			buf[0] = d - 10 + 'a';
			buf[1] = '\0';
		}
		return;
	}
	xtoa(d / 16, buf);
	for(i = 0; buf[i] != '\0'; i++ ){
		;
	}
	if((d % 16) < 10){
		buf[i] = (d % 16) + '0';
		buf[i + 1] = '\0';
	}else{
		buf[i] = (d % 16) - 10 + 'a';
		buf[i + 1] = '\0';
	}
}

int uprintf(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	char *s;
	int d;
	char buf[64];
	
	while(*fmt != '\0'){
		if(*fmt == '%'){
			fmt++;
			switch(*fmt){
				case 'd':
					d = va_arg(ap, int);
					itoa(d, buf);
					_uputs(buf);
					break;
				case 'c':
					d = va_arg(ap, int);
					uputchar(d);
					break;
				case 's':
					s = va_arg(ap, char *);
					_uputs(s);
					break;
				case 'x':
					d = va_arg(ap, int);
					xtoa(d, buf);
					_uputs(buf);
					break;
				default:
					break;
			}	
		}else{
			if(*fmt == '\n'){
				uputchar('\r');
			}
			uputchar(*fmt);
		}
		fmt++;
	}

	va_end(ap);

	return 0;
}
