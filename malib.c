#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>
#include "malib.h"
#include "tcv.h"  

int cmd(int argc, char** argv, donnees_t* data) {
	for(int i = 1; i < argc; ++i) {
		if(strcmp(argv[i], "-t") == 0) data->options[0] = (char)1;
		else if (strcmp(argv[i], "-i") == 0) data->options[1] = (char)1;
		else if (strcmp(argv[i], "-d") == 0) data->options[2] = (char)1;
		else if (strcmp(argv[i], "-s") == 0) data->options[3] = (char)1;
		else return -1;
	}
	return 0;
}
void lecture(char* ligne, donnees_t* data) {
	if(ligne != NULL) {
  	char* delim =" ";
		bool valide = true; 
		int i = 0;
		if(*ligne != '\0') {
  		char* partie = strtok(ligne,delim);
    	while(partie && valide) {
      	if(i == 0) valide = confirmeTimestamp(partie, data); 
				else if (i == 1) valide = confirmeEvenement(partie, data);
				else if (i == 2) valide = confirmeDeux(partie, data);
				else if (i == 3) valide = confirmeTrois(partie, data);
				partie = strtok(NULL,delim);
      	++i;
    	}
			#ifdef _ERR_
				printf("\n\ndata : \nVersion: %d.%d.%d\nOptions: %d%d%d%d\nidentifidant :%ld %d\nIDPN : %d\nTime : %ld\nEvenement : %c\nUnion : %d %f %d %s\n\n",data->version->major, data->version->minor, data->version->build,data->options[0], data->options[1], data->options[2], data->options[3], data->identif_s->id, data->identif_s->puissance, data->id_s->size, data->timestamp,data->event, data->idPwr, data->degSig, data->pwrSig, data->string);
				#endif
			validerNbrParam(i, data);
		}
  }     
}

bool confirmeDeux(char* partie, donnees_t* data) {
	char event = data->event;
	int err = strcmp(partie, "ERREUR");
	if(event == 0) {
		data->identif_s->id = atol(partie);
	}else if (event == 1 || event == 2 || event == 3){
		if(err == 0){
			data->string = partie;
			if(event == 1) data->cmpt_s->manifErrTA += 1;
			if(event == 2) data->cmpt_s->manifErrTH += 1;
			if(event == 3) data->cmpt_s->manifErrPulse += 1;
		}else data->degSig = atof(partie);

	}else if (event == 4) {
		data->pwrSig = (short)atoi(partie);
  }
	return true;
}
bool confirmeTrois(char* partie, donnees_t* data) {
	char event = data->event;
	if(event == 0) {
		int pwr = atoi(partie);
		if(pwr == 2||pwr == 3||pwr == 4) {
			data->identif_s->puissance = (unsigned char)pwr;	
		}else {
			data->cmpt_s->trxInval += 1; 
			return false;
		}
	}else if(event == 4) {
		ajouterIdPN(data->id_s, atol(partie));
	}
	return true;
}

bool confirmeEvenement(char* partie, donnees_t* data) {
	int evenement = validerEvenement(partie, data);
  if(evenement == -1) return false;
	else {
		data->event = evenement;
		return true;
	}
}
int validerEvenement(char* partie, donnees_t* data) {
  int i = 0;
  char eveneVal[6][2] = {{"00"},{"01"},{"02"},{"03"},{"04"},{"05"}};

  if(strlen(partie) == 2) {
    while(i < 6) {
       if((int)partie[0] == (int)eveneVal[i][0] && (int)partie[1] == (int)eveneVal[i][1]) return atoi(partie); 
       ++i;
    }
  }
	data->cmpt_s->trxInval += 1;
  return -1;
}
bool confirmeTimestamp(char* partie, donnees_t* data) {
	size_t timestamp = atol(partie);
	if(data->timestamp > timestamp) {
		data->cmpt_s->nbrNonSeq += 1;
		return false;
	}else {
		data->timestamp = timestamp;
		return true;
	}
}
bool validerNbrParam(int size, donnees_t* data) {
  int evenement = data->event; 
  return ((evenement == 0 ||evenement == 4) ? (size != 4 ? false : true) 
         : (evenement == 1 ||evenement == 2 ||evenement ==3) ? (size != 3 ? false : true)
         : (evenement == 5) ? (size < 4 ? false : true) 
         : false);
}
void affichage(Compteur_t* compte) {
  float moyTA = 0;
  float moyTH = 0;
  size_t moyP = 0;

  if(compte->nbrTA != 0) moyTA = compte->sumTA/compte->nbrTA;
  if(compte->nbrTH != 0) moyTH = compte->sumTH/compte->nbrTH;
  if(compte->nbrPulse != 0 ) moyP = round(compte->sumPulse/compte->nbrPulse);

  printf("21 %.1f %.1f %ld\n",moyTH, moyTA, moyP);

  printf("22 %ld %ld %ld\n", compte->valInvTH, compte->valInvTA, compte->valInvPulse);
 
  printf("23 %ld %ld %ld\n", compte->cumulErrTH, compte->cumulErrTA, compte->cumulErrPulse); 
}

