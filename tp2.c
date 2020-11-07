#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tcv.h"
#include "malib.h"

int main(int argc, char** argv) {
 
  char* str = malloc(sizeof("123456 01 2314 error\n"));

  str = "123345 01 2314 error\n";
  printf("\n %s ", str);
  char* inter;
  inter  = strtok(str, "\n");
 // printf("\n %s \n", inter);
  //char* string = strtok(inter, " ");
  //printf("\n %s \n", string);
  // int x  = dimensionX("12351 01 324 error\n");
  //printf("\n %d \n", x);
  return 0;
}
