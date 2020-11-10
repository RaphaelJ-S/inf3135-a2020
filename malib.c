#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "malib.h"
  


char* trim(char* ligne) {
  if(ligne != NULL) {
    char* fin;
    while(isspace((unsigned char)*ligne)) ligne++;
    if(*ligne== '\0') return ligne;
    fin = ligne + strlen(ligne) -1;
    while(fin > ligne && isspace((unsigned char)*fin)) fin--;
    fin[1] = '\0';
  }

  return ligne;

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
    }
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

  bool rep = false;
  if(size > 2) {
    size_t currTimestamp = atol(param[0]);
    char eveneVal[6][2] = {{"00"},{"01"},{"02"},{"03"},{"04"},{"05"}};
    int i = 0;

    int evenement = atoi(param[1]);
    if(currTimestamp > prevTimestamp){
      while(i < 6 && !rep && strlen(param[1]) == 2) {
        if((int)param[1][0] == (int)eveneVal[i][0] && (int)param[1][1] == (int)eveneVal[i][1]) rep = true; 
        ++i;
      }
      if(rep) {
        switch(evenement) {
          case(0||4):
	    if(size != 4) rep = false;
	    break;
	  case(1|2|3):
	    if(size != 3) rep =false;
            break;
 	  case(5):
	    if(size < 4) rep = false;
       	    break;
        } 
      } else printf("Erreur No evenement %s n'est pas valide\n", param[1]);
    } else printf("Erreur Timestamp prev: %ld >= curr: %ld\n", prevTimestamp, currTimestamp);

  } else printf("Erreur nbr de paramètre < 3\n"); 
  return rep;
}

Entree* creerEntree(char*ligne, Entree* vide) {
  
  return vide;
}