void ajouterIdPN(idPN_t* idPN, size_t nvElem) {
  idPN->tab = realloc(idPN->tab, sizeof(size_t) * (idPN->size+1));
  idPN->tab[idPN->size] = nvElem;
  idPN->size += 1; 
}
/*
static void opEvent05(char** tab, identifiant_t* identification, idPN_t* idPN) {
  printf("15 %ld %ld ", atol(tab[0]), identification->id);
  for(int i = 0; i < idPN->size; ++i) {
    printf("%ld ", idPN->tab[i]);
  }
  printf("\n");
}

static void opEvent04(char** tab, identifiant_t* identification, idPN_t* idPN) {
  int sig = atoi(tab[2]);
  version_t v;
  getVersion(&v);
  bool valide = v.build >= 1005 && v.build <= 1008 ? validerSignal_3((short)sig) 
              : v.build <= 1003 ? validerSignal_2((char)sig) : false;  
  if(valide) {
    size_t timestamp = atol(tab[0]);
    size_t id = atol(tab[3]);
    float metre = pow(10.0, ((-69 - (sig))/(10.0*identification->puissance))); 
    ajouterIdPN(idPN, id);
    printf("14 %ld %ld %.1f\n", timestamp, id, round(metre*10)/10); 

  } 
}
static void opEvent03(char* temperature, Compteur_t* compte) {
  int pulse = atoi(temperature);
  version_t v;
  getVersion(&v);
  bool valide = v.build >= 1005 && v.build <= 1008 ? validerPulsation_1(pulse) 
              : v.build <= 1003 ? validerPulsation_3((short)pulse) : false;  

  if(strcmp(temperature, "ERREUR") == 0) {
    compte->manifErrPulse += 1;
    if(compte->manifErrPulse == 3) {
      compte->manifErrPulse = 0;
      compte->cumulErrPulse += 1;
    }
  } else if(valide) {
      compte->sumPulse += pulse;
      compte->nbrPulse += 1;
  } else compte->valInvPulse += 1;
}

static void opEvent02(char* temperature, Compteur_t* compte) {
  int tempA = atof(temperature) * 10;
  version_t v;
  getVersion(&v);
  bool valide = v.build >= 1005 && v.build <= 1008 ? validerTA_1(tempA) 
              : v.build <= 1003 ? validerTA_3((short)tempA) : false;  

 
  if(strcmp(temperature, "ERREUR") == 0) {
    compte->manifErrTA +=1;
    if(compte->manifErrTA == 3) {
      compte->manifErrTA = 0;
      compte->cumulErrTA += 1;
    }
  } else if(valide){
      compte->sumTA += (float)tempA/10.0;
      compte->nbrTA += 1;
  } else compte->valInvTA += 1; 
}

static void opEvent01(char* temperature, Compteur_t* compte) {
  int tempH = atof(temperature)* 10; 

  version_t v;
  getVersion(&v);
  bool valide = v.build >= 1005 && v.build <= 1008 ? validerTH_1(tempH) 
              : v.build <= 1003 ? validerTH_1(tempH) : false;  


  if(strcmp(temperature, "ERREUR") == 0){
    compte->manifErrTH += 1;
    if(compte->manifErrTH == 3) {
      compte->manifErrTH = 0;
      compte->cumulErrTH += 1;
    }
  } else if (valide) {
      compte->sumTH += (float)(tempH/10.0);
      compte->nbrTH += 1;
  } else compte->valInvTH += 1;
}
static void opEvent00(char** tab, identifiant_t* precedent) {
  int puissance= atoi(tab[3]);
  precedent->id = atol(tab[2]);
  precedent->puissance = puissance==2||puissance==3||puissance==4 ? puissance : 2;
  printf("10 %ld %ld %d\n",atol(tab[0]), precedent->id, precedent->puissance);
}
void opAiguillage(char** tab, identifiant_t* identification, Compteur_t* compte, idPN_t* idPN) {
  char* mesure = tab[2];
  switch (atol(tab[1])) {
    case(0):
      opEvent00(tab, identification);
      break;
    case(1):
      opEvent01(mesure, compte);     
      break;
    case(2):
      opEvent02(mesure, compte);
      break;
    case(3):
      opEvent03(mesure, compte);
      break;
    case(4):
      opEvent04(tab, identification, idPN);
      break;
    case(5):
      opEvent05(tab, identification,  idPN);
      break;
  } 
}
*/




