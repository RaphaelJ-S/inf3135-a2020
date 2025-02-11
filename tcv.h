#ifndef __TCV_H__
#define __TCV_H__

#include <stdbool.h>

typedef struct version_s {
  unsigned char major;
  unsigned char minor;
  unsigned int  build;
} version_t;

void getVersion(version_t *v);


bool validerTH_1(int);
bool validerTH_2(char);
bool validerTH_3(short);

bool validerTA_1(int);
bool validerTA_2(char);
bool validerTA_3(short);

bool validerPulsation_1(int);
bool validerPulsation_2(char);
bool validerPulsation_3(short);

bool validerSignal_1(int);
bool validerSignal_2(char);
bool validerSignal_3(short);

#endif
