SRCS=main.c lib.c

all: a.out

# main.c lib.c ----> main.o lib.o
a.out: $(SRCS:.c=.o) 
	gcc $^

%.o: %.c
	gcc -c $< -o $@

clean:
	rm a.out *.o

.PHONY: all clean
