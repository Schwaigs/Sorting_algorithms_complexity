#include "utils.h"
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/********************************* Test Gen Tab ********************************/
void createAleaTab(long* A, size_t taille);
void createCroisTab(long* A, size_t taille);
void createDecroisTab(long* A, size_t taille);
/***************************** Algo 2 : Tri fusion *****************************/
void triFusion(long* A, size_t taille);
void sousTriFusion(long* A, size_t debut, size_t fin);
void fusion(long* A, size_t debut, size_t milieu, size_t fin);

/***************************** Algo 3 : Tri rapide *****************************/
void sousTriRapide(long * A,size_t p, size_t r);
size_t partition(long *, size_t p, size_t r);
void triRapide(long *, size_t n);
