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
  
  CU_ASSERT_FALSE(validerTH_1(169));   
  CU_ASSERT_TRUE(validerTH_1(170));
  CU_ASSERT_TRUE(validerTH_1(171)); 
  CU_ASSERT_TRUE(validerTH_1(399));
  CU_ASSERT_TRUE(validerTH_1(400));  
  CU_ASSERT_FALSE(validerTH_1(401));
} 

void test_validerTH_2(void) {
 //Le type de donné char a une grandeur de 1 octet donc il peut prendre des valeurs entre -128 et 127 ou  entre 0 et 255. Par conséquent, un char n'a pas assez de valeurs pour couvrir l'interval requis. De plus cette fonction retourne toujours faux. 
  CU_ASSERT_FALSE(validerTH_2((char)169));
  CU_ASSERT_TRUE(validerTH_2((char)170));
  CU_ASSERT_TRUE(validerTH_2((char)171));
  CU_ASSERT_TRUE(validerTH_2((char)254));
  CU_ASSERT_TRUE(validerTH_2((char)255));
}

void test_validerTH_3(void) {

  CU_ASSERT_FALSE(validerTH_3((short)169));
  CU_ASSERT_TRUE(validerTH_3((short)170));
  CU_ASSERT_TRUE(validerTH_3((short)171));
  CU_ASSERT_TRUE(validerTH_3((short)399));
  CU_ASSERT_TRUE(validerTH_3((short)400));
  CU_ASSERT_FALSE(validerTH_3((short)401));
}

void test_validerTA_1(void) {

  CU_ASSERT_FALSE(validerTA_1(-401));
  CU_ASSERT_TRUE(validerTA_1(-400));
  CU_ASSERT_TRUE(validerTA_1(-399));
  CU_ASSERT_TRUE(validerTA_1(399));
  CU_ASSERT_TRUE(validerTA_1(400));
  CU_ASSERT_FALSE(validerTA_1(401));
}

void test_validerTA_2(void) {
//Le type de donné char a une grandeur de 1 octet donc il peut prendre des valeurs entre -128 et 127 ou entre 0 et 255. Par conséquent, un char n'a pas assez de valeurs pour couvrir l'interval requis. De plus cette fonction retourne toujours vrais.
  CU_ASSERT_TRUE(validerTA_2((char)-128));
  CU_ASSERT_TRUE(validerTA_2((char)-127));
  CU_ASSERT_TRUE(validerTA_2((char)126));
  CU_ASSERT_TRUE(validerTA_2((char)127));

}

void test_validerTA_3(void) {

  CU_ASSERT_FALSE(validerTA_3((short)-401));
  CU_ASSERT_TRUE(validerTA_3((short)-400));
  CU_ASSERT_TRUE(validerTA_3((short)-399));
  CU_ASSERT_TRUE(validerTA_3((short)399));
  CU_ASSERT_TRUE(validerTA_3((short)400));
  CU_ASSERT_FALSE(validerTA_3((short)401));
}

void test_validerPulsation_1(void) {
  
  CU_ASSERT_FALSE(validerPulsation_1(49));
  CU_ASSERT_TRUE(validerPulsation_1(50));
  CU_ASSERT_TRUE(validerPulsation_1(51));
  CU_ASSERT_TRUE(validerPulsation_1(199));
  CU_ASSERT_TRUE(validerPulsation_1(200));
  CU_ASSERT_FALSE(validerPulsation_1(201));
}

void test_validerPulsation_2(void) {
//toujours fauxl.
  CU_ASSERT_FALSE(validerPulsation_2((char)49));
  CU_ASSERT_TRUE(validerPulsation_2((char)50));
  CU_ASSERT_TRUE(validerPulsation_2((char)51));
  CU_ASSERT_TRUE(validerPulsation_2((char)126));
  CU_ASSERT_TRUE(validerPulsation_2((char)127));
}

void test_validerPulsation_3(void) {
//toujours vrais  
  CU_ASSERT_FALSE(validerPulsation_3((short)49));
  CU_ASSERT_TRUE(validerPulsation_3((short)50));
  CU_ASSERT_TRUE(validerPulsation_3((short)51));
  CU_ASSERT_TRUE(validerPulsation_3((short)199));
  CU_ASSERT_TRUE(validerPulsation_3((short)200));
  CU_ASSERT_FALSE(validerPulsation_3((short)201));

}

void test_validerSignal_1(void) {
//toujours faux
  CU_ASSERT_FALSE(validerSignal_1(-86));
  CU_ASSERT_TRUE(validerSignal_1(-85));
  CU_ASSERT_TRUE(validerSignal_1(-84));
  CU_ASSERT_TRUE(validerSignal_1(-26));
  CU_ASSERT_TRUE(validerSignal_1(-25));
  CU_ASSERT_FALSE(validerSignal_1(-24));
}

void test_validerSignal_2(void) {
//retourne faux dans l'interval -85 a -25 
  CU_ASSERT_FALSE(validerSignal_2((char)-86)); 
  CU_ASSERT_TRUE(validerSignal_2((char)-85));
  CU_ASSERT_TRUE(validerSignal_2((char)-84));
  CU_ASSERT_TRUE(validerSignal_2((char)-26));
  CU_ASSERT_TRUE(validerSignal_2((char)-25));
  CU_ASSERT_FALSE(validerSignal_2((char)-24));

}

void test_validerSignal_3(void) {
//toujours faux dans l'interval -100 a 100.
  CU_ASSERT_FALSE(validerSignal_3((short)-86));
  CU_ASSERT_TRUE(validerSignal_3((short)-85));
  CU_ASSERT_TRUE(validerSignal_3((short)-84));
  CU_ASSERT_TRUE(validerSignal_3((short)-26));
  CU_ASSERT_TRUE(validerSignal_3((short)-25));
  CU_ASSERT_FALSE(validerSignal_3((short)-24));

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
