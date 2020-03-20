#include "tri_radix.h"
#include <string.h>

void triRadix(long * A,size_t n){
    //On cherche le plus grand nombre et le plus petit nombre de notre tableau pour connaitre celui avec le plus de chiffre(= digit)
    long m = labs(chercheMaxMin(A, n));

    //On créer le tableau qui va stocker le nouvel ordre temporairement de nos valeurs à chaque ittération de tris
    long * newA = malloc(sizeof(long)*n);

    //On fait une occurence de tri par digit (unité, dizaines, centaines...)
    //On en en base 10 donc à chaque boucle le digit est multiplié par 10
    for (int digit = 1; m/digit > 0; digit *= 10){
        triDigit(A, n, digit,newA);
    }
    afficheTab(A,0,n);
    free(newA);
}

long chercheMaxMin(long * A,size_t n){
    //On cherche les plus grand et plus petits nombres de notre tableau
    long min = A[0];
    long max = A[0];
    for (size_t i = 1; i < n; i++) 
        if (A[i] > max) 
            max = A[i]; 
        else if (A[i] < min)
            min = A[i];
    //on regarde lequel possède le plus grand nombre de chiffre avec la valeur absolue
    if(labs(max) > labs(min))
        return max;
    return min; 
}

//Tri le tableau selon un chiffre(digit) en particulier
void triDigit(long * A, size_t n, int d, long * newA) { 

    //On créer un tableau stockant les nombre selon le chiffre de leur digit 
    //même méthode que celle d'un histogramme
    long chiffre_neg[10] = {0}; //de 0 à -9 pour pouvoir gerer les nombres négatifs (0 des nombres négatifs)
    long chiffre_pos[10] = {0}; //de 0 à 9
  
    //On parcours le tableau pour compter les occurence de chaque chiffre pour notre digit actuel
    for (size_t i = 0; i < n; i++) {
        //On recupère le chiffre qui nous interesse
        int digit = (A[i]/d)%10;
        if(A[i] < 0){
            chiffre_neg[abs(digit)]++;
        }
        else{
            chiffre_pos[digit]++;
        }
    }

    //On fait un histogramme cumulé de chiffre_pos et chiffre_neg 
    //pour connaitre les indice de séparation de chaque groupe de chiffre dans notre tableau temporaire
    for (size_t j = 8; j+1 > 0; j--){
        chiffre_neg[j] += chiffre_neg[j+1];
    }

    chiffre_pos[0] += chiffre_neg[0];

    for (size_t l = 1; l < 10; l++){
        chiffre_pos[l] += chiffre_pos[l-1];
    }
  
    //On remplis notre tableau temporaire 
    for (size_t k = n - 1; k + 1 != 0; k--) 
    {   
        //On cherche la nouvelle position de notre valeur courante
        //à l'aide du nombre de valeurs qui possèdent le même digit dans notre histogramme chiffre
        size_t digit = (A[k]/d)%10;
        size_t pos;
        if(A[k] < 0){
            pos = chiffre_neg[abs(digit)] - 1;
            //une fois la valeur placée, on indique dans notre histogramme 
            //qu'il y en a une en moins à traiter pour ce digit
            chiffre_neg[abs(digit)]--;
        }
        else{
            pos = chiffre_pos[digit] - 1;
            chiffre_pos[digit]--;
        }
        newA[pos] = A[k];
    } 
  
    //Remplace le contenu de A par celui de notre tableau temporaire
    memcpy(A,newA,sizeof(long)*n);
} 