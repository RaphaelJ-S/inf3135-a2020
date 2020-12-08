#ifndef MALIB_H
#define MALIB_H
#include "tcv.h"
//Les idpn sauvés
typedef struct idPN_s {
  size_t id;
  size_t* tab;
  int size;
} idPN_t;

//Pour garder l'id sauvé à travers le fichier
typedef struct {
  size_t id;
  unsigned char puissance;
} identifiant_t;

//tous les compteurs (il y en a beaucoup :)
typedef struct {
	//partie générale
	size_t nbrTrxTot;
	size_t trxInval;
	size_t nbrNonSeq; 
	//partie event 04
	size_t nbrSignal;
	//partie event 05
	size_t nbrIdPn;
	//Partie event 03
	size_t valInvPulse;
  size_t manifErrPulse;
  size_t nbrPulse;
	size_t sumPulse;
	//partie event 02
	size_t valInvTA;
  size_t manifErrTA;
  double sumTA;
  size_t nbrTA;
	//partie event 01
	size_t valInvTH;
  size_t manifErrTH;
  double sumTH;
	size_t nbrTH;
} Compteur_t;

//structure contenant toutes les données nécessaires
typedef struct args_s {
  version_t* version;
  unsigned char* options;//0 -t, 1 -i, 2 -d,3 -s
  Compteur_t* cmpt_s;
	identifiant_t* identif_s;
  idPN_t* id_s;
  size_t timestamp;
	char event;
	unsigned char idPwr;
	float degSig;
	signed short pwrSig;
} donnees_t;

void lecture(char*, donnees_t*i);
int cmd(int, char**, donnees_t*);
bool confirmeTimestamp(char*, donnees_t*);
bool confirmeEvenement(char*, donnees_t*);
void affLigne(donnees_t*);
bool confirmeDeux(char*, donnees_t*);
bool confirmeTrois(char*, donnees_t*);
void ajouterIdPN(idPN_t*, size_t);
void affichageCompt(donnees_t*);
bool validerNbrParam(donnees_t*, int);
int validerEvenement(char*);
bool validerDegSig(donnees_t*);
#endif
