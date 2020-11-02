#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

void afficherMatrice(int (*tab)[3]);
void additionerMatrice(int tab[3][3], int mat[3][3]);

int main(int argc, char **argv) {
 // int matrice[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  //int mat2[3][3] = {{2,5,6}, {11,34,5}, {9, 8, 1}}; 
  //additionerMatrice(matrice, mat2);
 //  afficherMatrice(matrice); 
  return 0;
}

void afficherMatrice(int (*matrice)[3]) {
  printf("\n"); 
  for(int i = 0 ; i < 3; i++) {
    for(int j = 0 ; j < 3 ; j++) {
      printf("%d ", matrice[i][j]);
    }
    printf("\n");
  }
}

void additionerMatrice(int matrice1[3][3], int matrice2[3][3]) {
  afficherMatrice(matrice1);
  printf("+");
  afficherMatrice(matrice2);
  printf("=\n");
  for(int i = 0 ; i < 3 ; i++) {
    
    for(int j = 0 ; j < 3 ; j++) {
      printf("%d ", matrice1[i][j] + matrice2[i][j]);
    } 
    printf("\n");
  }
}
