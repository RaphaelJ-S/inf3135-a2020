#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
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
static void opEvent04(char** tab, identifiant_t* identification) {
  short sig = atoi(tab[2]);
  char signal = sig;
  
  if(validerSignal_2(signal)) {
    size_t timestamp = atol(tab[0]);
    size_t id = atol(tab[3]);
    float metre = pow(10, ((-69 - (sig))/(10*identification->puissance))); 
    printf("14 %ld %ld %.1f\n", timestamp, id, metre); 
  } 
}
static void opEvent03(char* temperature, Compteur_t* compte) {
  short pulse = atoi(temperature);

  if(strcmp(temperature, "ERREUR") == 0) {
    compte->manifErrPulse += 1;
    if(compte->manifErrPulse == 3) {
      compte->manifErrPulse = 0;
      compte->cumulErrPulse += 1;
    }
  } else if(validerPulsation_3(pulse)) {
      compte->sumPulse += pulse;
      compte->nbrPulse += 1;
  } else compte->valInvPulse += 1;
}

static void opEvent02(char* temperature, Compteur_t* compte) {
  short tempA = atof(temperature) * 10;
  
  if(strcmp(temperature, "ERREUR") == 0) {
    compte->manifErrTA +=1;
    if(compte->manifErrTA == 3) {
      compte->manifErrTA = 0;
      compte->cumulErrTA += 1;
    }
  } else if(validerTA_3(tempA)) {
      compte->sumTA += (float)tempA/10.0;
      compte->nbrTA += 1;
  } else compte->valInvTA += 1; 
}
static void opEvent01(char* temperature, Compteur_t* compte) {
  int tempH = atof(temperature)* 10; 
   
  if(strcmp(temperature, "ERREUR") == 0){
    compte->manifErrTH += 1;
    if(compte->manifErrTH == 3) {
      compte->manifErrTH = 0;
      compte->cumulErrTH += 1;
    }
  } else if (validerTH_1(tempH)) {
      compte->sumTH += (float)(tempH/10.0);
      compte->nbrTH += 1;
  } else compte->valInvTH += 1;
   
}

static void opEvent00(char** tab, identifiant_t* precedent) {
  unsigned char puissance= tab[3][0];
  if((puissance == '2')||(puissance == '3')||(puissance == '4')) {
    precedent->id = atol(tab[2]);
    precedent->puissance = puissance;
    printf("10 %ld %ld %c\n",atol(tab[0]), atol(tab[2]), puissance);
  }
}

void opAiguillage(char** tab, identifiant_t* identification, Compteur_t* compte) {
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
      opEvent04(tab, identification);
      break;
    case(5):
      break;
  } 
}

char** creerTab(char* ligne) {
  char** tab = (char**) malloc(dimensionX(ligne) * sizeof(char*));
  if(ligne != NULL) {
    char* delim =" ";
    int i = 0;

    if(*ligne != '\0') {
      char* partie = strtok(ligne,delim);
      while(partie != NULL) {
        tab[i] =(char*) malloc(strlen(partie) + 1);
        tab[i] = partie;
        partie = strtok(NULL,delim);
        ++i;
      }
    }else return NULL;
  }else return NULL;
   
  return tab;
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
  return timeStamp > prevTimestamp;
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

