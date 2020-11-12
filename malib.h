#ifndef MALIB_H
#define MALIB_H
typedef struct {
  size_t timestamp;
  size_t id;
  char* evenement;
  unsigned char puissance;
  short puisRSSI;
  union {
    char* erreur;
    float degOuPulse ;
  };
  size_t* idPN; 
} Entree;


typedef struct {
  size_t valInvalide;
  size_t manifErr;
  size_t cumulErr;
} Compteur;

char* trim(char*);
char** creerTab(char*);
int dimensionX(char*);
void lireLigne(char*, Entree*);
bool validerTab(char**, int , size_t);
bool validerNbrParam(int, int);
bool validerEvenement(char*);
bool validerTimestamp(size_t,size_t);
size_t actualiserTimestamp(size_t, size_t);
Entree* creerEntree(char*, Entree*);
#endif
