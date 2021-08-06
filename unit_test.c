#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
   //init defeault
   test_init_default_returns_nonNULL,
   test_get_size_on_init_default_returns_0,
   test_mparekh_get_capacity_on_init_default_returns_7,
   test_mparekh_string_empty_on_init_default_returns_0,
   //init_c_string
   test_mparekh_get_capacity_on_init_c_string_returns_5,
   test_mparekh_get_size_on_init_c_string_returns_5,
   test_mparekh_string_empty_on_init_c_string_returns_0,
   // test_mparekh_init_c_string_returns_nonNULL,
   //string_compare
   test_mparekh_my_string_compare_when_Left_is_bigger_returns_1,
   test_mparekh_my_string_compare_when_Right_is_bigger_returns_neg_1,
   test_mparekh_my_string_compare_when_strings_are_NULL_returns_0,
   //string_extraction
   test_mparekh_string_extraction_reads_empty_file_returns_FAILURE,
   test_mparekh_get_size_on_string_extraction_returns_greater_than_0,
   test_mparekh_string_extraction_returns_SUCCESS,
   //string_insertion
   test_mparekh_string_insertion_returns_SUCCESS,
   //string_push_back
   test_mparekh_string_push_back_returns_SUCCESS,
   //string_pop_back
   test_mparekh_string_pop_back_returns_FAILURE,
   test_mparekh_string_pop_back_returns_SUCCESS,
   //string_at
   test_mparekh_string_at_returns_r_at_position_4,
   test_mparekh_string_at_returns_NULL_at_position_neg_1,
   //string_c_str
   test_mparekh_string_c_str_returns_char_M,
   // test_mparekh_string_c_str_ends_a_string_with_NULL_character
   //string_concat
   test_mparekh_string_concat_returns_SUCCESS,
   test_mparekh_string_concat_a_and_b_returns_ab,
   //destroy
   test_mparekh_my_string_empty_on_destroy_returns_1,
   //Extra tests
   test_mparekh_Car_switched_with_Jav_using_pop_push,
   test_mparekh_Car_switched_with_Jav_using_pop_push_and_return_size_3
 };
 
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 
 int i;
 
 char buffer[500];
 
 int success_count = 0;
 
 int failure_count = 0;
 
 for(i=0; i<number_of_functions; i++)
   {
     
     if(tests[i](buffer, 500) == FAILURE)
       {
	 printf("FAILED: Test %d failed miserably\n", i);
	 printf("\t%s\n", buffer);
	 failure_count++;
       }
     else
       {
	 // printf("PASS: Test %d passed\n", i);
	 // printf("\t%s\n", buffer);
	 success_count++;
       }
   }
 
 printf("Total number of tests: %d\n", number_of_functions);

 printf("%d/%d Pass, %d/%d Failure\n", success_count,
	number_of_functions, failure_count, number_of_functions);

 return 0;
}
