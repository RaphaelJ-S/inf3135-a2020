#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tcv.h"
#include "malib.h"

int main(int argc, char** argv) {
  char** entreeTab;
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
    
    printf("\nData:*%s*\n",ptr);

    int size = dimensionX(ptr);
    entreeTab = creerTab(ptr);
    if(entreeTab != NULL) {

      if(entreeTab[0] != NULL)  {    

        if(validerTab(entreeTab, size, prevTimestamp)){
          printf("Cette entrée est valide\n");
          opAiguillage(entreeTab, &identification, &compte, &idPN );
        } else printf("Cette entrée n'est pas valide\n");
        prevTimestamp = actualiserTimestamp(atol(entreeTab[0]), prevTimestamp);
      }
    }
  }
  affichage(&compte); 
  return 0;
}
