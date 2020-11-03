#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv) {
  Pile* prem = create();

  push(5,prem);

  push(10,prem);

  pop(prem);

  push(20,prem);

  push(30,prem);

  push(40,prem);

  push(50,prem);
  destroy(prem);
  
}

Pile* create() {
  Pile* nouveau= malloc(sizeof(Pile));
  return nouveau; 
}

void destroy(Pile* stack) {

  struct elem_s* inter;
  struct elem_s* head = stack->top;
  while(head != NULL) {
      inter = head;
      head = head->next;
      free(inter);
      stack->size -= 1;     
  }
  free(stack);
}

void push(int element, Pile *stack) {

  struct elem_s* inter = stack->top;
  stack->top = malloc(sizeof(struct elem_s));

  if(stack->size == 0) {
    stack->top->next=NULL;
  }else {
    stack->top->next = inter;
  }
  
  stack->top->element = element;
  stack->size += 1;
  printf("\nLa nouvelle valeur top : %d et le nombre de node est : %d \n", stack->top->element, stack->size);
}

void pop(Pile *stack) {
  if(stack->size != 0) {

    printf("\nLa valeur popper est : %d et le nombre de node est : %d \n", stack->top->element, stack->size - 1);
    if(stack->size == 1) {
      free(stack->top);
      stack->top = NULL;
    }else {
      struct elem_s* tmp = stack->top;
      stack->top = stack->top->next; 
      free(tmp);
    }

    stack->size -= 1;
  }else {
    printf("\nLa pile est vide!\n");
  }
}


struct elem_s* peek(Pile *stack) {
  return stack->top;
}
