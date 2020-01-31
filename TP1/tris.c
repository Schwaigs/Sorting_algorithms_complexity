#include "tris.h"

/***************************** Algo 1 : Tri par insertion *****************************/

void triInsertion(long * A, size_t n){
    printf("********* Tri par insertion **********\n");
    afficheTab(A,0,n);
    for( size_t i = 1; i <= n-1; i++){
        long cle = A[i];
        size_t j = i-1;
        printf("Clé %ld à la position : %ld\n",cle,i);
        while(((j > j-1) || (j == 0)) && (A[j] > cle)){
            printf("    %ld à la position %ld, plus grand que %ld \n",A[j],j,cle);
            A[j+1] = A[j];
            printf("    Ecriture de %ld : ",A[j]);
            afficheTab(A,0,n);
            j--;
            if(j+1 == 0){
                break;
            }
        }
        A[j+1] = cle;
        printf("    Ecriture de la clé %ld : ",cle);
        afficheTab(A,0,n);
    }
    printf("Tableau trié : ");
    afficheTab(A,0,n);
}


/***************************** Algo 2 : Tri fusion *****************************/

void triFusion(long* A, size_t taille){
    printf("********* Tri par fusion **********\n");
    sousTriFusion(A,0,taille);
    printTab(A,taille);
}

void sousTriFusion(long* A, size_t debut, size_t fin){
    if (debut+1 < fin){
        size_t q = (size_t) ((debut+fin)/2);
        printf("# sousTriFusion \n taille du tableau : %ld \n moit : %ld \n",(fin-debut),q);
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

    //debut affichage
    printf("## Fusion \n  taille du tableau à former : %ld \n  debut : %ld \n  milieu : %ld \n  fin : %ld \n  tableau complet :",(fin-debut),debut,milieu,fin);
    printf("  [");
    for(size_t i = debut;i<fin;i++){
        printf(" %ld,",A[i]);
    }
    printf("]\n");
    printf("  tableau gauche :\n");
    printTab(Ag,taille1);
    printf("  tableau droit :\n");
    printTab(Ad,taille2);
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


/***************************** Algo 3 : Tri rapide *****************************/

void sousTriRapide(long * A,size_t p, size_t r){
    if(p - r != 0){
        size_t q = partition(A,p,r); //q la position du pivot dans la partition
        printf("Pivot %ld à la position : %ld \n",A[q],q);
        //tri partie gauche
        printf("Sous tri gauche  de %ld à %ld : ",p,q);
        afficheTab(A,p,q);
        sousTriRapide(A,p,q);
        //tri partie droite
        printf("Sous tri droit  de %ld à %ld : ",q+1,r);
        afficheTab(A,q+1,r);
        sousTriRapide(A,q+1,r);
    }
}

size_t partition(long * A, size_t p, size_t r){
    long pivot = A[r-1]; //le pivot est le dernier élément du tableau
    printf("Pivot %ld \n",pivot);
    size_t i = p;
    for (size_t j = p; j+2 <= r; j++){
        printf("    i = %ld et A[i] = %ld   j = %ld et A[j] = %ld \n",i,A[i],j,A[j]);
        if(A[j] <= pivot){
            printf("    Permutation de %ld et %ld : ",A[i],A[j]);
            long tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            afficheTab(A,p,r);
        }
    }
    printf("    Permutation du pivot : ");
    long tmp = A[i];
    A[i] = A[r-1];
    A[r-1] = tmp;
    afficheTab(A,p,r);
    return i;
}

void triRapide(long * A, size_t n){
    printf("********* Tri rapide **********\n");
    afficheTab(A,0,n);
    sousTriRapide(A,0,n);
    printf("Tableau trié : ");
    afficheTab(A,0,n);
}