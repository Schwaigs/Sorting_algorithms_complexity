#include <stdio.h>
#include "tris.h"

int main() {

  /********************* Test algo 3 ***********************/
  long tab[5] = {3,8,1,5,2};
  triRapide(tab,5);
  long tab2[8] = {12,8,1,-5,2,-8,6,9};
  triRapide(tab2,8);
  long tab3[6] = {7,8,1,2,-8,3};
  triRapide(tab3,6);
  return 0;
}
