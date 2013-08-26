SUBDIR=lib main

all: a.out

a.out: $(SUBDIR)
	gcc $(SUBDIR:=/built-in.o)

$(SUBDIR):
	cd $@; make
	#make -C $@

clean:
	for dir in $(SUBDIR); do\
		make -C $$dir clean\
	done

.PHONY: all clean $(SUBDIR)
