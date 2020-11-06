#include "stdio.h"
#include "string.h"

int main(int argc, char** argv) {
  char str[50];
  char* pch;
  while(fgets(str, 50, stdin) != NULL) {
    pch = strtok(str, "\n");
    if(pch != NULL) {
    printf("\n%s : ", pch);
    pch = strtok(str, " ");
    while(pch != NULL) {
      printf(" *%s*", pch);
      pch = strtok(NULL, " ");
    }
   }
    
  }
  printf("\n");
  return 0;
}

