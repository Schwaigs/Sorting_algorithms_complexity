all: main main.o utils.o tri_rapide_decompte.o

utils.o: utils.h utils.c
	gcc -o utils.o -Wall -c utils.c

#tris.o: tris.h tris.c
#	gcc -Wall -c tris.c

tri_rapide_decompte.o: tri_rapide_decompte.h tri_rapide_decompte.c
	gcc -Wall -c tri_rapide_decompte.c

tri_fusion_decompte.o: tri_fusion_decompte.h tri_fusion_decompte.c
	gcc -Wall -c tri_fusion_decompte.c

tri_inser_decompte.o: tri_inser_decompte.h tri_inser_decompte.c
	gcc -Wall -c tri_inser_decompte.c

#main: tris.o tri_rapide_decompte.o main.c utils.o
#	gcc -Wall -o main tris.o tri_rapide_decompte.o main.c utils.o

main: tri_rapide_decompte.o tri_inser_decompte.o tri_fusion_decompte.o main.c utils.o
	gcc -Wall -o main tri_rapide_decompte.o tri_inser_decompte.o tri_fusion_decompte.o main.c utils.o -lpthread -lm

clean:
	rm *.o main