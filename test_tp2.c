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

void test_opEvent01(){
  char ligne[50] = "38.2";
  CU_ASSERT_TRUE(opEvent01(ligne) == (float)38.2);
  strcpy(ligne,"16.5");
  CU_ASSERT_TRUE(opEvent01(ligne) == (float)-1);
  strcpy(ligne,"39.9");
  CU_ASSERT_TRUE(opEvent01(ligne) == (float)39.9);
  strcpy(ligne,"ERREUR");
  CU_ASSERT_TRUE(opEvent01(ligne) == (float)0);

}

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

void test_actualiserTimestamp() {
  CU_ASSERT_TRUE(actualiserTimestamp((size_t)1423, (size_t)1422)==  1423);
  CU_ASSERT_TRUE(actualiserTimestamp((size_t)8475, (size_t)12)==  8475);
  CU_ASSERT_TRUE(actualiserTimestamp((size_t)453215, (size_t)25435)==  453215);
  CU_ASSERT_TRUE(actualiserTimestamp((size_t)1422, (size_t)1423)==  1423);
  CU_ASSERT_TRUE(actualiserTimestamp((size_t)5453, (size_t)68498)==  68498);

}
void test_validerTab() {
  char str[50] = "1342 02 error";
  int dimension = dimensionX(str);
  char** test = creerTab(str);
  CU_ASSERT_TRUE(validerTab(test, dimension, 1341));

  strcpy(str, "145130 05 1341 1543 43634");
  dimension = dimensionX(str);
  test = creerTab(str);
  CU_ASSERT_TRUE(validerTab(test, dimension, 15675));

  strcpy(str, "412 07");
  dimension = dimensionX(str);
  test = creerTab(str);
  CU_ASSERT_FALSE(validerTab(test, dimension, 324));

  strcpy(str, "");
  dimension = dimensionX(str);
  test = creerTab(str);
  CU_ASSERT_FALSE(validerTab(test, dimension, 0));
}
void test_validerNbrParam() {
  CU_ASSERT_TRUE(validerNbrParam(0,4));
  CU_ASSERT_TRUE(validerNbrParam(4,4));
  CU_ASSERT_TRUE(validerNbrParam(1,3));
  CU_ASSERT_TRUE(validerNbrParam(2,3));
  CU_ASSERT_TRUE(validerNbrParam(3,3));
  CU_ASSERT_TRUE(validerNbrParam(5,10));
  CU_ASSERT_FALSE(validerNbrParam(0,3));
  CU_ASSERT_FALSE(validerNbrParam(5,3));
  CU_ASSERT_FALSE(validerNbrParam(2,4));
  CU_ASSERT_FALSE(validerNbrParam(3,5));
}
