#include <stdio.h>
#include "simple.c"


enum {

  BORNE_MAX_TH=400,
  BORNE_MIN_TH=170,

  BORNE_MAX_TA=400,
  BORNE_MIN_TA=-400,

  BORNE_MAX_PULSE=200,
  BORNE_MIN_PULSE=50,
 
  BORNE_MAX_SIGNAL=-25,
  BORNE_MIN_SIGNAL=-85,

  BORNE_MAX_U_CHAR=255 ,
  BORNE_MIN_U_CHAR=0 ,
  
  BORNE_MAX_S_CHAR=127,
  BORNE_MIN_S_CHAR=-128
};
int init_suite();
int clean_suite();
void test_validerTH_1();
void test_validerTH_2();
void test_validerTH_3();
void test_validerTA_1();
void test_validerTA_2();
void test_validerTA_3();
void test_validerPulsation_1();
void test_validerPulsation_2();
void test_validerPulsation_3();
void test_validerSignal_1();
void test_validerSignal_2();
void test_validersignal_3();

