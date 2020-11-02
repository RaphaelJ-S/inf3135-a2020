#include <stdio.h>



union L64 {
  unsigned long n;
  struct {
    unsigned int lo;
    unsigned int hi;
  };
};

