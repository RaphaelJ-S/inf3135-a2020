#include <stdio.h>
#include "labo06-5.h"
#include <limits.h>

int main(int argc, char **argv) {
  union L64 uni;
  uni.n = (unsigned long)12345;
  printf("\n\nlo : %d  hi : %d \n\n", uni.lo, uni.hi);
  uni.n = (unsigned long)ULONG_MAX-10;
  printf("\n\nlong_max = %lu \nlong_max-10 = %lu \nint_max = %d \nint_max-10 =%d \n\n",ULONG_MAX, ULONG_MAX-10, (int)ULONG_MAX, (int)ULONG_MAX-10);
  printf("\n\nlo : %d hi : %d \n\n", uni.lo, uni.hi);

}

