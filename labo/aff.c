#include <stdio.h>

int main () {

  /*
  for(int i = -300 ; i < 301 ; i++ ) {
    printf("\nint = %d, short = %d", i, (short)i);
  }
  */
  printf("\n\nDe 0 à 255\n");
  for(int i = 0 ; i <256 ; i++) {
    printf("intchar = %c\n", i);
 
  }
  printf("\n\nDe -128 à 127\n");
  for(int j = -128 ; j < 128 ; j++) {
    printf("charcast = %c\n", j);
  }
  return 0;
  
}
