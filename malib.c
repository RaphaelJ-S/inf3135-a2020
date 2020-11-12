#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "malib.h"
#include "tcv.h"  



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

