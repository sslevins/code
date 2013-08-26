HELLO=hello world
PWD=$(shell pwd)

all: a.out

a.out: main.o lib.o
	gcc $^

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm a.out *.o

.PHONY: all clean
