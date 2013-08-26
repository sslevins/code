SRCS=main.c lib.c 

all: a.out

a.out: $(SRCS:.c=.o)
	gcc $^ -o $@

%.o: %.c
	gcc -Iinclude -c $< -o $@

dep:
	gcc -MM $(SRCS) > depend

sinclude depend

clean:
	rm a.out *.o

.PHONY: all clean
