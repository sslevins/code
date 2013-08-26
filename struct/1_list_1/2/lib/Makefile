all: built-in.o

built-in.o: list.c
	gcc -I../include -c list.c -o built-in.o

clean:
	rm -f built-in.o

.PHONY: all clean

