#include <stdio.h>
#include "Basic.h"
#include "tcv.h"
#include "simple.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }


void test_validerTH_1(void) {
  CU_ASSERT_TRUE(validerTH_1((int)BORNE_MIN_TH));
  CU_ASSERT_TRUE(validerTH_1((int)BORNE_MIN_TH + 1)); 
  CU_ASSERT_TRUE(validerTH_1((int)BORNE_MAX_TH - 1));
  CU_ASSERT_TRUE(validerTH_1((int)BORNE_MAX_TH));  
} 
void test_validerTH_2(void) {
  CU_ASSERT_FALSE(validerTH_2((char)BORNE_MIN_S_CHAR));
  CU_ASSERT_FALSE(validerTH_2((char)BORNE_MIN_S_CHAR + 1));
  CU_ASSERT_FALSE(validerTH_2((char)BORNE_MAX_S_CHAR - 1));
  CU_ASSERT_FALSE(validerTH_2((char)BORNE_MAX_S_CHAR));
}
void test_validerTH_3(void) {
  CU_ASSERT_TRUE(validerTH_3((short)BORNE_MIN_TH));
  CU_ASSERT_TRUE(validerTH_3((short)BORNE_MIN_TH + 1));
  CU_ASSERT_TRUE(validerTH_3((short)BORNE_MAX_TH - 1));
  CU_ASSERT_TRUE(validerTH_3((short)BORNE_MAX_TH));
}


void test_validerTA_1(void) {
  CU_ASSERT_TRUE(validerTA_1((int)BORNE_MIN_TA));
  CU_ASSERT_TRUE(validerTA_1((int)BORNE_MIN_TA + 1));
  CU_ASSERT_TRUE(validerTA_1((int)BORNE_MAX_TA - 1));
  CU_ASSERT_TRUE(validerTA_1((int)BORNE_MAX_TA));
}
void test_validerTA_2(void) {
  CU_ASSERT_TRUE(validerTA_2((char)BORNE_MIN_S_CHAR));
  CU_ASSERT_TRUE(validerTA_2((char)BORNE_MIN_S_CHAR + 1));
  CU_ASSERT_TRUE(validerTA_2((char)BORNE_MAX_S_CHAR - 1));
  CU_ASSERT_TRUE(validerTA_2((char)BORNE_MAX_S_CHAR));
}
void test_validerTA_3(void) {
  CU_ASSERT_TRUE(validerTA_3((short)BORNE_MIN_TA));
  CU_ASSERT_TRUE(validerTA_3((short)BORNE_MIN_TA + 1));
  CU_ASSERT_TRUE(validerTA_3((short)BORNE_MAX_TA - 1));
  CU_ASSERT_TRUE(validerTA_3((short)BORNE_MAX_TA));;
}


void test_validerPulsation_1(void) {
  CU_ASSERT_TRUE(validerPulsation_1((int)BORNE_MIN_PULSE));
  CU_ASSERT_TRUE(validerPulsation_1((int)BORNE_MIN_PULSE + 1));
  CU_ASSERT_TRUE(validerPulsation_1((int)BORNE_MAX_PULSE - 1));
  CU_ASSERT_TRUE(validerPulsation_1((int)BORNE_MAX_PULSE));
}
void test_validerPulsation_2(void) {
  CU_ASSERT_TRUE(validerPulsation_2((char)BORNE_MIN_PULSE));
  CU_ASSERT_TRUE(validerPulsation_2((char)BORNE_MIN_PULSE + 1));
  CU_ASSERT_TRUE(validerPulsation_2((char)BORNE_MAX_S_CHAR - 1));
  CU_ASSERT_TRUE(validerPulsation_2((char)BORNE_MAX_S_CHAR));
}
void test_validerPulsation_3(void) {
  CU_ASSERT_TRUE(validerPulsation_3((short)BORNE_MIN_PULSE));
  CU_ASSERT_TRUE(validerPulsation_3((short)BORNE_MIN_PULSE + 1));
  CU_ASSERT_TRUE(validerPulsation_3((short)BORNE_MAX_PULSE - 1));
  CU_ASSERT_TRUE(validerPulsation_3((short)BORNE_MAX_PULSE));
}


void test_validerSignal_1(void) {
  CU_ASSERT_TRUE(validerSignal_1((int)BORNE_MIN_SIGNAL));
  CU_ASSERT_TRUE(validerSignal_1((int)BORNE_MIN_SIGNAL + 1));
  CU_ASSERT_TRUE(validerSignal_1((int)BORNE_MAX_SIGNAL - 1));
  CU_ASSERT_TRUE(validerSignal_1((int)BORNE_MAX_SIGNAL));
}
void test_validerSignal_2(void) {
  CU_ASSERT_TRUE(validerSignal_2((char)BORNE_MIN_SIGNAL));
  CU_ASSERT_TRUE(validerSignal_2((char)BORNE_MIN_SIGNAL + 1));
  CU_ASSERT_TRUE(validerSignal_2((char)BORNE_MAX_SIGNAL - 1));
  CU_ASSERT_TRUE(validerSignal_2((char)BORNE_MAX_SIGNAL));
}
void test_validerSignal_3(void) {
  CU_ASSERT_TRUE(validerSignal_3((short)BORNE_MIN_SIGNAL));
  CU_ASSERT_TRUE(validerSignal_3((short)BORNE_MIN_SIGNAL + 1));
  CU_ASSERT_TRUE(validerSignal_3((short)BORNE_MAX_SIGNAL - 1));
  CU_ASSERT_TRUE(validerSignal_3(short)BORNE_MAX_SIGNAL);
}
