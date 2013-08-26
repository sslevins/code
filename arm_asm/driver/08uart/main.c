#include "regs.h"
#include "common.h"

int main(int argc, char *argv[])
{
	char buf[1024];
	clock_init();
	uart_init();
	int c = ugetchar();

	uputchar(c);
	uputchar('\r');
	uputchar('\n');

	uputs("hello uart...");

	ugets(buf);
	uputs(buf);

	uprintf("hello chengdu...\n");
	uprintf("uprintf:%s\n%c\n", "hello printf", 'g');
	uprintf("uprintf:%d\n%x\n",122, 48);

	return 0;
}
