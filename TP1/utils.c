#include "utils.h"
#include <math.h>

void printTab(long* A,size_t taille){
    printf("  [");
    for(size_t i = 0;i<taille-1;i++){
        printf(" %ld,",A[i]);
    }
    printf(" %ld]\n",A[taille-1]);
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
        A[i] = (long)(min + (rand() % (max - min)));
    }
}
void createCroisTab(long* A, size_t taille, long min,long max){
    int step = 1;
    int inter = 1;
    if (taille>=(max-min)){
        step = taille/(max-min);
    } else{
        step = 0;
        inter = ceil((max-min)/taille);
    }
    long val = min;
    for(size_t i = 0;i<taille;i++){
        A[i] = (long) val;
        if (step == 0 || i%step==0){
            val+=inter;
        }
    }
}
void createDecroisTab(long* A, size_t taille, long min,long max){
    int step = 1;
    int inter = 1;
    if (taille>=(max-min)){
        step = ceil(taille/(max-min));
    } else{
        step = 0;
        inter = ceil((max-min)/taille);
    }
    long val = 0;
    for(size_t i = 0;i<taille;i++){
        A[i] = (long) (max-val);
        if (step==0 || i%step==0){
            val+=inter;
        }
    }
}

perf init_perf() {
    perf p;
    p.nb_ecriture = 0;
    p.nb_echange = 0;
    p.nb_comp = 0;
    p.appels_fusion = 0;
    p.appels_partition = 0;
  return p;
}