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
  int evenement ;
   
  if(size > 2) {
    evenement = atoi(param[1]);

    if(!validerEvenement(param)) {
      printf("Erreur! le No evenement %s n'est pas valide. Doit être entre 00 et 05\n", param[1]); 
      return false;
    }
    if(!validerNbrParam(evenement, size)){
      printf("Erreur! L'evenement %s n'a pas le bon nombre de parametre", param[1]);
      return false; 
    } 
    if(!validerTimestamp(param, prevTimestamp)) {
      printf("Erreur! Le timestamp de cet entrée est <= à la précédente\n");
      return false;
    }
    return true; 
  } else printf("Erreur! le nombre de paramètre est invalide. Doit être > 2\n"); 

  return false;
}
//Retourne le timestamp de param si il est supérieur au précédent, sinon retourne le timestamp précédent
bool validerTimestamp(char** param, size_t prevTimestamp) {
  return atol(param[0]) > prevTimestamp;
}

size_t actualiserTimestamp(char** param, size_t prevTimestamp) {
  if(atol(param[0]) > prevTimestamp) return atol(param[0]);
  else return prevTimestamp; 
}

bool validerEvenement(char** param) {
  int i = 0;
  char eveneVal[6][2] = {{"00"},{"01"},{"02"},{"03"},{"04"},{"05"}};

  if(strlen(param[1]) == 2) {
    while(i < 6) {
       if((int)param[1][0] == (int)eveneVal[i][0] && (int)param[1][1] == (int)eveneVal[i][1]) return true; 
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

Entree* creerEntree(char*ligne, Entree* vide) {
  
  return vide;
}
