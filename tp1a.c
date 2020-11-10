#include <stdio.h>
#include "Basic.h"
#include "tcv.h"
#include "simple.h"

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
}
