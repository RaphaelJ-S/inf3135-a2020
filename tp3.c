#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tcv.h"
#include "malib.h"

int main(int argc, char** argv) {
  char str[200];
  char* ptr;
	unsigned char flags[4]={0,0,0,0};
  identifiant_t identification = {9999, 2};
  Compteur_t compte = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  idPN_t idPN = {malloc(sizeof(size_t)), 0};
	version_t vers;   
  getVersion(&vers);
//ne pas oublier de reset ces valeurs
	donnees_t data = {&vers,flags , &compte, &identification, &idPN, 0};  
	cmd(argc, argv, &data);
	printf("version #: %d.%d.%d\n",vers.major, vers.minor, vers.build);

  while(fgets(str,200, stdin) != NULL) {
		ptr = strtok(str, "\n");
    lecture(ptr, &data);

  }
  free(idPN.tab);
  //affichage(&compte); 
  return 0;
}
