#ifndef MALIB_H
#define MALIB_H

typedef struct {
  size_t id;
  unsigned char puissance;
} identifiant_t;

typedef struct {
  size_t valInvalide;
  size_t manifErr;
  size_t cumulErr;
} Compteur_t;
int opAiguillage(char**, identifiant_t*);
char** creerTab(char*);
int dimensionX(char*);
bool validerTab(char**, int , size_t);
bool validerNbrParam(int, int);
bool validerEvenement(char*);
bool validerTimestamp(size_t,size_t);
size_t actualiserTimestamp(size_t, size_t);
#endif
