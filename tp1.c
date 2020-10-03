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

  CU_ASSERT_FALSE(validerTH_1(-171));
  CU_ASSERT_FALSE(validerTH_1(-169));
  CU_ASSERT_FALSE(validerTH_1(-1));
  CU_ASSERT_FALSE(validerTH_1(0));
  CU_ASSERT_FALSE(validerTH_1(50));
  CU_ASSERT_FALSE(validerTH_1(169));   
  CU_ASSERT_TRUE(validerTH_1(170));
  CU_ASSERT_TRUE(validerTH_1(171)); 
  CU_ASSERT_TRUE(validerTH_1(221));
  CU_ASSERT_TRUE(validerTH_1(273));
  CU_ASSERT_TRUE(validerTH_1(365));   
  CU_ASSERT_TRUE(validerTH_1(399));
  CU_ASSERT_TRUE(validerTH_1(400));  
  CU_ASSERT_FALSE(validerTH_1(401));
  CU_ASSERT_FALSE(validerTH_1(526));
} 

void test_validerTH_2(void) {
  CU_ASSERT_TRUE(validerTH_2((char)170));
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
   if ( (NULL == CU_add_test(pSuite, "validerTH_1_int", test_validerTH_1)) ||
        (NULL == CU_add_test(pSuite, "validerTH_1_char", test_validerTH_2))	
		   
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
