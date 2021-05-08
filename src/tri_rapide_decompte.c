#include "tri_rapide_decompte.h"

void sousTriRapide(long * A,size_t p, size_t r){
    if(p+1 < r){
        size_t q = partition(A,p,r); //q la position du pivot dans la partition
        //printf("Pivot %ld à la position : %ld \n",A[q],q);

        sousTriRapide(A,p,q);
        sousTriRapide(A,q+1,r);
    }

}

size_t partition(long * A, size_t p, size_t r){
    //long pivot = A[r-1]; //le pivot est le dernier élément du tableau
    //On prend un pivot de manière aléatoire
    long pivot = A[rand()%((r+1)-p) +p];
    //printf("Pivot %ld \n",pivot);
    size_t i = p;
    long tmp;

    for (size_t j = p; j+2 <= r; j++){

        //printf("    i = %ld et A[i] = %ld   j = %ld et A[j] = %ld \n",i,A[i],j,A[j]);
        if(A[j] <= pivot){
            //printf("    Permutation de %ld et %ld : ",A[i],A[j]);
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
//            afficheTab(A,p,r);
        }
    }
//    printf("    Permutation du pivot : ");
    tmp = A[i];
    A[i] = A[r-1];
    A[r-1] = tmp;

//    afficheTab(A,p,r);
    return i;
}

void triRapide(long * A, size_t n){
    //printf("********* Tri rapide **********\n");
    //printf("Tableau de départ :\n");
    //printf("Bornes de départs : 0 et %ld \n",n);
    //afficheTab(A,0,n);
    sousTriRapide(A,0,n);
    //printf("Tableau de sortie :\n");
    //afficheTab(A,0,n);
}