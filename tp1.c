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
//Le type de donné char a une grandeur de 1 octet donc il peut prendre des valeurs entre -128 et 127. Par conséquent, un char n'a pas assez de valeurs pour couvrir l'interval requis. De plus cette fonction retourne toujours vraix.
  CU_ASSERT_FALSE(validerTH_1(-171));
  CU_ASSERT_FALSE(validerTH_1(-169));
  CU_ASSERT_FALSE(validerTH_1(-1));
  CU_ASSERT_FALSE(validerTH_1(0));
  CU_ASSERT_FALSE(validerTH_1(16));
  CU_ASSERT_FALSE(validerTH_1(17));
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
  
  CU_ASSERT_FALSE(validerTH_2((char)-170));
  CU_ASSERT_FALSE(validerTH_2((char)-400));
  CU_ASSERT_FALSE(validerTH_2((char)16));
  CU_ASSERT_FALSE(validerTH_2((char)17));
  CU_ASSERT_FALSE(validerTH_2((char)18)); 
  CU_ASSERT_FALSE(validerTH_2((char)27));
  CU_ASSERT_FALSE(validerTH_2((char)39));
  CU_ASSERT_FALSE(validerTH_2((char)40));
  CU_ASSERT_FALSE(validerTH_2((char)169));
  CU_ASSERT_TRUE(validerTH_2((char)170));
  CU_ASSERT_TRUE(validerTH_2((char)171));
  CU_ASSERT_TRUE(validerTH_2((char)300));
  CU_ASSERT_TRUE(validerTH_2((char)350));
  CU_ASSERT_TRUE(validerTH_2((char)399));
  CU_ASSERT_TRUE(validerTH_2((char)400));
  CU_ASSERT_FALSE(validerTH_2((char)401));
  CU_ASSERT_FALSE(validerTH_2((char)536));

}

void test_validerTH_3(void) {
  CU_ASSERT_FALSE(validerTH_3((short)-171));
  CU_ASSERT_FALSE(validerTH_3((short)0));
  CU_ASSERT_FALSE(validerTH_3((short)50));
  CU_ASSERT_FALSE(validerTH_3((short)169));
  CU_ASSERT_TRUE(validerTH_3((short)170));
  CU_ASSERT_TRUE(validerTH_3((short)171));
  CU_ASSERT_TRUE(validerTH_3((short)224));
  CU_ASSERT_TRUE(validerTH_3((short)356));
  CU_ASSERT_TRUE(validerTH_3((short)399));
  CU_ASSERT_TRUE(validerTH_3((short)400));
  CU_ASSERT_FALSE(validerTH_3((short)401));
  CU_ASSERT_FALSE(validerTH_3((short)435));
  CU_ASSERT_FALSE(validerTH_3((short)546));
}

void test_validerTA_1(void) {

  CU_ASSERT_FALSE(validerTA_1(-500));
  CU_ASSERT_FALSE(validerTA_1(-401));
  CU_ASSERT_TRUE(validerTA_1(-400));
  CU_ASSERT_TRUE(validerTA_1(-399));
  CU_ASSERT_TRUE(validerTA_1(-224));
  CU_ASSERT_TRUE(validerTA_1(-98));
  CU_ASSERT_TRUE(validerTA_1(0));
  CU_ASSERT_TRUE(validerTA_1(40));
  CU_ASSERT_TRUE(validerTA_1(275));
  CU_ASSERT_TRUE(validerTA_1(399));
  CU_ASSERT_TRUE(validerTA_1(400));
  CU_ASSERT_FALSE(validerTA_1(401));
  CU_ASSERT_FALSE(validerTA_1(560));
}

