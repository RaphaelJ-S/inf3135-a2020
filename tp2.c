#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tcv.h"
#include "malib.h"

int main(int argc, char** argv) {
  char str[200];
  char* ptr;
  char** entreeTab;
  size_t prevTimestamp = 0;
  identifiant_t identification = {9000, 2};
  while(fgets(str,200, stdin) != NULL) {
    ptr = strtok(str, "\n");
    
    printf("\nData:*%s*\n",ptr);

    int size = dimensionX(ptr);
    entreeTab = creerTab(ptr);
    if(entreeTab != NULL) {

      for(int i = 0; i < size; ++i) printf("tableau2d[%d]:*%s*\n", i, entreeTab[i]);

      if(entreeTab[0] != NULL)  {    
        printf("Timestamp prev : %ld , curr: %ld\n", prevTimestamp, atol(entreeTab[0]));
        if(validerTab(entreeTab, size, prevTimestamp)){
          printf("Cette entrée est valide\n");
          opAiguillage(entreeTab, &identification);
        } else printf("Cette entrée n'est pas valide\n");
        prevTimestamp = actualiserTimestamp(atol(entreeTab[0]), prevTimestamp);
        
        
      }
    }
  }
  return 0;
}
