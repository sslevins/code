#ifndef LZY_COMMON_H
#define LZY_COMMON_H

 
#define INT_EINT1 1
#define TFTP_RRQ        1
#define TFTP_WRQ        2
#define TFTP_DATA       3
#define TFTP_ACK        4
#define TFTP_ERROR      5
#define TFTP_OACK       6
#define MAX_BLOCK       (2048 * 16)
#define NULL ((void *)0)
#define printf(...) (((int (*)(const char *, ...))0xc7e11d70)(__VA_ARGS__))

#endif

