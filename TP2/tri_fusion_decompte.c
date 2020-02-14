#include <stddef.h>
#include "tri_fusion_decompte.h"

void triFusion(long* A, size_t taille){
    sousTriFusion(A,0,taille);
    //printTab(A,taille);
    printf("********* Tri par fusion **********\n");
}

void sousTriFusion(long* A, size_t debut, size_t fin){
    if (debut+1 < fin){
        size_t q = (size_t) ((debut+fin)/2);
        //printf("# sousTriFusion \n taille du tableau : %ld \n moit : %ld \n",(fin-debut),q);
        sousTriFusion(A,debut,q);
        sousTriFusion(A,q,fin);
        fusion(A,debut,q,fin);
    }
}

void fusion(long* A, size_t debut, size_t milieu, size_t fin){
    size_t taille1 = milieu - debut;
    size_t taille2 = fin - milieu;
    long* Ag = malloc(sizeof(long)*taille1);
    long* Ad = malloc(sizeof(long)*taille2);
    cpTab(A, Ag, debut,milieu);
    cpTab(A, Ad, milieu,fin);

//    debut affichage
//    printf("## Fusion \n  taille du tableau à former : %ld \n  debut : %ld \n  milieu : %ld \n  fin : %ld \n  tableau complet :",(fin-debut),debut,milieu,fin);
//    printf("  [");
//    for(size_t i = debut;i<fin;i++){
//        printf(" %ld,",A[i]);
//    }
//    printf("]\n");
//    printf("  tableau gauche :\n");
//    printTab(Ag,taille1);
//    printf("  tableau droit :\n");
//    printTab(Ad,taille2);
    // fin affichage

    size_t indg = 0;
    size_t indd = 0;
    size_t i = debut;

    while (i<fin){
        if (indg == taille1){
            A[i] = Ad[indd];
            indd++;
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
        i++;
    }
    free(Ag);
    free(Ad);
}