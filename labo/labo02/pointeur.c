#include <stdio.h>

int main() {
  
  int entier = 20;
  int *ptr = &entier;
  printf("L'entier : %d\n", entier);
  printf("L'adresse de l'entier : %p\n", &entier);
  printf("L'adresse de ptr : %p\n", ptr);
  printf("La valeur dans ptr : %d\n", *ptr);
  
  int tabEntier[4] = {2,4,6,8};
  int *ptrTab = tabEntier;
  printf("Case 0 du tableau : %d\n", tabEntier[0]);
  printf("L'adresse du tableau : %p\n", &tabEntier);
  printf("L'adresse dans ptrTab : %p\n", ptrTab);
  printf("Les valeurs dans le tableau pointer par ptr : ");
  for(int i = 0 ; i < 4 ; ++i) {
    printf("%d ", ptrTab[i]);
     }  
  printf("\n");
}
