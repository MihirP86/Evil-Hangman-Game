#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

//init_default
Status test_init_default_returns_nonNULL(char* buffer, int length);

Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status test_mparekh_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status test_mparekh_string_empty_on_init_default_returns_0(char* buffer, int length);

//init_c_stirng
Status test_mparekh_get_capacity_on_init_c_string_returns_5(char* buffer, int length);

Status test_mparekh_get_size_on_init_c_string_returns_5(char* buffer, int length);

Status test_mparekh_init_c_string_returns_nonNULL(char* buffer, int length);

Status test_mparekh_string_empty_on_init_c_string_returns_0(char* buffer, int length);

//string_compare
Status test_mparekh_my_string_compare_when_Left_is_bigger_returns_1(char* buffer, int length);

Status test_mparekh_my_string_compare_when_strings_are_NULL_returns_0(char* buffer, int length);

Status test_mparekh_my_string_compare_when_Right_is_bigger_returns_neg_1(char* buffer, int length);

//string_extraction
Status test_mparekh_string_extraction_reads_empty_file_returns_FAILURE(char* buffer, int length);

Status test_mparekh_get_size_on_string_extraction_returns_greater_than_0(char* buffer, int length);

Status test_mparekh_string_extraction_returns_SUCCESS(char* buffer, int length);

//string_insertion
Status test_mparekh_string_insertion_returns_SUCCESS(char* buffer, int length);

//string_push_back
Status test_mparekh_string_push_back_returns_SUCCESS(char* buffer, int length);

//string_pop_back
Status test_mparekh_string_pop_back_returns_FAILURE(char* buffer, int length);

Status test_mparekh_string_pop_back_returns_SUCCESS(char* buffer, int length);

//string_at
Status test_mparekh_string_at_returns_r_at_position_4(char* buffer, int length);

Status test_mparekh_string_at_returns_NULL_at_position_neg_1(char* buffer, int length);

//string_c_string
Status test_mparekh_string_c_str_returns_char_M(char* buffer, int length);

//Status test_mparekh_string_c_str_ends_a_string_with_NULL_character(char* buffer, int length);

//string_concat
Status test_mparekh_string_concat_returns_SUCCESS(char* buffer, int length);

Status test_mparekh_string_concat_a_and_b_returns_ab(char* buffer, int length);

//destroy
Status test_mparekh_my_string_empty_on_destroy_returns_1(char* buffer, int length);

//Extra tests
Status test_mparekh_Car_switched_with_Jav_using_pop_push(char* buffer, int length);

Status test_mparekh_Car_switched_with_Jav_using_pop_push_and_return_size_3(char* buffer, int length);
#endif
