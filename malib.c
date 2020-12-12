#include "malib.h"

void lecture( char* ligne, donnees_t* data ) {
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
		}
		if(validerNbrParam(data, i) && data->options[0] == 0 && valide) {
			affichageLigne(data);
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
  } else if( event == 5 ) { 
		int (*comp)(const void*, const void*) = comparer;
		size_t id = atol(partie);
		
		if(data->id_s->size > 1) qsort( data->id_s->tab, data->id_s->size, sizeof(size_t), (*comp) ); 		
		if( !(bsearch( (void*)&id, data->id_s->tab, data->id_s->size, sizeof(size_t), (*comp))) ) ajouterIdPN(data->id_s, id);

		qsort( data->id_s->tab, data->id_s->size, sizeof(size_t), (*comp) );
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
			data->identif_s->puissance = (unsigned char)2;
			return false;
		}
	}else if(event == 4) {
		ajouterIdPN(data->id_s, atol(partie));
		data->id_s->id = atol(partie);
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
		else data->cmpt_s->valInvTH += 1; 
	
	}else if (event == 2) {
		valide = foncAPrendre == 1 ? validerTA_1((int)(degSig*10)) : foncAPrendre == 2 ? validerTA_3((short)(degSig * 10)) : false;
		if(valide) data->cmpt_s->sumTA += degSig;
		else data->cmpt_s->valInvTA += 1;
	
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

void ajouterIdPN(idPN_t* idPN, size_t nvElem) {
  idPN->tab = realloc(idPN->tab, sizeof(size_t) * (idPN->size+1));
  idPN->tab[idPN->size] = nvElem;
  idPN->size += 1; 
}

