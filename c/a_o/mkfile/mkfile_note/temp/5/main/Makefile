SUBDIR =
SRCS = main.c
TGT = built-in.o
CFLGS = -c -I../include

$(TGT): $(SRCS:.c=.o) $(SUBDIR)
	ld -r $(SRCS:.c=.o) $(SUBDIR:=/$(TGT)) -o $@

%.o: %.c
	gcc $(CFLGS) $^ -o $@

$(SUBDIR):
	make -C $@
	
clean:
	for dir in $(SUBDIR); do \
		make -C $$dir clean; \
	done
	rm -rf $(TGT) $(SRCS:.c=.o)

.PHONY: clean $(SUBDIR)


