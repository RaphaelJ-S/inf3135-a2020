#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "malib.h"
#include "outil3.h"

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
	return round(pow(_BASE_, (_M_ - _signal)/(_BASE_* _power)));
}


