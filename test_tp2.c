//tp1.c
#include "Basic.h"       // mode de base
//#include "Automated.h"
//#include "Console.h"
#include "tcv.h"         // declaration de mes fonction
#include "malib.h"

#include <stdlib.h>
#include <stdio.h>       // printf
#include <string.h>
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
void test_trim() {
  char str[] = "   0001 02 erreur   ";
  char* string = trim(str);
  CU_ASSERT_STRING_EQUAL(string, "0001 02 erreur");
  strcpy(str, "002 03 143 12  ");
  string = trim(str);
  CU_ASSERT_STRING_EQUAL(string, "002 03 143 12");
  strcpy(str, "  003  02");
  string = trim(str);
  CU_ASSERT_STRING_EQUAL(string, "003  02");
  strcpy(str, "0004   04 125");
  string = trim(str);
  CU_ASSERT_STRING_EQUAL(string, "0004   04 125");
}

void test_creerTab() {
  char str[] = "0001 02 erreur erreur";
  char** test1;
  test1 = creerTab(str);
  CU_ASSERT_STRING_EQUAL(test1[0], "0001");
  CU_ASSERT_STRING_EQUAL(test1[1], "02");
  CU_ASSERT_STRING_EQUAL(test1[2], "erreur");
  CU_ASSERT_STRING_EQUAL(test1[3], "erreur");
  
  strcpy(str, "0324134");
  test1 = creerTab(str);
  CU_ASSERT_STRING_EQUAL(test1[0], "0324134");

  strcpy(str, "0004 03 2543");
  test1 = creerTab(str);
  CU_ASSERT_STRING_EQUAL(test1[0], "0004");
  CU_ASSERT_STRING_EQUAL(test1[1], "03");
  CU_ASSERT_STRING_EQUAL(test1[2], "2543");
}

void test_dimensionX() {
  CU_ASSERT_TRUE(dimensionX("15345 15 2342") == 3);
  CU_ASSERT_TRUE(dimensionX("123sdfre") == 1 ); 
  CU_ASSERT_TRUE(dimensionX("") == 0);
  CU_ASSERT_TRUE(dimensionX("1234   123   11234 12") == 4);
  CU_ASSERT_TRUE(dimensionX("123413 123  14134") == 3);   
}
/************* Nous debutons l'execution des tests **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "tp2_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "Nombre d'elements dans tableau 2d", test_dimensionX)) ||
        (NULL == CU_add_test(pSuite, "Creation tableau 2d", test_creerTab)) ||
	(NULL == CU_add_test(pSuite, "Trim des extremitees", test_trim))
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
