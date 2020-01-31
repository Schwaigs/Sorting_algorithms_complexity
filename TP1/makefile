all: main main.o triFusion.o utils.o

main: main.o triFusion.o utils.o
	gcc -o main -Wall main.o triFusion.o utils.o

main.o: main.c
	gcc -o main.o -Wall -c main.c

triFusion.o: triFusion.h triFusion.c
	gcc -o triFusion.o -Wall -c triFusion.c

utils.o: utils.h utils.c
	gcc -o utils.o -Wall -c utils.c
