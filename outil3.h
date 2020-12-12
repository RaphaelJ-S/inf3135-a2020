
#ifndef _OUTIL3_H_
#define _OUTIL3_H_

#include "struct.h"

int cmd(int, char**, donnees_t*);
float distance(int _signal, int _power);
int comparer(const void*, const void*);
void affichageOptions(donnees_t*);
void affichageLigne(donnees_t*);
void affichageCompt(donnees_t*);
#endif
