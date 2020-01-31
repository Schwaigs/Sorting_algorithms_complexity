all: main main.o triFusion.o

main: main.o triFusion.o
	gcc -o main -Wall main.o triFusion.o

main.o: main.c
	gcc -o main.o -Wall -c main.c

triFusion.o: triFusion.h triFusion.c
	gcc -o triFusion.o -Wall -c triFusion.c
