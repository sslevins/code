all: hello

hello: lib main
	gcc lib/built-in.o main/built-in.o -o hello

lib:
	make -C lib

main:
	make -C main 

clean:
	make -C lib clean
	make -C main clean
	rm -f hello

.PHONY: all clean lib main
