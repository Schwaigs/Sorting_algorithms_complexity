#include "tri_inser_decompte.h"

void triInsertion(long * A, size_t n){
    printf("********* Tri par insertion **********\n");
    perf p = init_perf();
    afficheTab(A,0,n);
    for( size_t i = 1; i <= n-1; i++){
        p.nb_comp += 1; //comparaison boucle
        p.nb_ecriture +=1; //incrémentation boucle
        long cle = A[i];
        p.nb_ecriture +=1;
        size_t j = i-1;
        p.nb_ecriture +=1;
        printf("Clé %ld à la position : %ld\n",cle,i);
        while(((j > j-1) || (j == 0)) && (A[j] > cle)){
            p.nb_comp += 3; //comparaison boucle
            printf("    %ld à la position %ld, plus grand que %ld \n",A[j],j,cle);
            A[j+1] = A[j];
            p.nb_ecriture +=1;
            printf("    Ecriture de %ld : ",A[j]);
            afficheTab(A,0,n);
            j--;
            p.nb_ecriture +=1;
            p.nb_comp += 1;
            if(j+1 == 0){
                break;
            }
        }
        A[j+1] = cle;
        p.nb_ecriture +=1;
        printf("    Ecriture de la clé %ld : ",cle);
        afficheTab(A,0,n);
    }
    printf("Tableau trié : ");
    afficheTab(A,0,n);
    printPerf(p);
}