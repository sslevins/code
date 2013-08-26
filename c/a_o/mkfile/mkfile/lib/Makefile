SUBDIR=
SRCS = 1.c 2.c 3.c 4.c 5.c 6.c 7.c

PWD= $(shell pwd)
CFLAGS = -I$(PWD)/../include
BUILTIN = built-in.o
DEP = depend

all:$(BUILTIN)

$(BUILTIN): $(SRCS:.c=.o)
	ld -r $^ -o $@

%.o: %.c
	gcc $(CFLAGS) -c $<

$(DEP): $(SRCS)
	gcc $(CFLAGS) -MM $(SRCS) > $@

sinclude $(DEP)

clean:
	for dir in $(SUBDIR); do \
		make -C $$dir clean; \
	done
	rm -rf *.o $(DEP) $(BUILTIN)

.PHONY: 
	clean all aaa
