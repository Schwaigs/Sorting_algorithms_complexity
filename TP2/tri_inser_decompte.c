#include "tri_inser_decompte.h"

void triInsertion(long * A, size_t n){
    printf("********* Tri par insertion **********\n");
    printf("Tableau de départ :\n");
    afficheTab(A,0,n);
    long cle;
    for( size_t i = 1; i <= n-1; i++){
        cle = A[i];
        size_t j = i-1;

//        printf("Clé %ld à la position : %ld\n",cle,i);
        while(((j > j-1) || (j == 0)) && (A[j] > cle)){
//            printf("    %ld à la position %ld, plus grand que %ld \n",A[j],j,cle);
            A[j+1] = A[j];
//            printf("    Ecriture de %ld : ",A[j]);
//            afficheTab(A,0,n);
            j--;
            if(j+1 == 0){
                break;
            }
        }
        A[j+1] = cle;
//        printf("    Ecriture de la clé %ld : ",cle);
//        afficheTab(A,0,n);
    }
    printf("Tableau de sortie :\n");
    afficheTab(A,0,n);
}