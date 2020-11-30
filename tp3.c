#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tcv.h"
#include "malib.h"

int main(int argc, char** argv) {
  char** entreeTab = (char**)malloc(sizeof(*entreeTab)); 
  char str[200];
  char* ptr;
  size_t prevTimestamp = 0;
  identifiant_t identification = {9999, 2};
  Compteur_t compte = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  idPN_t idPN = {malloc(sizeof(size_t)), 0};
  
  version_t pres;
  getVersion(&pres);
  printf("version #: 0.1.%d\n", pres.build);

  while(fgets(str,200, stdin) != NULL) {
    ptr = strtok(str, "\n");
    int size = dimensionX(ptr);
    entreeTab = creerTab(ptr, entreeTab, size);
    #ifdef _ERR_
      printf("E1 : ");
      for(int i =0; i<size ; ++i) {
        printf("-%s-", entreeTab[i]);
      }
      printf("\n");
    #endif 
    if(entreeTab != NULL) {

      if(entreeTab[0] != NULL)  {    

        if(validerTab(entreeTab, size, prevTimestamp)){
          opAiguillage(entreeTab, &identification, &compte, &idPN );

    #ifdef _ERR_
      printf("E2 : ");
      for(int i =0; i<size ; ++i) {
        printf("-%s-", entreeTab[i]);
      }
      printf("\n");
    #endif 
 
       }
        prevTimestamp = actualiserTimestamp(atol(entreeTab[0]), prevTimestamp);
      }
    }
    #ifdef _ERR_
      printf("E3 : ");
      for(int i =0; i<size ; ++i) {
        printf("-%s-", entreeTab[i]);
      }
      printf("\n");
    #endif 
     
  }
  free(entreeTab);
  free(idPN.tab);
  affichage(&compte); 
  return 0;
}
