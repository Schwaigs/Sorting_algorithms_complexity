#include <stdio.h>
#include "tris.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    /********************* Test algo 2 ***********************/
    long tab[] = {1,9,8,7,3,5,6};

    triFusion(tab,7);
    printf("tab : %ld, %ld, %ld, %ld, %ld, %ld, %ld \n",tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6]);

  /********************* Test algo 3 ***********************/
//  long tab[5] = {3,8,1,5,2};
//  triRapide(tab,5);
//  long tab2[8] = {12,8,1,-5,2,-8,6,9};
//  triRapide(tab2,8);
//  long tab3[6] = {7,8,1,2,-8,3};
//  triRapide(tab3,6);
  return 0;
}
