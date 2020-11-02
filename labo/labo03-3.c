#include <stdio.h>

unsigned int trouver(const double tableau[], unsigned int taille, double element);

int main(int argc, char **argv) {
  const double tableau[] = {12.5, 12.4, 24.0};
  double element = 12.4;
  printf("\n%u longueur\n", 3);
  return trouver(tableau, 3, element);
}


unsigned int trouver(const double tableau[], unsigned int taille, double element) {
  for(int i =0 ; i < taille ; i++) {
    if(tableau[i] == element) {
      return i;
    }
  }
  return 0;
}
