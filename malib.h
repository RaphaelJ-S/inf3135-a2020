#ifndef MALIB_H
#define MALIB_H
#include "tcv.h"
//Les idpn sauvés
typedef struct idPN_s {
  size_t* tab;
  int size;
} idPN_t;

//Pour garder l'id sauvé à travers le fichier
typedef struct {
  size_t id;
  int puissance;
} identifiant_t;

//tous les compteurs (il y en a beaucoup :)
typedef struct {
	size_t nbrTrxTot;
	size_t trxInval;
	size_t nbrNonSeq; 
	size_t sumPulse;
  double sumTA;
  double sumTH;
  size_t nbrPulse;
  size_t nbrTA; 
  size_t nbrTH;
	size_t nbrSignal;
	size_t nbrIdPn;
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

//structure contenant toutes les données nécessaires
typedef struct args_s {
  version_t version;
  unsigned short* options;//0 -t, 1 -i, 2 -d,3 -s
  Compteur_t cmpt_s;
	identifiant_t identif_s;
  idPN_t id_s;
	size_t timestamp;
	char opt[3];
	union {
		unsigned char idPwr;
		float degSig;
		signed short pwrSig;
		char erreur[7];
	};	
} donnees_t;

int cmd(int , char**, donnees_t*);
void affichage(Compteur_t*);
void opAiguillage(char**, identifiant_t*, Compteur_t*, idPN_t*);
char** creerTab(char*, char**, int);
int dimensionX(char*);
bool validerTab(char**, int , size_t);
bool validerNbrParam(int, int);
bool validerEvenement(char*);
bool validerTimestamp(size_t,size_t);
size_t actualiserTimestamp(size_t, size_t);
#endif
