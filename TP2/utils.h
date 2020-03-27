#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <stdio.h>


typedef struct p {
    unsigned long nb_ecriture;
    unsigned long nb_echange;
    unsigned long nb_alloc;
    unsigned long nb_ecriture_tab;
    unsigned long nb_comp;
    unsigned long appels_fusion;
    unsigned long appels_partition;
} perf;

perf init_perf();
void printPerf(perf p);

void cpTab(long* tab1, long* tab2, size_t deb, size_t fin);
/********************************* Affichage ********************************/
void printTab(long* A,size_t taille);
void afficheTab(long * A, size_t p, size_t q);

/********************************** Gen Tab *********************************/
void createAleaTab(long* A, size_t taille, long min,long max);
void createUniTab(long* A, size_t taille, long min,long max);
void createCroisTab(long* A, size_t taille, long min,long max);
void createDecroisTab(long* A, size_t taille, long min,long max);

void createCombineTab(long* A, size_t taille, long min, long max, char firstType, char secondType, size_t change);
#endif