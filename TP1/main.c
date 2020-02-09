#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "tri_rapide_decompte.h"
#include "utils.h"
#include "tri_fusion_decompte.h"
#include "tri_inser_decompte.h"

struct argument{
    long* tab;
    long size;
};


void* threadInsert (void* arg){
    struct argument* argum = (struct argument*)arg;
    triInsertion(argum->tab,argum->size);
    pthread_exit(NULL);
}
void* threadFusion (void* arg){
    struct argument* argum = (struct argument*)arg;
    triFusion(argum->tab,argum->size);
    pthread_exit(NULL);
}
void* threadRapide (void* arg){
    struct argument* argum = (struct argument*)arg;
    triRapide(argum->tab,argum->size);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    long tab[5] = {3,8,1,5,2};
    long tab2[8] = {12,8,1,-5,2,-8,6,9};
    long tab3[6] = {7,8,1,2,-8,3};
    long tab4[7] = {1,9,8,7,3,5,6};

    /********************* Test Gen Tab **********************/
    char *ptr;
    long taille = strtol(argv[1],&ptr,10);
    long* tabAlea = malloc(sizeof(long)*taille);
    long* tabAleaCp = malloc(sizeof(long)*taille);
//    long tabCrois[1000000];
//    long tabDeCrois[10];
    createAleaTab(tabAlea,taille,-100,1000);
//    createCroisTab(tabCrois,1000000,-10,100000);
//    createDecroisTab(tabDeCrois,10,-5,20);
//    printf("tab alea \n");
//    printTab(tabAlea,10);
//    printf("tab Crois \n");
//    printTab(tabCrois,10);
//    printf("tab Decrois \n");
//    printTab(tabDeCrois,10);

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

    /********************* Test algo 1 tri par insertionD ***********************/
//    long* tabAleaCp1 = malloc(sizeof(long)*taille);
//    memcpy(tabAleaCp1,tabAlea,sizeof(long)*taille);
//
//    struct argument arg1;
//    arg1.size = taille;
//    arg1.tab = tabAleaCp1;
//    pthread_t triInsert;
//    pthread_create (&triInsert, NULL, threadInsert, &arg1);
//    triInsertion(tabAleaCp,taille);
//    triInsertion(tab2,8);
//    triInsertion(tab3,6);

    /********************* Test algo 2 tri par fusionD **********************/
    long* tabAleaCp2 = malloc(sizeof(long)*taille);
    memcpy(tabAleaCp2,tabAlea,sizeof(long)*taille);

    struct argument arg2;
    arg2.size = taille;
    arg2.tab = tabAleaCp2;
    pthread_t triFus;
    pthread_create (&triFus, NULL, threadFusion, &arg2);
//    triFusion(tabAleaCp,taille);
//    triFusion(tab3,6);
//    triFusion(tab2,8);
//    triFusion(tab,5);

    /********************* Test algo 3 tri rapideD ***********************/
    long* tabAleaCp3 = malloc(sizeof(long)*taille);
    memcpy(tabAleaCp3,tabAlea,sizeof(long)*taille);

    struct argument arg3;
    arg3.size = taille;
    arg3.tab = tabAleaCp3;
    pthread_t triRap;
    pthread_create (&triRap, NULL, threadRapide, &arg3);
    //triRapide(tabAleaCp,100000000);
    //triRapide(tab2,8);
//   triRapide(tab3,6);

    pthread_join(triInsert,NULL);
    pthread_join(triFus,NULL);
    pthread_join(triRap,NULL);
    free(tabAlea);
    free(tabAleaCp1);
    free(tabAleaCp2);
    free(tabAleaCp3);
    return 0;
}
