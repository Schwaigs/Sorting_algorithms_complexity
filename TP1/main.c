#include <stdio.h>
#include "triFusion.h"

int main(int argc, char* argv[]) {
    long tab[] = {1,9,8,7,3,5,6};

    triFusion(tab,7);
    printf("tab : %ld, %ld, %ld, %ld, %ld, %ld, %ld \n",tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6]);
}