void test_validerTA_2(void) {
//Le type de donné char a une grandeur de 1 octet donc il peut prendre des valeurs entre -128 et 127. Par conséquent, un char n'a pas assez de valeurs pour couvrir l'interval requis. De plus cette fonction retourne toujours vraix.
  CU_ASSERT_FALSE(validerTA_2((char)-672));
  CU_ASSERT_FALSE(validerTA_2((char)-401));
  CU_ASSERT_TRUE(validerTA_2((char)-400));
  CU_ASSERT_TRUE(validerTA_2((char)-399));
  CU_ASSERT_TRUE(validerTA_2((char)-289));
  CU_ASSERT_TRUE(validerTA_2((char)-112));
  CU_ASSERT_TRUE(validerTA_2((char)0));
  CU_ASSERT_TRUE(validerTA_2((char)40));
  CU_ASSERT_TRUE(validerTA_2((char)178));
  CU_ASSERT_TRUE(validerTA_2((char)267));
  CU_ASSERT_TRUE(validerTA_2((char)399));
  CU_ASSERT_TRUE(validerTA_2((char)400));
  CU_ASSERT_FALSE(validerTA_2((char)401));
  CU_ASSERT_FALSE(validerTA_2((char)492));

}

void test_validerTA_3(void) {
  CU_ASSERT_FALSE(validerTA_3((short)-543));
  CU_ASSERT_FALSE(validerTA_3((short)-401));
  CU_ASSERT_TRUE(validerTA_3((short)-399));
  CU_ASSERT_TRUE(validerTA_3((short)-299));
  CU_ASSERT_TRUE(validerTA_3((short)-190));
  CU_ASSERT_TRUE(validerTA_3((short)-40));
  CU_ASSERT_TRUE(validerTA_3((short)0));
  CU_ASSERT_TRUE(validerTA_3((short)40));
  CU_ASSERT_TRUE(validerTA_3((short)171));
  CU_ASSERT_TRUE(validerTA_3((short)270));
  CU_ASSERT_TRUE(validerTA_3((short)334));
  CU_ASSERT_TRUE(validerTA_3((short)399));
  CU_ASSERT_TRUE(validerTA_3((short)400));
  CU_ASSERT_FALSE(validerTA_3((short)401));
  CU_ASSERT_FALSE(validerTA_3((short)456));
}

void test_validerPulsation_1(void) {
  CU_ASSERT_FALSE(validerPulsation_1(50));
  CU_ASSERT_FALSE(validerPulsation_1(0));
  CU_ASSERT_FALSE(validerPulsation_1(49));
  CU_ASSERT_TRUE(validerPulsation_1(50));
  CU_ASSERT_TRUE(validerPulsation_1(51));
  CU_ASSERT_TRUE(validerPulsation_1(78));
  CU_ASSERT_TRUE(validerPulsation_1(150));
  CU_ASSERT_TRUE(validerPulsation_1(199));
  CU_ASSERT_TRUE(validerPulsation_1(200));
  CU_ASSERT_FALSE(validerPulsation_1(201));
  CU_ASSERT_FALSE(validerPulsation_1(356));
}

void test_validerPulsation_2(void) {
  CU_ASSERT_FALSE(validerPulsation_2((char)49));
  CU_ASSERT_TRUE(validerPulsation_2((char)50));
  CU_ASSERT_TRUE(validerPulsation_2((char)51));
  CU_ASSERT_TRUE(validerPulsation_2((char)57));
  CU_ASSERT_TRUE(validerPulsation_2((char)79));
  CU_ASSERT_TRUE(validerPulsation_2((char)124));
  CU_ASSERT_TRUE(validerPulsation_2((char)178));
  CU_ASSERT_TRUE(validerPulsation_2((char)199));
  CU_ASSERT_TRUE(validerPulsation_2((char)200));
  CU_ASSERT_FALSE(validerPulsation_2((char)201));
}

