#include "malib.h"

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
				printf("\n--Data--\n");
				printf("\nOptions : -t_%d, -i_%d, -d_%d, -s_%d",data->options[0], data->options[1], data->options[2], data->options[3]);
				printf("\nVersion : %d.%d.%d", data->version->major, data->version->minor, data->version->build);
				printf("\nIdentifiant : %ld %d", data->identif_s->id, data->identif_s->puissance);
				printf("\nIDPN : %d", data->id_s->size);
				printf("\nTimestamp : %ld", data->timestamp);
				printf("\nEvenement : %d", data->event);
				printf("\nUnion : %d, %f, %d\n\n", data->idPwr, data->degSig, data->pwrSig);
				printf("\nCompteurs TA : \n	valInv : %ld Err : %ld sum : %.1f nbr : %ld",data->cmpt_s->valInvTA, data->cmpt_s->manifErrTA, data->cmpt_s->sumTA, data->cmpt_s->nbrTA);
				printf("\nCompteurs TH : \n	valInv : %ld Err : %ld sum : %.1f nbr : %ld",data->cmpt_s->valInvTH, data->cmpt_s->manifErrTH, data->cmpt_s->sumTH, data->cmpt_s->nbrTH);
				printf("\nCompteurs Pulse: \n	valInv : %ld Err : %ld sum : %.ld nbr : %ld",data->cmpt_s->valInvPulse, data->cmpt_s->manifErrPulse, data->cmpt_s->sumPulse, data->cmpt_s->nbrPulse);
				printf("\nCompteurs : \n	E4 : %ld E5 : %ld nbrTot : %ld trxInval : %ld nbrNonSeq : %ld\n\n", data->cmpt_s->nbrSignal, data->cmpt_s->nbrIdPn, data->cmpt_s->nbrTrxTot, data->cmpt_s->trxInval, data->cmpt_s->nbrNonSeq);	
			#endif
			
		}
		if(validerNbrParam(data, i) && data->options[0] == 0 && valide) {
			affLigne(data);
		}
  }     
}

bool confirmeDeux(char* partie, donnees_t* data) {
	char event = data->event;
	int err = strcmp(partie, "ERREUR");
	if(event == 0) {
		data->identif_s->id = atol(partie);
	}else if (event == 1 || event == 2 || event == 3 || event == 4){
		if(err == 0){
			if(event == 1) data->cmpt_s->manifErrTH += 1;
			if(event == 2) data->cmpt_s->manifErrTA += 1;
			if(event == 3) data->cmpt_s->manifErrPulse += 1;
			return false;
		}else {
			data->degSig = atof(partie);
			data->pwrSig = atoi(partie);
			return validerDegSig(data);
		}
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
		data->id_s->id = atol(partie);
	}else if(event == 5) {
		
	} 
	return true;
}

bool confirmeEvenement(char* partie, donnees_t* data) {
	int evenement = validerEvenement(partie);
  if(evenement == -1) { 
		data->cmpt_s->trxInval += 1;
		return false;	
	}else if ( evenement == 1) data->cmpt_s->nbrTH += 1;
	else if ( evenement == 2) data->cmpt_s->nbrTA += 1;
	else if ( evenement == 3) data->cmpt_s->nbrPulse += 1;
	else if ( evenement == 4) data->cmpt_s->nbrSignal += 1;
	else if ( evenement == 5) data->cmpt_s->nbrIdPn += 1;
	data->event = evenement;
	return true;
}

bool validerDegSig(donnees_t* data) {
  unsigned int build = data->version->build;
	char event = data->event;
	int foncAPrendre = build >= 1005 && build <= 1008 ? 1 : build <= 1003 ? 2 : 0; 
	float degSig = data->degSig;
	bool valide = false;
	
	if(event == 1) {
		valide = foncAPrendre == 1 || foncAPrendre == 2 ? validerTH_1((int)(degSig * 10)) : false;
		if(valide) data->cmpt_s->sumTH += degSig; 
		else data->cmpt_s->valInvTA += 1; 
	
	}else if (event == 2) {
		valide = foncAPrendre == 1 ? validerTA_1((int)(degSig*10)) : foncAPrendre == 2 ? validerTA_3((short)(degSig * 10)) : false;
		if(valide) data->cmpt_s->sumTA += degSig;
		else data->cmpt_s->valInvTH += 1;
	
	}else if (event == 3) {
		valide = foncAPrendre == 1 ? validerPulsation_1((int)degSig) : foncAPrendre == 2 ? validerPulsation_3((short)degSig) : false;
		if(valide)	data->cmpt_s->sumPulse += degSig;
		else 	data->cmpt_s->valInvPulse += 1;
	
	}else if (event == 4) {
		valide = foncAPrendre == 1 ? validerSignal_3((short)degSig) : foncAPrendre == 2 ? validerSignal_2((char)degSig) : false;
	}
	return valide;
}
int validerEvenement(char* partie) {
  int i = 0;
  char eveneVal[6][2] = {{"00"},{"01"},{"02"},{"03"},{"04"},{"05"}};

  if(strlen(partie) == 2) {
    while(i < 6) {
       if((int)partie[0] == (int)eveneVal[i][0] && (int)partie[1] == (int)eveneVal[i][1]) return atoi(partie); 
       ++i;
    }
  }
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
bool validerNbrParam(donnees_t* data, int size) {
  int evenement = data->event;
	if(size < 3)return false;
	return ((evenement == 0 ||evenement == 4) ? (size != 4 ? false : true) 
         : (evenement == 1 ||evenement == 2 ||evenement ==3) ? (size != 3 ? false : true)
         : (evenement == 5) ? (size < 4 ? false : true) 
         : false);
}

void affLigne(donnees_t* data) {
	float (*dist)(int, int) = distance;
	if(data->event == 0) printf("\n10 %ld %ld %d", data->timestamp, data->identif_s->id, data->identif_s->puissance);
	if(data->event == 4) printf("\n14 %ld %ld %.1f", data->timestamp, data->id_s->id, (*dist)(data->pwrSig, data->identif_s->puissance)); 
	if(data->event == 5){
		printf("\n15 %ld %ld ", data->timestamp, data->identif_s->id);
		for(int i = 0; i < data->id_s->size; ++i) {
			printf("%ld ", data->id_s->tab[i]);
		}
	}
}
void affichageCompt(donnees_t* data) {
  Compteur_t* compte = data->cmpt_s;
	size_t THvalide = compte->nbrTH - compte->manifErrTH - compte->valInvTH;
	size_t TAvalide = compte->nbrTA - compte->manifErrTA - compte->valInvTA;
	size_t Pvalide = compte->nbrPulse - compte->manifErrPulse - compte->valInvPulse;
  float moyTA = TAvalide > 0 ? compte->sumTA/TAvalide : 0;
  float moyTH = THvalide > 0 ? compte->sumTH/THvalide : 0;
	float moyP = Pvalide > 0 ? compte->sumPulse/Pvalide : 0;
	printf("\n21 %.1f %.1f %.0f",moyTH, moyTA, moyP);
  printf("\n22 %ld %ld %ld", compte->valInvTH, compte->valInvTA, compte->valInvPulse);
  printf("\n23 %ld %ld %ld", compte->manifErrTH/3, compte->manifErrTA/3, compte->manifErrPulse/3); 
}
void ajouterIdPN(idPN_t* idPN, size_t nvElem) {
  idPN->tab = realloc(idPN->tab, sizeof(size_t) * (idPN->size+1));
  idPN->tab[idPN->size] = nvElem;
  idPN->size += 1; 
}

