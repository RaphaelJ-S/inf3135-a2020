#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>
#include "malib.h"
#include "tcv.h"  

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

static void ajouterIdPN(idPN_t* idPN, size_t nvElem) {
  idPN->tab = realloc(idPN->tab, sizeof(size_t) * (idPN->size+1));
  idPN->tab[idPN->size] = nvElem;
  idPN->size += 1; 
}

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
  if((puissance == 2)||(puissance == 3)||(puissance == 4)) {
    precedent->id = atol(tab[2]);
    precedent->puissance = puissance;
    printf("10 %ld %ld %d\n",atol(tab[0]), atol(tab[2]), puissance);
  }
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

char** creerTab(char* ligne, char** entreeTab, int size) {
  char** tmpTab = (char**)realloc(entreeTab,size *sizeof(*entreeTab));
  assert(tmpTab);
  if(ligne != NULL) {
    char* delim =" ";
    int i = 0;

    if(*ligne != '\0') {
      char* partie = strtok(ligne,delim);
      while(partie != NULL) {
        tmpTab[i] =(char*) malloc(strlen(partie));
        tmpTab[i] = partie;
        partie = strtok(NULL,delim);
        ++i;
      }
    }
  }
  return tmpTab;
}

int dimensionX(char*ligne) {
  int x = 0;
  if(ligne != NULL) {
    char tmp[200];
    strcpy(tmp,ligne);

    char* partie = strtok(tmp, " ");
    while(partie != NULL) {
      partie = strtok(NULL, " ");
      ++x;
    }
  }
  return x;
}

bool validerTab(char** param, int size, size_t prevTimestamp) {
  int evenement ;
  size_t timeStamp;
   
  if(size > 2) {
    evenement = atoi(param[1]);
    timeStamp = atol(param[0]);
 
    if(!validerEvenement(param[1]))return false;
    if(!validerNbrParam(evenement, size)) return false;
    if(!validerTimestamp(timeStamp, prevTimestamp)) return false;
    return true; 
  }
  return false;
}

bool validerTimestamp(size_t timeStamp, size_t prevTimestamp) {
  return timeStamp >= prevTimestamp;
}

size_t actualiserTimestamp(size_t timestamp, size_t prevTimestamp) {
  if (validerTimestamp(timestamp, prevTimestamp)) return timestamp;
  else return prevTimestamp; 
}

bool validerEvenement(char* param) {
  int i = 0;
  char eveneVal[6][2] = {{"00"},{"01"},{"02"},{"03"},{"04"},{"05"}};

  if(strlen(param) == 2) {
    while(i < 6) {
       if((int)param[0] == (int)eveneVal[i][0] && (int)param[1] == (int)eveneVal[i][1]) return true; 
       ++i;
    }
  }
  return false;
}

bool validerNbrParam(int evenement, int size) {
  
  return ((evenement == 0 ||evenement == 4) ? (size != 4 ? false : true) 
         : (evenement == 1 ||evenement == 2 ||evenement ==3) ? (size != 3 ? false : true)
         : (evenement == 5) ? (size < 4 ? false : true) 
         : false);
}

