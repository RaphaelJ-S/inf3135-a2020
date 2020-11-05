#include <stdio.h>

typedef struct{
  int size;
  int capacity;
  char **phrase;
} setString; 

setString creer();

void ajouter(char* mot, setString *ensemble);

void enlever(char *word, setString* ensemble);

int trouver(char *word, setString *ensemble);

void vider(setString *ensemble);

void afficher(setString* ensemble);
