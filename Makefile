



all: server

clean:
	@rm -rf *.o
	@rm -rf server

server: main.o httpd.o
	gcc -o server $^

main.o: main.c httpd.h
	gcc -c -o main.o main.c

httpd.o: httpc.c httpd.h
	gcc -c -o httpd.o httpc.c
