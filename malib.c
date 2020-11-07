#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "malib.h"

void lireEntree(char* ligne) {
  char* inter = strtok(ligne, " ");
//  int dimX = 0;
 // int dimY = 0;
  //char** param;
  
  while(inter != NULL) {
    
  }
}

int dimensionX(char*ligne) {
  char* partie = strtok(ligne, " ");
  int x = 0;
  while(partie != NULL) {
    partie = strtok(NULL, " ");
    ++x;
  }
  return x;
}

bool validerEntree(char** param) {
  return true;
}

Entree* creerEntree(char*ligne, Entree* vide) {
  
  return vide;
}
