#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tcv.h"
#include "malib.h"

int main(int argc, char** argv) {
  int i =0;
  char str[] = "123456 01 2314 error\n";
  char** tableau = creerTab(str);
  printf("\n");
  while(i < dimensionX(str)) {
    printf("- %s -", tableau[i]);
    i++;
  } 
  printf("\n"); 
  return 0;
}
