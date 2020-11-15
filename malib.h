#ifndef MALIB_H
#define MALIB_H

typedef struct {
  size_t id;
  unsigned char puissance;
} identifiant_t;

typedef struct {
  size_t sumPulse;
  float sumTA;
  float sumTH;
  size_t nbrPulse;
  size_t nbrTA; 
  size_t nbrTH;
  size_t valInvPulse;
  size_t manifErrPulse;
  size_t cumulErrPulse;
  size_t valInvTA;
  size_t manifErrTA;
  size_t cumulErrTA;
  size_t valInvTH;
  size_t manifErrTH;
  size_t cumulErrTH;
} Compteur_t;

void affichage(Compteur_t*);
void opAiguillage(char**, identifiant_t*, Compteur_t*);
char** creerTab(char*);
int dimensionX(char*);
bool validerTab(char**, int , size_t);
bool validerNbrParam(int, int);
bool validerEvenement(char*);
bool validerTimestamp(size_t,size_t);
size_t actualiserTimestamp(size_t, size_t);
#endif
