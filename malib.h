
#ifndef MALIB_H
#define MALIB_H
#include "struct.h"
#include "tcv.h"
#include "outil3.h"

void lecture(char*, donnees_t*i);
int cmd(int, char**, donnees_t*);
bool confirmeTimestamp(char*, donnees_t*);
bool confirmeEvenement(char*, donnees_t*);
bool confirmeDeux(char*, donnees_t*);
bool confirmeTrois(char*, donnees_t*);
void ajouterIdPN(idPN_t*, size_t);
bool validerNbrParam(donnees_t*, int);
int validerEvenement(char*);
bool validerDegSig(donnees_t*);

#endif
