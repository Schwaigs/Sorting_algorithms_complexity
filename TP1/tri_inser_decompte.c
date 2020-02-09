#include "tri_inser_decompte.h"

void triInsertion(long * A, size_t n){

    perf p = init_perf();
//    afficheTab(A,0,n);
    long cle;
    p.nb_alloc += sizeof(long) + sizeof(size_t);
    for( size_t i = 1; i <= n-1; i++){
        cle = A[i];
        size_t j = i-1;

        p.nb_comp += 1; //comparaison boucle
        p.nb_ecriture +=3;
//        printf("Clé %ld à la position : %ld\n",cle,i);
        while(((j > j-1) || (j == 0)) && (A[j] > cle)){
//            printf("    %ld à la position %ld, plus grand que %ld \n",A[j],j,cle);
            A[j+1] = A[j];
//            printf("    Ecriture de %ld : ",A[j]);
//            afficheTab(A,0,n);
            j--;
            p.nb_comp += 4; //comparaison boucle + suivante
            p.nb_ecriture +=2;;
            p.nb_ecriture_tab++;
            if(j+1 == 0){
                break;
            }
        }
        A[j+1] = cle;
        p.nb_ecriture++;
        p.nb_ecriture_tab++;
//        printf("    Ecriture de la clé %ld : ",cle);
//        afficheTab(A,0,n);
    }
//    printf("Tableau trié : ");
//    afficheTab(A,0,n);
    printf("********* Tri par insertion **********\n");
    printPerf(p);
}