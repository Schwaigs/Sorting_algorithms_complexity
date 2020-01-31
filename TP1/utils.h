#include <stdlib.h>
#include <stdio.h>


void cpTab(long* tab1, long* tab2, size_t deb, size_t fin);
/********************************* Affichage ********************************/
void printTab(long* A,size_t taille);
void afficheTab(long * A, size_t p, size_t q);

/********************************** Gen Tab *********************************/
void createAleaTab(long* A, size_t taille);
void createCroisTab(long* A, size_t taille);
void createDecroisTab(long* A, size_t taille);