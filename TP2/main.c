#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "tri_rapide_decompte.h"
#include "utils.h"
#include "tri_fusion_decompte.h"
#include "tri_inser_decompte.h"
#include "tri_radix.h"

struct argument{
    long* tab;
    long size;
};


void* threadInsert (void* arg){
    struct argument* argum = (struct argument*)arg;
    triInsertion(argum->tab,argum->size);
    pthread_exit(NULL);
}
void* threadFusion (void* arg){
    struct argument* argum = (struct argument*)arg;
    triFusion(argum->tab,argum->size);
    pthread_exit(NULL);
}
void* threadRapide (void* arg){
    struct argument* argum = (struct argument*)arg;
    triRapide(argum->tab,argum->size);
    pthread_exit(NULL);
}
void* threadRadix (void* arg){
    struct argument* argum = (struct argument*)arg;
    triRadix(argum->tab,argum->size);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {

    if(argc != 6){
        printf("Argument manquant : %s nom_tri taille_tab type_tab min max\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    
    /********************* Gen Tab **********************/
    char *ptr;
    long taille = strtol(argv[2],&ptr,10);
    long* tab = malloc(sizeof(long)*taille);

    switch (argv[3][0]){
        case 'a':
            createAleaTab(tab,taille,atoi(argv[4]),atoi(argv[5]));
            break;
        case 'c':
            createCroisTab(tab,taille,atoi(argv[4]),atoi(argv[5]));
            break;
        case 'd':
            createDecroisTab(tab,taille,atoi(argv[4]),atoi(argv[5]));
            break;
        default:
            printf("Argument n°4 type_tab : [a : aleatoire] [c : croissant] [d : decroissant]\n");
            exit(EXIT_FAILURE);
    }

    /********************* Choix tri **********************/
    long* tabCp = malloc(sizeof(long)*taille);
    memcpy(tabCp,tab,sizeof(long)*taille);

    struct argument arg;
    arg.size = taille;
    arg.tab = tabCp;
    pthread_t tri;

    switch (argv[1][0]){
        case 'i':
            pthread_create (&tri, NULL, threadInsert, &arg);
            break;
        case 'f':
            pthread_create (&tri, NULL, threadFusion, &arg);
            break;
        case 'r':
            pthread_create (&tri, NULL, threadRapide, &arg);
            break;
        case 'x':
            pthread_create (&tri, NULL, threadRadix, &arg);
            break;
        default:
            printf("Argument n°2 nom_tri : [i : insertion] [f : fusion] [r : rapide] [x : radix]\n");
            exit(EXIT_FAILURE);
    }

    pthread_join(tri,NULL);
    free(tab);
    free(tabCp);

    return 0;
}
