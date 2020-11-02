#include <stdio.h>

struct elem_s {
  int element;
  struct elem_s *next; 
};

typedef struct Pile_s {
  int size;
  struct elem_s *top;
} Pile;

Pile* create();

void push(int element, Pile *stack);

struct elem_s* pop(Pile *stack);

struct elem_s* top(Pile *stack);

void destroy(Pile* stack);