void test_validerPulsation_3(void) {
  
for(short i = -250 ; i < 251 ; ++i ) {
  CU_ASSERT_TRUE(validerPulsation_3(i));
}	
/*	CU_ASSERT_FALSE(validerPulsation_3((short)-154));
  CU_ASSERT_FALSE(validerPulsation_3((short)0));
  CU_ASSERT_FALSE(validerPulsation_3((short)49));
  CU_ASSERT_TRUE(validerPulsation_3((short)50));
  CU_ASSERT_TRUE(validerPulsation_3((short)51));
  CU_ASSERT_TRUE(validerPulsation_3((short)69));
  CU_ASSERT_TRUE(validerPulsation_3((short)156));
  CU_ASSERT_TRUE(validerPulsation_3((short)199));
  CU_ASSERT_TRUE(validerPulsation_3((short)200));
  CU_ASSERT_FALSE(validerPulsation_3((short)201));
  CU_ASSERT_FALSE(validerPulsation_3((short)250));
*/
}

void test_validerSignal_1(void) {
  CU_ASSERT_FALSE(validerSignal_1(-100));
  CU_ASSERT_FALSE(validerSignal_1(-86));
  CU_ASSERT_TRUE(validerSignal_1(-85));
  CU_ASSERT_TRUE(validerSignal_1(-84));
  CU_ASSERT_TRUE(validerSignal_1(-59));
  CU_ASSERT_TRUE(validerSignal_1(-41));
  CU_ASSERT_TRUE(validerSignal_1(-28));
  CU_ASSERT_TRUE(validerSignal_1(-26));
  CU_ASSERT_TRUE(validerSignal_1(-25));
  CU_ASSERT_FALSE(validerSignal_1(-24));
  CU_ASSERT_FALSE(validerSignal_1(-15));
  CU_ASSERT_FALSE(validerSignal_1(0));
  CU_ASSERT_FALSE(validerSignal_1(50));
}

void test_validerSignal_2(void) {
  CU_ASSERT_FALSE(validerSignal_2((char)-85));
  CU_ASSERT_FALSE(validerSignal_2((char)-25));
  CU_ASSERT_FALSE(validerSignal_2((char)0));
  CU_ASSERT_FALSE(validerSignal_2((char)24));
  CU_ASSERT_TRUE(validerSignal_2((char)25));
  CU_ASSERT_TRUE(validerSignal_2((char)26));
  CU_ASSERT_TRUE(validerSignal_2((char)44));
  CU_ASSERT_TRUE(validerSignal_2((char)71));
  CU_ASSERT_TRUE(validerSignal_2((char)84));
  CU_ASSERT_TRUE(validerSignal_2((char)85));
  CU_ASSERT_FALSE(validerSignal_2((char)87));
  CU_ASSERT_FALSE(validerSignal_2((char)100));

}

void test_validerSignal_3(void) {
  CU_ASSERT_FALSE(validerSignal_3((short)-100));
  CU_ASSERT_FALSE(validerSignal_3((short)-86));
  CU_ASSERT_TRUE(validerSignal_3((short)-85));
  CU_ASSERT_TRUE(validerSignal_3((short)-84));
  CU_ASSERT_TRUE(validerSignal_3((short)-59));
  CU_ASSERT_TRUE(validerSignal_3((short)-41));
  CU_ASSERT_TRUE(validerSignal_3((short)-28));
  CU_ASSERT_TRUE(validerSignal_3((short)-26));
  CU_ASSERT_TRUE(validerSignal_3((short)-25));
  CU_ASSERT_FALSE(validerSignal_3((short)-24));
  CU_ASSERT_FALSE(validerSignal_3((short)-15));
  CU_ASSERT_FALSE(validerSignal_3((short)0));
  CU_ASSERT_FALSE(validerSignal_3((short)25));
  CU_ASSERT_FALSE(validerSignal_3((short)50));
  CU_ASSERT_FALSE(validerSignal_3((short)85));

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
	(NULL == CU_add_test(pSuite, "validerPulsation_3", test_validerPulsation_3)) /*||
	(NULL == CU_add_test(pSuite, "validerSignal_1", test_validerSignal_1)) || 
	(NULL == CU_add_test(pSuite, "validerSignal_2", test_validerSignal_2)) ||
	(NULL == CU_add_test(pSuite, "validerSignal_3", test_validerSignal_3)) */
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
