#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set_string.h"

int main(int argc, char** argv){
  setString ens = creer();
  ajouter("salut", &ens);
  afficher(&ens);
  ajouter("bonjour", &ens);
  ajouter("allo", &ens);
  ajouter("salut", &ens);
  afficher(&ens);
  ajouter("vraiment", &ens);
  ajouter("trueman", &ens);
  afficher(&ens);
  enlever("allo", &ens);
  afficher(&ens);
}

setString creer(){
  setString construit;
  construit.size = 0;
  construit.capacity = 1;
  construit.phrase = (char**)malloc(sizeof(char*));
  return construit;
}

void ajouter(char* mot, setString* ensemble){
  if(trouver(mot, ensemble) == -1 ) {
    if(ensemble->capacity <= ensemble->size) {
      char **nv = (char **)malloc(sizeof(char*)*ensemble->size * 5);
      for(int i =0 ; i < ensemble->size; ++i) {
        nv[i] = ensemble->phrase[i];
      }
      free(ensemble->phrase); 
      ensemble->capacity *= 5;
      ensemble->phrase = nv;
    } 
    ensemble->phrase[ensemble->size] = malloc(strlen(mot));
    ensemble->phrase[ensemble->size]= mot;
    ensemble->size += 1;
  } else printf("\nLe mot %s est déjà dans l'ensemble \n", mot);

}

void enlever(char* mot, setString *ensemble) {
  int indice = trouver(mot, ensemble);
  if(indice != -1) {
    setString nv = creer(); 
    for(int i = 0; i < ensemble->size; ++i) {
      if(strcmp(mot, ensemble->phrase[i]) != 0) {
        ajouter(ensemble->phrase[i], &nv);
      }
    }
    free(ensemble->phrase);
    ensemble->phrase = nv.phrase;
    ensemble->capacity = nv.capacity;
    ensemble->size = nv.size;
    printf("\nLe mot %s est enlevé de l'ensemble \n", mot);
  }else printf("\nLe mot '%s' ne fait pas parti de l'ensemble. \n", mot);
}

int trouver(char* mot, setString* ensemble) {
  for(int i = 0 ; i < ensemble->size; ++i) {
    if(strcmp(mot,ensemble->phrase[i])==0) {
      return i;
    }
  }
  return -1;
}
//fonctionne pas 
void vider(setString* ensemble) {
  for(int i =1; i < ensemble->size; ++i) {
    printf("\nÉtape vider i = %d \n", i);
    free(ensemble->phrase[i]);
  }
  free(ensemble->phrase);
  printf("\nÉtape vider free phrase \n");
}

void afficher(setString* ensemble) {
  printf("\nL'ensemble :");
  for(int i = 0; i < ensemble->size; ++i) {
    printf(" %s", ensemble->phrase[i]);
  }
  printf("\n");
}
