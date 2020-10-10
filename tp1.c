//tp1.c
#include "Basic.h"       // mode de base
//#include "Automated.h"
//#include "Console.h"
#include "tcv.h"         // declaration de mes fonctions
#include <stdio.h>       // printf

/*****  LES fonctions qui initialise et detruit la "Suite de test" ******/

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/********************* NOS fonctions de tests *********************/
/*
void test_case_exemple(void)
{
   // Les types d'assertions disponibles
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}
*/
//Insérer le code du Tp1 ici.!!!

void test_validerTH_1(void) {
  int valInt;
  valInt = 170;  
  CU_ASSERT_TRUE(validerTH_1(valInt));
  valInt = 171;
  CU_ASSERT_TRUE(validerTH_1(valInt)); 
  valInt = 399;
  CU_ASSERT_TRUE(validerTH_1(valInt));
  valInt = 400;
  CU_ASSERT_TRUE(validerTH_1(valInt));  
} 

void test_validerTH_2(void) {
 //Le type de donné char a une grandeur de 1 octet donc il peut prendre des valeurs entre -128 et 127. Par conséquent, un char n'a pas assez de valeurs pour couvrir l'interval requis. De plus cette fonction retourne toujours faux. 
  char valChar;
  valChar = -128;
  CU_ASSERT_FALSE(validerTH_2(valChar));
  valChar = -127;
  CU_ASSERT_FALSE(validerTH_2(valChar));
  valChar = 126;
  CU_ASSERT_FALSE(validerTH_2(valChar));
  valChar = 127;
  CU_ASSERT_FALSE(validerTH_2(valChar));
}
void test_validerTH_3(void) {
  short valShort;
  valShort = 170;
  CU_ASSERT_TRUE(validerTH_3(valShort));
  valShort = 171;
  CU_ASSERT_TRUE(validerTH_3(valShort));
  valShort = 399;
  CU_ASSERT_TRUE(validerTH_3(valShort));
  valShort = 400;
  CU_ASSERT_TRUE(validerTH_3(valShort));
}

void test_validerTA_1(void) {
  int valInt;
  valInt = -400; 
  CU_ASSERT_TRUE(validerTA_1(valInt));
  valInt = -399; 
  CU_ASSERT_TRUE(validerTA_1(valInt));
  valInt = 399;
  CU_ASSERT_TRUE(validerTA_1(valInt));
  valInt = 400;
  CU_ASSERT_TRUE(validerTA_1(valInt));
}

void test_validerTA_2(void) {
//Le type de donné char a une grandeur de 1 octet donc il peut prendre des valeurs entre -128 et 127. Par conséquent, un char n'a pas assez de valeurs pour couvrir l'interval requis. De plus cette fonction retourne toujours vrais.
  char valChar;
  valChar = -128; 
  CU_ASSERT_TRUE(validerTA_2(valChar));
  valChar = -127;
  CU_ASSERT_TRUE(validerTA_2(valChar));
  valChar = 126;
  CU_ASSERT_TRUE(validerTA_2(valChar));
  valChar = 127;
  CU_ASSERT_TRUE(validerTA_2(valChar));

}

void test_validerTA_3(void) {
  short valShort;
  valShort = -400;
  CU_ASSERT_TRUE(validerTA_3(valShort));
  valShort = -399;
  CU_ASSERT_TRUE(validerTA_3(valShort));
  valShort = 399;
  CU_ASSERT_TRUE(validerTA_3(valShort));
  valShort = 400;
  CU_ASSERT_TRUE(validerTA_3(valShort));
}

void test_validerPulsation_1(void) {
  int valInt;
  valInt = 50;
  CU_ASSERT_TRUE(validerPulsation_1(valInt));
  valInt = 51;
  CU_ASSERT_TRUE(validerPulsation_1(valInt));
  valInt = 199;
  CU_ASSERT_TRUE(validerPulsation_1(valInt));
  valInt = 200;
  CU_ASSERT_TRUE(validerPulsation_1(valInt));
}

void test_validerPulsation_2(void) {
//toujours faux.
  char valChar;
  valChar = 50;
  CU_ASSERT_TRUE(validerPulsation_2(valChar));
  valChar = 51;
  CU_ASSERT_TRUE(validerPulsation_2(valChar));
  valChar = 126;
  CU_ASSERT_TRUE(validerPulsation_2(valChar));
  valChar = 127;
  CU_ASSERT_TRUE(validerPulsation_2(valChar));
}

void test_validerPulsation_3(void) {
//toujours vrais  
  short valShort;
  valShort = 50;
  CU_ASSERT_TRUE(validerPulsation_3(valShort));
  valShort = 51;
  CU_ASSERT_TRUE(validerPulsation_3(valShort));
  valShort = 199;
  CU_ASSERT_TRUE(validerPulsation_3(valShort));
  valShort = 200;
  CU_ASSERT_TRUE(validerPulsation_3(valShort));

}

void test_validerSignal_1(void) {
//toujours faux
  
  int valInt;
  valInt = -85;
  CU_ASSERT_FALSE(validerSignal_1(valInt));
  valInt = -84;
  CU_ASSERT_FALSE(validerSignal_1(valInt));
  valInt = -26;
  CU_ASSERT_FALSE(validerSignal_1(valInt));
  valInt = -25;
  CU_ASSERT_FALSE(validerSignal_1(valInt));
}

void test_validerSignal_2(void) {
//retourne faux dans l'interval -85 a -25
  char valChar;
  valChar = -85;
  CU_ASSERT_FALSE(validerSignal_2(valChar));
  valChar = -84;
  CU_ASSERT_FALSE(validerSignal_2(valChar));
  valChar = -26;
  CU_ASSERT_FALSE(validerSignal_2(valChar));
  valChar = -25;
  CU_ASSERT_FALSE(validerSignal_2(valChar));

}

void test_validerSignal_3(void) {
  short valShort;
  valShort = -85;
  CU_ASSERT_FALSE(validerSignal_3(valShort));
  valShort = -84;
  CU_ASSERT_FALSE(validerSignal_3(valShort));
  valShort = -26;
  CU_ASSERT_FALSE(validerSignal_3(valShort));
  valShort = -25;
  CU_ASSERT_FALSE(validerSignal_3(valShort));

}
/************* Nous debutons l'execution des tests **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "tp1_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "validerTH_1", test_validerTH_1)) ||
        (NULL == CU_add_test(pSuite, "validerTH_2", test_validerTH_2)) ||	
	(NULL == CU_add_test(pSuite, "validerTH_3", test_validerTH_3)) ||
        (NULL == CU_add_test(pSuite, "validerTA_1", test_validerTA_1)) ||
	(NULL == CU_add_test(pSuite, "validerTA_2", test_validerTA_2)) ||
	(NULL == CU_add_test(pSuite, "validerTA_3", test_validerTA_3)) ||
        (NULL == CU_add_test(pSuite, "validerPulsation_1", test_validerPulsation_1)) ||
	(NULL == CU_add_test(pSuite, "validerPulsation_2", test_validerPulsation_2)) ||
	(NULL == CU_add_test(pSuite, "validerPulsation_3", test_validerPulsation_3)) ||
	(NULL == CU_add_test(pSuite, "validerSignal_1", test_validerSignal_1)) || 
	(NULL == CU_add_test(pSuite, "validerSignal_2", test_validerSignal_2)) ||
	(NULL == CU_add_test(pSuite, "validerSignal_3", test_validerSignal_3)) 
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
/* 
   // LES modes interactifs
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
*/
   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
