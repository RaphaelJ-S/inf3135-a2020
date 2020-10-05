#include <stdio.h>

int main() {
  for(int i = -200 ; i < 201 ; i++) {
    
    char c = (char)i;
    int t = (int)c;

    printf("i = %d, c = %c, t = %d \n", i, c, t);
  }
  return 0;
}
