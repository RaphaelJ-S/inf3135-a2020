#include <stdio.h>
#include <tgmath.h>
#include <stdlib.h>

enum Nombre_e {
  INT, FLOAT, DOUBLE
};

typedef struct {
  enum Nombre_e type;
  union {
    int i;
    float f;
    double d;
  } valeur;
} Nombre_t;

Nombre_t max(Nombre_t a, Nombre_t b);

int main( int argc, char **argv ) {
  Nombre_t un={INT, .valeur.i= 14};
  Nombre_t deux={DOUBLE, .valeur.d= 18.4};
  printf("\n\nunion1 i = %d, union2 d = %f \n\n",un.valeur.i, deux.valeur.d);
  Nombre_t rep = max(un, deux);
  if(rep.type == INT) {
    printf("\n\nreponse : %d \n\n", rep.valeur.i);
  }else if(rep.type == FLOAT) {
    printf("\n\nreponse : %f \n\n", rep.valeur.f);
  }else {
    printf("\n\nreponse : %f \n\n", rep.valeur.d);
  }
}

Nombre_t max(Nombre_t a, Nombre_t b) {
 if(a.type == INT) {
   if(b.type == INT) {
     if(a.valeur.i >= b.valeur.i) {
       return a;
     }else { 
       return b; 
     }
   }else if (b.type == FLOAT) {
     if(a.valeur.i >= b.valeur.f) {
       return a;
     }else { 
       return b; 
     }
   
   }else if (b.type == DOUBLE) {
     if(a.valeur.i >= b.valeur.d) {
       return a;
     }else { 
       return b; 
     }
 
   }
 }else if ( a.type == FLOAT ) {
   if(b.type == INT) {
     if(a.valeur.f >= b.valeur.i) {
       return a;
     }else { 
       return b; 
     }
 
   }else if (b.type == FLOAT) {
     if(a.valeur.f >= b.valeur.f) {
       return a;
     }else { 
       return b; 
     }
 
   }else if (b.type == DOUBLE) {
     if(a.valeur.f >= b.valeur.d) {
       return a;
     }else { 
       return b; 
     }
 
 
 }else if ( a.type == DOUBLE) {
   if(b.type == INT) {
     if(a.valeur.d >= b.valeur.i) {
       return a;
     }else { 
       return b; 
     }
 
   }else if (b.type == FLOAT) {
     if(a.valeur.d >= b.valeur.f) {
       return a;
     }else { 
       return b; 
     }
 
   }else if (b.type == DOUBLE) {
     if(a.valeur.d >= b.valeur.d) {
       return a;
     }else { 
       return b; 
     }
   }   
 }
}
}

