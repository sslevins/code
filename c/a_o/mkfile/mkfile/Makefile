SUBDIR = lib main
TGT = hello
PWD = $(shell pwd)
CFLAGS = -I$(PWD)/include
BUILTIN = built-in.o
DEPEND = depend

all: $(TGT)

$(TGT): $(SUBDIR)
	gcc -o $@ $(^:=/$(BUILTIN))
	@echo ********finish********

#make -C lib
lib:
	make -C lib

main:
	make -C main

$(DEPEND): $(SRCS)
	gcc $(CFLAGS) -MM $^ > $@

clean:
	@for dir in $(SUBDIR); do \
		make -C $$dir clean; \
	done
	rm -rf *.o $(DEP) $(BUILTIN)

.PHONY: all clean $(SUBDIR) 
