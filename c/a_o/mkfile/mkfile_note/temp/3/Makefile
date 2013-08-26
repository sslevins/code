SRCS=main.c lib.c other.c

all: a.out

a.out: $(SRCS:.c=.o)
	gcc $^ -o $@

%.o: %.c
	gcc -c $< -o $@

dep:
	gcc -MM main.c lib.c other.c > depend

sinclude depend

clean:
	rm a.out *.o

.PHONY: all clean
