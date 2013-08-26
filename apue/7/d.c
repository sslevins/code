#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h> 

int print_screen(char *buf,int width,int height);

char *fb_addr;
unsigned fb_size;

int main(int argc, char *argv[])
{
	int screen_fbd = 0;
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
	char *env = NULL;
	short *color_white;

	if(!(env = getenv("FRAMEBUFFER")))
		env = "/dev/fb0";

	screen_fbd = open(env, O_RDWR);

	if(screen_fbd < 0)
	{
		printf("liuqi Error Opening FrameBuffer Device:%s\r\n", env);
		return 0;
	}
	else
	{
		printf("Success Opening FrameBuffer Device:%s\r\n",env);
	}

	if(ioctl(screen_fbd, FBIOGET_FSCREENINFO, &fb_fix) == -1)
	{
		printf("Error Reading Screen Info FSCREENINFO.\n");

		close(screen_fbd);

		return 0;
	}

	if(ioctl(screen_fbd, FBIOGET_VSCREENINFO, &fb_var) == -1)
	{
		printf("Error Reading Screen Info VSCREENINFO.\n");

		close(screen_fbd);

		return 0;
	}

	fb_size = fb_var.yres * fb_fix.line_length;
	fb_addr = (char *)mmap(NULL, fb_size, PROT_READ|PROT_WRITE, MAP_SHARED, screen_fbd, 0);
	color_white=(char*)malloc(fb_var.yres * fb_fix.line_length);
	memset(color_white, 0xFF, fb_var.yres * fb_fix.line_length);
	sleep(3);
	print_screen(color_white,fb_var.xres,fb_var.yres);
	if (!fb_addr)
		exit(1);
	free(color_white);
	return 0;
}

int print_screen(char *buf,int width,int height)
{
	short *t_data = (short *)buf;
	short *t_fb_addr = (short *)fb_addr;
	int bytew= width<<1;
	while(--height >= 0)
	{
		memcpy(t_fb_addr,t_data,bytew);
		t_fb_addr += width;
		t_data += width;
	}
}
