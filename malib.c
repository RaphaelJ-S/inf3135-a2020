#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "malib.h"

void lireEntree(char* ligne) {
//  int dimX = dimensionX(ligne);
//  int dimY = 0;
  
  //char** param;
  
 // while(inter != NULL) {
    
  //}
}
char** creerTab(char*ligne) {
  char** tab;
  char* partie = strtok(ligne, " ");
  int x = dimensionX(ligne);
  tab  = (char**)malloc(x * sizeof(char*));
  for(int i = 0; i < x; i++) {
printf("i : %d, partie : %s \n", i, partie);
    tab[i] = malloc(dimensionY(partie)*sizeof(char));
    tab[i] = partie;
    partie = strtok(NULL, " "); 


  } 
/*
  while( partie != NULL ) {     
    int y = dimensionY(partie);
    printf("\ndimensionY : %d \n", y);
    tab[i] = malloc(y * sizeof(char));
    tab[i] = partie;
    partie = strtok(NULL, " ");
    printf("%s \n", partie);
  }*/ 
  return tab;
}

int dimensionY(char*ligne) {
  
  return strlen(ligne) ;
  
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
