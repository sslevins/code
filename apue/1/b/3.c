#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define oops(x, num) {perror(x); exit(num);}

void show_mode(struct stat* st)
{
	char buf[11];

	if (S_ISREG(st->st_mode))
		buf[0] = '-';
	else if (S_ISDIR(st->st_mode))
		buf[0] = 'd';
	else if (S_ISCHR(st->st_mode))
		buf[0] = 'c';
	else if (S_ISBLK(st->st_mode))
		buf[0] = 'b';
	else if (S_ISFIFO(st->st_mode))
		buf[0] = 'p';
	else if (S_ISLNK(st->st_mode))
		buf[0] = 'l';
	else if (S_ISSOCK(st->st_mode))
		buf[0] = 's';
	else
		buf[0] = '0';
	
	if ((st->st_mode & 00400) != 0)
		buf[1] = 'r';
	else
		buf[1] = '-';

	if ((st->st_mode & 00200) != 0)
		buf[2] = 'w';
	else
		buf[2] = '-';

	if ((st->st_mode & 00100) != 0)
		buf[3] = 'x';
	else
		buf[3] = '-';

	if ((st->st_mode & 00040) != 0)
		buf[4] = 'r';
	else
		buf[4] = '-';

	if ((st->st_mode & 00020) != 0)
		buf[5] = 'w';
	else
		buf[5] = '-';

	if ((st->st_mode & 00010) != 0)
		buf[6] = 'x';
	else
		buf[6] = '-';

	if ((st->st_mode & 00004) != 0)
		buf[7] = 'r';
	else
		buf[7] = '-';

	if ((st->st_mode & 00002) != 0)
		buf[8] = 'w';
	else
		buf[8] = '-';

	if ((st->st_mode & 00001) != 0)
		buf[9] = 'x';
	else
		buf[9] = '-';
	
	buf[10] = '\0';

	printf("%s ", buf);
}

void show_uname(int uid)
{
	struct passwd * pwd = getpwuid(uid);
	printf("%s ", pwd->pw_name);
}

void show_gname(int gid)
{
	struct group * group = getgrgid(gid);
	printf("%s ", group->gr_name);
}

void show_time(time_t time)
{
	char* p = ctime(&time);
	printf("%s ", p+4);
}

void show_info(struct stat* st, struct dirent * dir)
{
	//printf("%c ", type);
	//printf("%d ", st->st_mode);
	show_mode(st);
	printf("%d ", st->st_nlink);
	// printf("%d ", st->st_uid);
	show_uname(st->st_uid);
	// printf("%d ", st->st_gid);
	show_gname(st->st_gid);
	printf("%d ", st->st_size);
	// printf("%d ", st->st_mtime);
	show_time(st->st_mtime);
	printf("%s", dir->d_name);

	printf("\n");
}

int main()
{
	DIR * cur = opendir(".");
	if (cur == NULL)
		oops("opendir", 1);
	
	struct stat st;
	struct dirent * dir;
	while ((dir = readdir(cur)) != NULL)
	{
		stat(dir->d_name, &st);
		show_info(&st, dir);
	}
	
}

