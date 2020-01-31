all: main main.o utils.o

utils.o: utils.h utils.c
	gcc -o utils.o -Wall -c utils.c

tris.o: tris.h tris.c
	gcc -Wall -c tris.c

main: tris.o main.c utils.o
	gcc -Wall -o main tris.o main.c utils.o

clean:
	rm *.o main