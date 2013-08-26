#include "regs.h"
#include "stdarg.h"

void uart_init(void)
{
	GPACON &= ~0xff;
	GPACON |= 0x22;

	ULCON0 = 0x03;
	UCON0 |= 0x1 | (1 << 2);
	UFCON0 = 0;
	UMCON0 = 0;
	UBRDIV0 = 34; 
	UDIVSLOT0 = 0xdfdd;
}

void uputchar(char c)
{
	while((UTRSTAT0 & 0x2) == 0);
	UTXH0 = c;
}

char ugetchar(void)
{
	while((UTRSTAT0 & 0x1) == 0);
	
	return URXH0;
}

void uputs(const char *string)
{
	while(*string != '\0'){
		if(*string == '\n'){
			uputchar('\r');
		}
		uputchar(*string);
		string++;
	}
}

void itoa(int c, char *buf)
{
	int i;

	if(c < 10){
		buf[0] = c + '0';
		buf[1] = '\0';
		return;
	}

	itoa(c / 10, buf);
	
	for(i = 0; buf[i] != '\0'; i++);
	
	buf[i] = (c % 10) + '\0';
	buf[i + 1] = '\0';
}

void itox(int c, char *buf)
{
	int i;

	if(c < 16){
		if(c < 10){
			buf[0] = c + '0';
			buf[1] = '\0';
		}else{
			buf[0] = c - 10 + 'a';
			buf[1] = '\0';
		}
		return;
	}

	itox(c / 16, buf);

	for(i = 0; buf[i] != '\0'; i++);

	if((c % 16) < 10){
		buf[i] = (c % 16) + '0';
		buf[i + 1] = '\0';	
	}else{
		buf[i] = (c % 16) + 'a' - 10;
		buf[i + 1] = '\0';
	}		
}

char *ugets(char *string)
{
	char c;
	char *save = string;
	
	while((c = ugetchar()) != '\r'){
		uputchar(c);
		*string = c;
		string++;
	}
	uputchar('\n');
	*string = '\0';
	
	return save;
}

int uprintf(const char *fmt, ...)
{
	char buf[64];
	
	char *s;
	char c;
	int d, x;

	va_list ap;

	va_start(ap, fmt);	

	while(*fmt != '\0'){
		if(*fmt == '%'){
			fmt++;		
			switch(*fmt){
				case 's':
					s = va_arg(ap, char *);
					uputs(s);
					break;
				case 'c':
					c = va_arg(ap, int);
					uputchar(c);
					break;
				case 'x':
					x = va_arg(ap, int);
					itox(x, buf);
					uputs(buf);
					break;
				case 'd':	
					d = va_arg(ap, int);
					itoa(d, buf);
					uputs(buf);
					break;
				defautl:
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
}
