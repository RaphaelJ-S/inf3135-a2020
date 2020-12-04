#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tcv.h"
#include "malib.h"

int main(int argc, char** argv) {
  char** entreeTab = (char**)malloc(sizeof(*entreeTab)); 
  char str[200];
  char* ptr;
	unsigned short flags[4]= {0,0,0,0};
  size_t prevTimestamp = 0;
  identifiant_t identification = {9999, 2};
  Compteur_t compte = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  idPN_t idPN = {malloc(sizeof(size_t)), 0};
	version_t vers;   
  getVersion(&vers);
//ne pas oublier de reset ces valeurs
	donnees_t data = {vers,flags , compte, identification, idPN, 0};  
	
	printf("version #: %d.%d.%d\n",vers.major, vers.minor, vers.build);

  while(fgets(str,200, stdin) != NULL) {
		ptr = strtok(str, "\n");
    int size = dimensionX(ptr);
    entreeTab = creerTab(ptr, entreeTab, size);
    if(entreeTab != NULL) {

      if(entreeTab[0] != NULL)  {    

        if(validerTab(entreeTab, size, prevTimestamp)){
          opAiguillage(entreeTab, &identification, &compte, &idPN );

        }
        prevTimestamp = actualiserTimestamp(atol(entreeTab[0]), prevTimestamp);
      }
    }
  }
  free(entreeTab);
  free(idPN.tab);
  affichage(&compte); 
  return 0;
}
