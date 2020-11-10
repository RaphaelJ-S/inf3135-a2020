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
  while(fgets(str,200, stdin) != NULL) {
    ptr = strtok(str, "\n");
    
    printf("\nData:*%s*\n",ptr);

    ptr = trim(ptr);
    int size = dimensionX(ptr);
    entreeTab = creerTab(ptr);
    if(entreeTab != NULL) {

      for(int i = 0; i < size; ++i) printf("tableau2d[%d]:*%s*\n", i, entreeTab[i]);
    
      if(validerTab(entreeTab, size, prevTimestamp)) printf("%s est valide\n", str);
      else printf("%s n'est pas valide\n", str);
      if(entreeTab[0] != NULL) prevTimestamp = atoll(entreeTab[0]); 
    }
  }
  return 0;
}
