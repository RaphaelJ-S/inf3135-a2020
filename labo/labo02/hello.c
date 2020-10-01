#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void boucleAvant(int x);
void boucleApres(int x);
int racineCarreEntiere(int x);
int somme();
bool estTrie();
void ligneDeCommande(int argc, char *argv[]);
int elementPlusFrequent(int tableau[]);

int main(int argc, char **argv) {
  
  int tabEntier[10] = {1,1,1,2,2,3,3,3,3,5};
    
  
  ligneDeCommande(argc, argv); 
  boucleAvant(4);
  boucleApres(3);
  printf("Tableau trie? : %s\n", estTrie()? "true": "false");
  printf("La valeur de l'élément le plus fréquent est %d\n", elementPlusFrequent(tabEntier));
  
  //  printf("Racine de 4 : %f\n", sqrt (1024.0));
  return 0;
}

int elementPlusFrequent(int tableau[]) {
  int longueur = 10;
  int freq = 0;
  int max = 0;
  int pos = 0;
  for ( int i = 0 ; i < longueur ; ++i) {
    freq = 1; 
    for(int j = 0 ; j < longueur ; ++j) {
      if(tableau[i] == tableau[j]) {
        freq += 1;
      }  
    }
    if(freq > max) {
      max = freq;
      pos = i;
    }
  }
  return tableau[pos]; 
}
void ligneDeCommande(int argc, char **argv) {
  char args[30];
  printf("Bonjours ");
  
  for(int i = 0 ; i < argc ; ++i) {
    if(i != 0) {
      printf("%s ", argv[i]);
    }
  }
  printf("\n");
}
bool estTrie() {
  int tab[6] = {1,2,3,4,5,6};
  int longueur = sizeof(tab) / sizeof(tab[0]);
  bool trier = true;
  int i = 0; 
  while(trier && i < longueur - 1) {
	  
     if(tab[i] > tab[i + 1]) {
       trier = false;
     }
    ++i;
  }
  return trier;
}
int somme() { 
  
  int n,  result = 0;
  int tableau[5] = {4, 4, 2, 5, 1};
  n = sizeof(tableau) / sizeof(tableau[0]); 
  
  for(int i = 0 ; i < n ; ++i) {
    result += tableau[i];
  }  
  return result;
}
/*
int racineCarreEntiere(int x) {
  return sqrt(x); 
}
*/

void boucleApres(int x) {
  for(int j= 0 ; j < x ; j++) {
    printf("Boucle après : %d\n", j);
  }
}
void boucleAvant(int x) {
  for(int i =0; i < x ; ++i) {
    printf("Boucle avant : %d\n", i);
  }
}
