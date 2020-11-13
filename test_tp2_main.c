#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Basic.h"
#include "test_tp2.h"
#include "malib.h"

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
        (NULL == CU_add_test(pSuite, "Validation format evenement", test_validerEvenement)) ||
        (NULL == CU_add_test(pSuite, "Validation comparaison timestamp", test_validerTimestamp)) ||
        (NULL == CU_add_test(pSuite, "Validation de l'ordre timestamp", test_actualiserTimestamp))||
        (NULL == CU_add_test(pSuite, "Validation du format du tableau 2d", test_validerTab)) ||
        (NULL == CU_add_test(pSuite, "Validation du nombre de paramètre", test_validerNbrParam)) ||
        (NULL == CU_add_test(pSuite, "Operation evenement 01", test_opEvent01)) ||
        (NULL == CU_add_test(pSuite, "Operation evenement 02", test_opEvent02)) ||
        (NULL == CU_add_test(pSuite, "Operation evenement 03", test_opEvent03))
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
