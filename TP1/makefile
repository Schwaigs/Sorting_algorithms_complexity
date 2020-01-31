all: main

tris.o: tris.h tris.c
	gcc -Wall -c tris.c

main: tris.o main.c
	gcc -Wall -o main tris.o main.c

clean: 
	rm *.o main