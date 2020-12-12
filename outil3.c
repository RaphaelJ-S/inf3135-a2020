#include "outil3.h"
#include <math.h>
#define _BASE_ 10.0
#define _M_ -69

int cmd(int argc, char** argv, donnees_t* data) {
	
	for( int i = 1; i < argc; ++i) {
		if( strcmp( argv[i], "-t") == 0 ) data->options[0] = (unsigned char)1;
		else if( strcmp( argv[i], "-i" ) == 0 ) data->options[1] = (unsigned char)1;
		else if( strcmp( argv[i], "-d" ) == 0 ) data->options[2] = (unsigned char)1;
		else if( strcmp( argv[i], "-s" ) == 0 ) data->options[3] = (unsigned char)1;
		else return -1;
	}
	return 0;
}

float distance(int _signal, int _power) {
	return round( pow( _BASE_, ( _M_ - _signal ) / ( _BASE_ * _power )) * 10) / 10;
}

int comparer(const void* arg1, const void* arg2) {
	return ( *(size_t*)arg1 - *(size_t*)arg2 );
}

void affichageOptions(donnees_t* data) {
	if(data->options[0] == 0) {
		affichageCompt(data);
	}
	if (data->options[1] == 1){
		printf("\ninformation invalide\n  trx non reconnue : %ld\n  trx avec ts non sequentiel : %ld", data->cmpt_s->trxInval, data->cmpt_s->nbrNonSeq);
	}
	if (data->options[2] == 1) {
		printf("\ninformation detaillee\n  trx 01 : %ld\n  trx 02 : %ld\n  trx 03 : %ld\n  trx 04 : %ld\n  trx 05 : %ld\n  le dernier ts lu : %ld", data->cmpt_s->nbrTH, data->cmpt_s->nbrTA, data->cmpt_s->nbrPulse, data->cmpt_s->nbrSignal, data->cmpt_s->nbrIdPn, data->timestamp);
	}
	if (data->options[3] == 1) {
		printf("\ninformation sommaire\n  nbr trx valides : %ld\n  nbr trx (total) : %ld", data->cmpt_s->nbrTrxTot - data->cmpt_s->trxInval - data->cmpt_s->nbrNonSeq, data->cmpt_s->nbrTrxTot);
	}
}

void affichageLigne(donnees_t* data) {
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

