#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <utime.h>
#include <errno.h>
#include <stdlib.h>

#define oops(x, num) \
				{ perror(x); exit(num); }

int main()
{
	int ret = 0;
	struct utimbuf buf;
	buf.actime = time(NULL);
	buf.modtime = time(NULL);

	ret = utime("./1.c", &buf);
	if (ret == -1)
		oops("utime", 1);

	return 0;
}


