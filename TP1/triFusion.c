#include "triFusion.h"


void triFusion(long* A, size_t taille){
    sousTriFusion(A,0,n);
}

void sousTriFusion(long* A, size_t debut, size_t fin){
    if (debut+1 < fin){
        q = floor((debut+fin)/2);
        sousTriFusion(A,debut,q);
        sousTriFusion(A,q,fin);
        fusion(A,debut,q,fin);
    }
}

void fusion(long* A, size_t debut, size_t milieu, size_t fin){
    size_t taille1 = millieu - debut;
    size_t taille2 = fin - milieu;
    long* Ag = malloc(sizeof(long)*taille1);
    long* Ad = malloc(sizeof(long)*taille2);
    memcpy(Ag, A, taille1);
    memcpy(Ad, A[milieu], taille2);
    size_t indg = 0;
    size_t indd = 0;
    size_t i = debut;
    while (i<fin){
        if (indg == taille1){
            A[i] = Ad[indd];
            indg++;
        } else if (indd == taille2){
            A[i] = Ag[indg];
            indg++;
        } else if (Ag[indg]<Ad[indd]){
            A[i] = Ag[indg];
            indg++;
        } else {
            A[i] = Ad[indd];
            indd++;
        }
        i++
    }
}