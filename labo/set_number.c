#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct set_s {
  int size;
  int capacite;
  int *tab;
};

struct set_s* create() {
  struct set_s *vide = malloc(sizeof(struct set_s));
  vide->size = 0, vide->capacite = 1;
  return vide;
}

int find(int elem,struct set_s* ensemble) {
  int i = 0;
  while (i < ensemble->size) {
    if(elem == ensemble->tab[i]) {
      return i;
    }
    ++i;
  }
  return -1;
}

void add(int elem, struct set_s* ensemble ){
  if(elem >= 0) {
   if(find(elem, ensemble) == -1) {
    if(ensemble->capacite <= ensemble->size + 1) {
      int *biggerSet = malloc(sizeof(ensemble->tab[0]) * ensemble->capacite * 2);

      for(int i = 0 ; i < ensemble->size ; ++i) {
        biggerSet[i] = ensemble->tab[i];
      }

      free(ensemble->tab);
      ensemble->tab = biggerSet;
      ensemble->capacite = ensemble->capacite * 2;
    } 

    ensemble->tab[ensemble->size] = elem;
    ensemble->size += 1; 
    printf("\nElement %d ajoute a l'ensemble \n", elem);
  }else printf("\nL'element %d  est deja present dans l'ensemble \n", elem);

 }else printf("\nL'element doit etre positif. \n");
}

void discard(int elem,struct set_s* ensemble) {
  int indice = find(elem,ensemble);
  if(indice != -1) {
    struct set_s* nouveau = create();
     
    for(int i = 0; i < ensemble->size; ++i) {
      if(ensemble->tab[i] != elem) {
        add(ensemble->tab[i],nouveau);
      }
    }
    free(ensemble->tab);
    ensemble->size = nouveau->size;
    ensemble->capacite = nouveau->capacite;
    ensemble->tab = nouveau->tab;
    free(nouveau);
  }else printf("\nL'ensemble ne contient pas cet element. \n");
}

void empty(struct set_s* ensemble) {
  ensemble->size = 0;
  free(ensemble->tab);
  ensemble->tab = malloc(sizeof(ensemble->tab[0]) * ensemble->capacite);
  printf("\nEnsemble vider \n");
}


void afficher(struct set_s* ensemble) {
  printf("\nL'ensemble contient : ");
  for(int i = 0 ; i <ensemble->size; ++i) {
    printf("%d ", ensemble->tab[i]);
  }
  printf("\n");

}
int main(int argc, char **argv) {

  struct set_s *set = create();

  add(3, set);
  add(6, set);
  add(1, set);
  add(6, set);
  afficher(set);
  discard(2, set);
  afficher(set);
  discard(3, set);
  afficher(set);
  empty(set);
  add(5, set);
  add(0, set);
  add(-1, set);
  add(10, set);

  afficher(set);
  
  free(set->tab);
  free(set);
}
