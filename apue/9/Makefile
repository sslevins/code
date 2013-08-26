all:server client

server: srv.c
	gcc srv.c -o server

client: cli.c
	gcc cli.c -o client

clean:
	rm -rf server client *.out
