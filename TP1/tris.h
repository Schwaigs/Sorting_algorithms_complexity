#include "utils.h"
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/***************************** Algo 2 : Tri fusion *****************************/
void triFusion(long* A, size_t taille);
void sousTriFusion(long* A, size_t debut, size_t fin);
void fusion(long* A, size_t debut, size_t milieu, size_t fin);

/***************************** Algo 3 : Tri rapide *****************************/
void sousTriRapide(long * A,size_t p, size_t r);
size_t partition(long *, size_t p, size_t r);
void triRapide(long *, size_t n);
