all: main main.o utils.o

utils.o: utils.h utils.c
	gcc -o utils.o -Wall -c utils.c

tris.o: tris.h tris.c
	gcc -Wall -c tris.c

tri_fusion_decompte.o: tri_fusion_decompte.h tri_fusion_decompte.c
	gcc -Wall -c tri_fusion_decompte.c

main: tris.o tri_fusion_decompte.o main.c utils.o
	gcc -Wall -o main tris.o tri_fusion_decompte.o main.c utils.o

clean:
	rm *.o main