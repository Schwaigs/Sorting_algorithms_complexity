all: main main.o triFusion.o utils.o

triFusion.o: triFusion.h triFusion.c
	gcc -o triFusion.o -Wall -c triFusion.c

utils.o: utils.h utils.c
	gcc -o utils.o -Wall -c utils.c

tris.o: tris.h tris.c
	gcc -Wall -c tris.c

main: tris.o main.c triFusion.o utils.o
	gcc -Wall -o main tris.o main.c triFusion.o utils.o

clean:
	rm *.o main