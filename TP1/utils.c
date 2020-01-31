#include "utils.h"

void printTab(long* A,size_t taille){
    printf("Tableau:\n [");
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
