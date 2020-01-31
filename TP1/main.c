#include <stdio.h>
#include "tris.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    long tab[5] = {3,8,1,5,2};
    long tab2[8] = {12,8,1,-5,2,-8,6,9};
    long tab3[6] = {7,8,1,2,-8,3};
    long tab4[7] = {1,9,8,7,3,5,6};

    /********************* Test algo 1 tri par insertion ***********************/
    triInsertion(tab,5);
    triInsertion(tab2,8);
    triInsertion(tab3,6);

    /********************* Test algo 2 tri par fusion ***********************/
    triFusion(tab4,7);
    printf("tab : %ld, %ld, %ld, %ld, %ld, %ld, %ld \n",tab4[0],tab4[1],tab4[2],tab4[3],tab4[4],tab4[5],tab4[6]);

    /********************* Test algo 3 tri rapide ***********************/
    triRapide(tab,5);
    triRapide(tab2,8);
    triRapide(tab3,6);
    return 0;
}
