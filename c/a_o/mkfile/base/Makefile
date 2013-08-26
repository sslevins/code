
all: a.out

a.out: main.o lib.o
	gcc main.o lib.o

main.o: main.c
	gcc -c main.c -o main.o

lib.o: lib.c
	gcc -c lib.c -o lib.o

clean:
	rm a.out main.o lib.o

.PHONY: clean all
