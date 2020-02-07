#include <stdio.h>
#include "tri_rapide_decompte.h"
#include "utils.h"
#include "tri_fusion_decompte.h"

int main(int argc, char* argv[]) {
    long tab[5] = {3,8,1,5,2};
    long tab2[8] = {12,8,1,-5,2,-8,6,9};
    long tab3[6] = {7,8,1,2,-8,3};
    long tab4[7] = {1,9,8,7,3,5,6};

    /********************* Test Gen Tab **********************/
    long tabAlea[10];
    long tabCrois[10];
    long tabDeCrois[10];
    createAleaTab(tabAlea,10,-5,5);
    createCroisTab(tabCrois,10,-10,5);
    createDecroisTab(tabDeCrois,10,-5,20);
    printf("tab alea \n");
    printTab(tabAlea,10);
    printf("tab Crois \n");
    printTab(tabCrois,10);
    printf("tab Decrois \n");
    printTab(tabDeCrois,10);

    /********************* Test algo 1 tri par insertion ***********************/
//    triInsertion(tab,5);
//    triInsertion(tab2,8);
//    triInsertion(tab3,6);

    /********************* Test algo 2 tri par fusion ***********************/
//    triFusion(tab4,7);
//    triFusion(tab3,6);
//    triFusion(tab2,8);
//    triFusion(tab,5);

    /********************* Test algo 3 tri rapide ***********************/
//    triRapide(tab,5);
//    triRapide(tab2,8);
//    triRapide(tab3,6);

    /********************* Test algo 2 tri par fusionD **********************/
    //triFusion(tab4,7,&p);
//    triFusion(tab3,6);
//    triFusion(tab2,8);
//    triFusion(tab,5);

    /********************* Test algo 3 tri rapide ***********************/
    //triRapide(tab,5);
    //triRapide(tab2,8);
    triRapide(tab3,6);
    return 0;
}
