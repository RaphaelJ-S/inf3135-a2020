#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chaine(int nbrE, char **argv);
void renverse(int nbrE, char** argv);

int main(int argc, char **argv) {
  chaine(argc,argv);
  renverse(argc, argv);
  return 0;
}

void chaine(int nbrE, char** argv) {
  char concat[100];
  for(int i = 1 ; i < nbrE ; i++) {
    strcat(concat, argv[i]);
  } 
  printf("\nLes arguments à l'endroit: %s\n",concat);
}

void renverse(int nbrE, char** argv) {
  char* envers = malloc(strlen(argv[2])+strlen(argv[1]) +1);
  for(int i = (nbrE - 1) ; i > 0 ; --i) {
    strcat(envers, argv[i]);
  } 
 // strcat(concat, argv[nbrE - 1]);
  printf("\nLes arguments à l'envers : %s \n",envers );
  free(envers);
}
