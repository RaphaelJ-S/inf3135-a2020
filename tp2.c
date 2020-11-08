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
    ptr = trim(ptr);
    int size = dimensionX(ptr);
    entreeTab = creerTab(ptr);
    if(validerTab(entreeTab, size, prevTimestamp)) {

      printf("Valide\n");
    }
    prevTimestamp = atoll(entreeTab[0]); 
  }
  return 0;
}
