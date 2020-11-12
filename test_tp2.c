#include "Basic.h"
#include "tcv.h"       
#include "malib.h"
#include "test_tp2.h"
#include <stdlib.h>
#include <stdio.h>      
#include <string.h>
#include <stdbool.h>

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }


void test_creerTab() {
  char str[] = "0001 02 erreur erruer";
  char** test1 = creerTab(str);
  CU_ASSERT_STRING_EQUAL(test1[0], "0001");
  CU_ASSERT_STRING_EQUAL(test1[1], "02");
  CU_ASSERT_STRING_EQUAL(test1[2], "erreur");
  CU_ASSERT_STRING_EQUAL(test1[3], "erruer");

  test1 = (char**)creerTab("");
  CU_ASSERT_EQUAL(test1, NULL);

  test1 = (char**)creerTab(NULL);
  CU_ASSERT_EQUAL(test1, NULL);
}
void test_dimensionX() {
  CU_ASSERT_TRUE(dimensionX("1234 02 142")== 3);
  CU_ASSERT_TRUE(dimensionX("123sdfre") == 1 ); 
  CU_ASSERT_TRUE(dimensionX("") == 0);
  CU_ASSERT_TRUE(dimensionX(NULL) == 0);
}
void test_validerEvenement() {
  CU_ASSERT_TRUE(validerEvenement("00"));
  CU_ASSERT_TRUE(validerEvenement("01"));
  CU_ASSERT_TRUE(validerEvenement("02"));
  CU_ASSERT_TRUE(validerEvenement("03"));
  CU_ASSERT_TRUE(validerEvenement("04"));
  CU_ASSERT_TRUE(validerEvenement("05"));
  CU_ASSERT_FALSE(validerEvenement("06"));
  CU_ASSERT_FALSE(validerEvenement("001"));
  CU_ASSERT_FALSE(validerEvenement("10"));
}
void test_validerTimestamp() {
  CU_ASSERT_TRUE(validerTimestamp((size_t)0002, (size_t)1));
  CU_ASSERT_TRUE(validerTimestamp((size_t)5, (size_t)0001));
  CU_ASSERT_FALSE(validerTimestamp((size_t)0001, (size_t)001));
  CU_ASSERT_FALSE(validerTimestamp((size_t)1, (size_t)002));
}
void test_validerTab() {
  
}
