SUBDIR = 
SRCS = main.c

PWD = $(shell pwd)
CFLAGS = -I$(PWD)/../include
BUILTIN = built-in.o
DEPEND = depend


all: $(BUILTIN)

$(BUILTIN): $(SRCS:.c=.o)
	ld -r $^ -o $@

%.o:%.c
	gcc $(CFLAGS) -c $<

$(DEP):$(SRCS)
	gcc $(CFLAGS) -MM $(SRCS) > $@

sinclude $(DEP)

clean:
	for dir in $(SUBDIR); do \
		$(MAKE) -C $$dir clean; \
	done
	rm -rf *.o $(DEP) $(BUILTIN)

.PHONY: clean all
