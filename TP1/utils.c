#include "utils.h"

void printTab(long* A,size_t taille){
    printf("  [");
    for(size_t i = 0;i<taille;i++){
        printf(" %ld,",A[i]);
    }
    printf("]\n");
}

void cpTab(long* tab1, long* tab2, size_t deb, size_t fin){
    size_t j = 0;
    for(size_t i=deb; i<fin; i++){
        tab2[j] = tab1[i];
        j++;
    }
}

void afficheTab(long * A, size_t p, size_t q){
    if((p - q != 0)){
        printf("[");
        for(size_t i = p; i < q-1; i++){
            printf("%ld,",A[i]);
        }
        printf("%ld]\n",A[q-1]);
    }
    else{
        printf("Tab vide \n");
    }
}

void createAleaTab(long* A, size_t taille, long min,long max){
    for(size_t i = 0;i<taille;i++){
        A[i] = (long) (rand() % taille);
    }
}
void createCroisTab(long* A, size_t taille){
    for(size_t i = 0;i<taille;i++){
        A[i] = (long) i;
    }
}
void createDecroisTab(long* A, size_t taille){
    for(size_t i = 0;i<taille;i++){
        A[i] = (long)(taille - i);
    }
}