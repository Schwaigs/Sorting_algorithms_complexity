#include <stddef.h>
#include "utils.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

void triFusion(long* A, size_t taille);

void sousTriFusion(long* A, size_t debut, size_t fin);

void fusion(long* A, size_t debut, size_t milieu, size_t fin);