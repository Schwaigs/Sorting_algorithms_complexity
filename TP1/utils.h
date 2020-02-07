#include <stdlib.h>
#include <stdio.h>


typedef struct p {
    int nb_ecriture;
    int nb_echange;
    int nb_comp;
    int appels_fusion
    int appels_partition
} perf;

void cpTab(long* tab1, long* tab2, size_t deb, size_t fin);
/********************************* Affichage ********************************/
void printTab(long* A,size_t taille);
void afficheTab(long * A, size_t p, size_t q);

/********************************** Gen Tab *********************************/
void createAleaTab(long* A, size_t taille, long min,long max);
void createCroisTab(long* A, size_t taille, long min,long max);
void createDecroisTab(long* A, size_t taille, long min,long max);