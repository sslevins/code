all: built-in.o

built-in.o: main.c
	gcc -I../include -c main.c -o built-in.o

clean:
	rm -f built-in.o

.PHONY: all clean

