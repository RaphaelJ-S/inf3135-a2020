#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include "stack.h"

int main(int argc, char **argv) {
  Pile* prem = create();
  printf("\nsize of Pile : %ld \n", sizeof(*prem));
  printf("\nsize of elem_s : %ld \n", sizeof(struct elem_s));
  push(5,prem);
  printf("\nLa valeur dans le top : %d \n", prem->top->element);
  printf("\nSize : %d \n", prem->size);
  push(10,prem);
  printf("\nLa valeur dans le top : %d \n", prem->top->element);
  printf("\nSize : %d \n", prem->size);
  printf("\nla valeur dans le next : %d \n", prem->top->next->element);
  struct elem_s* ret = pop(prem);
  printf("\nLa valeur de l'element popper : %d \n", ret->element);
  printf("\nLa valeur du top : %d \n", prem->top->element);
  push(20,prem);
  printf("\nLa valeur du top : %d \n", prem->top->element);
  printf("\nLa valeur du next : %d \n", prem->top->next->element);
  free(ret);
  destroy(prem);
}

Pile* create() {
  Pile* new = malloc(sizeof(Pile));
  return new; 
}

void destroy(Pile* stack) {
  while(stack->size != 0) {
    struct elem_s* inter = stack->top;
    while(inter->next != NULL) {
      inter = inter->next;
    }
    free(inter);
    stack->size -= 1;
  }
  free(stack);
}
void push(int element, Pile *stack) {
  if(stack->size == 0) {
    stack->top = malloc(sizeof(struct elem_s));
    stack->top->element=element;
    stack->top->next=NULL;
  }else {
    struct elem_s* inter = stack->top;
    stack->top = malloc(sizeof(struct elem_s));
    stack->top->next = inter;
    stack->top->element = element;
  }
  stack->size += 1;
}

struct elem_s* pop(Pile *stack) {
  struct elem_s* retour = NULL;
  if(stack->size == 0) {
    printf("\nLa pile est vide!\n");
    return retour;
  }else if(stack->size == 1) {
    retour =  stack->top;
    stack->top = NULL;
  }else {
    retour = stack->top;
    stack->top = stack->top->next; 
  }
  stack->size -= 1;
  return retour;  
  
}


struct elem_s* top(Pile *stack) {
  return stack->top;
}
