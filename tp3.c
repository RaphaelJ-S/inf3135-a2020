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
  Compteur_t compte = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  idPN_t idPN = {0, malloc(sizeof(size_t)), 0};
	version_t vers;   
  getVersion(&vers);
	donnees_t data = {&vers,flags , &compte, &identification, &idPN, 0};  
	int option = cmd(argc, argv, &data);
	
	if(option == 0) {
		printf("version #: %d.%d.%d",vers.major, vers.minor, vers.build);
  	while(fgets(str,200, stdin) != NULL) {
				ptr = strtok(str, "\n");
   		 	data.cmpt_s->nbrTrxTot += 1;
				#ifdef _ERR_
					printf("\nEntree : %s", ptr);
				#endif
				lecture(ptr, &data);
  	}
		if(data.options[0] == 0) {
			affichageCompt(&data);			
		}
		if (data.options[1] == 1){
			printf("\ninformation invalide\n  trx non reconnue : %ld\n  trx avec ts non sequentiel : %ld", data.cmpt_s->trxInval, data.cmpt_s->nbrNonSeq);		
		}
		if (data.options[2] == 1) {
			printf("\ninformation detaillee\n  trx 01 : %ld\n  trx 02 : %ld\n  trx 03 : %ld\n  trx 04 : %ld\n  trx 05 : %ld\n  le dernier ts lu : %ld", data.cmpt_s->nbrTH, data.cmpt_s->nbrTA, data.cmpt_s->nbrPulse, data.cmpt_s->nbrSignal, data.cmpt_s->nbrIdPn, data.timestamp);
		}
		if (data.options[3] == 1) {
			printf("\ninformation sommaire\n  nbr trx valides : %ld\n  nbr trx (total) : %ld", data.cmpt_s->nbrTrxTot - data.cmpt_s->trxInval - data.cmpt_s->nbrNonSeq, data.cmpt_s->nbrTrxTot);
		}
	}else printf("\n\nUne option n'est pas valide. Les options sont : -d -t -i -s\n\n");
  free(idPN.tab);
  return 0;
}
