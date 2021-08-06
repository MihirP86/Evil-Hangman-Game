#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <string.h>

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(hString == NULL)
    {
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  if(my_string_get_size(hString) != 0)
    {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	     "Did not receive 0 from get_size after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	      , length);
    }

  my_string_destroy(&hString);
  
  return status;
}

Status test_mparekh_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  
  Status status;

  hString = my_string_init_default();

  if(my_string_get_capacity(hString) != 7)
    {
      status = FAILURE;

      printf("Expected a capacity of 7 but got %d\n" , my_string_get_capacity(hString));

      strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n" "Did not recieve 7 from get_capacity after init_default\n", length);

    }

  else
    {
      status = SUCCESS;

      strncpy(buffer, "test_get_capacity_on_init_default_return_7\n", length);
    }

  my_string_destroy(&hString);

  return status;
}

Status test_mparekh_string_empty_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  my_string_push_back(hString, 'M');

  if(my_string_empty(hString) == 1)
    {
      status = FAILURE;
      printf("Expected a return value of 0 but got %d\n", my_string_empty(hString));
      strncpy(buffer, " test_mparekh_string_empty_on_init_c_string_returns_1\n"
              "Did not receive 1 from string_empty after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, " test_mparekh_string_empty_on_init_c_string_returns_0\n"
              , length);
    }
  my_string_destroy(&hString);
  return status;
}

//init_c_string

Status test_mparekh_get_capacity_on_init_c_string_returns_5(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_c_string("Mihir");
  
  if((my_string_get_capacity(hString)-1) != 5)
    {
      status = FAILURE;
      printf("Expected a capcity of 5 but got %d\n", my_string_get_capacity(hString));
      strncpy(buffer, "test_mparekh_get_capacity_on_init_c_string_returns_5\n"
	      "Did not receive 5 from get_capacity after init_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_get_capacity_on_init_c_string_returns_5\n"
	      , length);
    }
  my_string_destroy(&hString);
  return status;
}


Status test_mparekh_get_size_on_init_c_string_returns_5(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Mihir");

  if((my_string_get_size(hString)) != 5)
    {
      status = FAILURE;
      printf("Expected a size of 5 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_mparekh_get_size_on_init_c_string_returns_5\n"
              "Did not receive 5 from get_capacity after init_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_get_size_on_init_c_string_returns_5\n"
              , length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_mparekh_string_empty_on_init_c_string_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("Mihir");

  if(my_string_empty(hString) == 1)
    {
      status = FAILURE;
      printf("Expected a return value of 0 but got %d\n", my_string_empty(hString));
      strncpy(buffer, " test_mparekh_string_empty_on_init_c_string_returns_1\n"
              "Did not receive 1 from string_empty after init_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, " test_mparekh_string_empty_on_init_c_string_returns_0\n"
              , length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_mparekh_my_string_compare_when_Left_is_bigger_returns_1(char* buffer, int length)
{

   MY_STRING hLeft_string = NULL;
   MY_STRING hRight_string = NULL;

   Status status;
  
  hLeft_string = my_string_init_c_string("Apple");
  hRight_string = my_string_init_c_string("App");

  if (my_string_compare(hLeft_string, hRight_string) != 1)
    {
      status = FAILURE;
      
      printf("Expected a string compare result of 1 but got %d\n" , my_string_compare(hLeft_string, hRight_string));

      strncpy(buffer, "test_mparekh_my_string_compare_when_Left_is_bigger_returns_1\n" "Did not recieve 1 from my_string_compare\n", length);

    }

  else
    {
      status = SUCCESS;

      strncpy(buffer, "test_mparekh_my_string_compare_returns_1\n", length);
    }


  my_string_destroy(&hLeft_string);

  my_string_destroy(&hRight_string);

  return status;
}

Status test_mparekh_my_string_compare_when_Right_is_bigger_returns_neg_1(char* buffer, int length)
{

   MY_STRING hLeft_string = NULL;
   MY_STRING hRight_string = NULL;

   Status status;

  hLeft_string = my_string_init_c_string("App");
  hRight_string = my_string_init_c_string("Apple");

  if (my_string_compare(hLeft_string, hRight_string) != -1)
    {
      status = FAILURE;

      printf("Expected a string compare result of -1 but got %d\n" , my_string_compare(hLeft_string, hRight_string));

      strncpy(buffer, "test_mparekh_my_string_compare_when_Right_is_bigger_returns_1\n" "Did not recieve -1 from my_string_compare\n", length);

    }

  else
    {
      status = SUCCESS;
      
      strncpy(buffer, "test_mparekh_my_string_compare_returns_1\n", length);
    }
  
  my_string_destroy(&hLeft_string);
  
  my_string_destroy(&hRight_string);

  return status;
}



Status test_mparekh_my_string_compare_when_strings_are_NULL_returns_0(char* buffer, int length)
{

   MY_STRING hLeft_string = NULL;
   MY_STRING hRight_string = NULL;

   Status status;

   hLeft_string = my_string_init_c_string("Mihir");
   hRight_string = my_string_init_c_string("Mihir");
   
   if (my_string_compare(hLeft_string, hRight_string) != 0)
     {
       status = FAILURE;
       
       printf("Expected a string compare result of 0 but got %d\n" , my_string_compare(hLeft_string, hRight_string));
       
       strncpy(buffer, "test_mparekh_my_string_compare_when_strings_are_NULL_returns_0\n" "Did not recieve 0 from my_string_compare\n", length);
       
     }
   
   else
     {
       status = SUCCESS;
       
       strncpy(buffer, "test_mparekh_my_string_compare_when_strings_are_NULL_returns_0\n", length);
     }
   
   
   my_string_destroy(&hLeft_string);
   
   my_string_destroy(&hRight_string);
   
   return status;
}


//string_extraction

Status test_mparekh_string_extraction_reads_empty_file_returns_FAILURE(char* buffer, int length)
{
  MY_STRING hString = NULL;

  FILE* fp;
  
  Status status;
  
  hString = my_string_init_default();
  
  fp = fopen("empty.txt", "r");

  Status extract_result = my_string_extraction(hString, fp);
  
  if(extract_result != FAILURE)
    {
      status = FAILURE;
      printf("Expected a return status of FAILURE but got SUCCESS\n");
      strncpy(buffer, "test_mparekh_string_extraction_reads_empty_file_returns_FAILURE\n"
	      "Did not receive FAILURE from my_string_extraction\n", length);
    }
    else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_extraction_reads_empty_file_returns_FAILURE\n"
              , length);
    }

    my_string_destroy(&hString);
    
    fclose(fp);
    
    return status;
}
    
Status test_mparekh_get_size_on_string_extraction_returns_greater_than_0(char* buffer, int length)
{
  MY_STRING hString = NULL;

  FILE* fp;

  Status status;

  hString = my_string_init_default();

  fp = fopen("simple.txt", "r");

  my_string_extraction(hString, fp);

  if(my_string_get_size(hString) <= 0)
    {
      status = FAILURE;

      printf("Expected a size greater than 0 but got %d\n" , my_string_get_size(hString));

      strncpy(buffer, "test_mparekh_get_size_on_string_extraction_returns_greater_than_0\n" "Did not recieve a number greater than 0 from get_size after string_extraction\n", length);

    }

  else
    {
      status = SUCCESS;

      strncpy(buffer, "test_mparekh_get_size_on_string_extraction_returns_greater_than_0\n", length);
    }

  my_string_destroy(&hString);
  
  fclose(fp);
  
  return status;
}


Status test_mparekh_string_extraction_returns_SUCCESS(char* buffer, int length)
{
  MY_STRING hString = NULL;

  FILE* fp;

  Status status;

  hString = my_string_init_default();
  
  fp = fopen("simple.txt", "r");
  
  if(my_string_extraction(hString, fp) != SUCCESS)
    {
      status = FAILURE;
      
      printf("Expected string_extraction to return SUCCESS but got FAILURE\n");
      
      strncpy(buffer, "test_mparekh_string_extraction_returns_SUCCESS\n" "Did not return SUCCESS from string_extraction\n", length);
      
    }

  else
    {
      status = SUCCESS;
      
      strncpy(buffer, " test_mparekh_string_extraction_returns_SUCCESS\n", length);
    }

  my_string_destroy(&hString);
  
  fclose(fp);
  
  return status;
}

//string_insertion
Status test_mparekh_string_insertion_returns_SUCCESS(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  
  if(my_string_insertion(hString, stdout) != SUCCESS)
    {
      status = FAILURE;

      printf("Expected string_insertion to return SUCCESS but got FAILURE\n");

      strncpy(buffer, "test_mparekh_string_insertion_returns_SUCCESS\n" "Did not return SUCCESS from string_insertion\n", length);

    }

  else
    {
      status = SUCCESS;

      strncpy(buffer, " test_mparekh_string_insertion_returns_SUCCESS\n", length);
    }

  my_string_destroy(&hString);

  return status;
}

//string_push_back
Status test_mparekh_string_push_back_returns_SUCCESS(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  my_string_push_back(hString, 'M');
    
  if(my_string_empty(hString)!= 0)
    {
      status = FAILURE;
      printf("Expected a return value of 1 but got %d\n", my_string_empty(hString) );
      strncpy(buffer, "test_mparekh_string_push_back_returns_SUCCESS\n"
              "Did not receive 1 from my_string_empty\n", length);
    }
    else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_push_back_returns_SUCCESS\n"
              , length);
    }

    my_string_destroy(&hString);

    return status;
}

//string_pop_back
Status test_mparekh_string_pop_back_returns_FAILURE(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  my_string_push_back(hString, 'M');

  my_string_pop_back(hString);
  
  if(my_string_pop_back(hString) == SUCCESS)
    {
      status = FAILURE; 
      
      printf("Expected a retrun FAILURE but got SUCCESS\n"); 
      strncpy(buffer, "test_mparekh_string_pop_back_returns_FAILURE\n" 
	      "Did not receive FAILURE from my_string_pop_back\n", length); 
    }
  else 
    { 
      status = SUCCESS; 
      strncpy(buffer, "*/test_mparekh_string_pop_back_returns_FAILURE\n"
              , length);
    }
  
  my_string_destroy(&hString);
  
  return status;
}

Status test_mparekh_string_pop_back_returns_SUCCESS(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  my_string_push_back(hString, 'M');

  if (my_string_pop_back(hString) != SUCCESS)
    {
      status = FAILURE;
      printf("Expected a retrun SUCCESS but got FAILURE\n");
      strncpy(buffer, "test_mparekh_string_pop_back_returns_SUCCESS\n"
              "Did not receive 1 from my_string_empty\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_pop_back_returns_SUCCESS\n"
              , length);
    }

  my_string_destroy(&hString);

  return status;
}
//string_at
Status test_mparekh_string_at_returns_r_at_position_4(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  my_string_push_back(hString, 'M');

  my_string_push_back(hString, 'i');

  my_string_push_back(hString, 'h');

  my_string_push_back(hString, 'i');

  my_string_push_back(hString, 'r');

  
  if(*my_string_at(hString, 4) != 'r')
    {
      status = FAILURE;
      printf("Expected a retrun value of r but got %c\n", *my_string_at(hString, 4));
      strncpy(buffer, " test_mparekh_string_at_returns_r_at_position_4\n"
              "Did not receive r from my_string_at\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, " test_mparekh_string_at_returns_r_at_position_4\n"
              , length);
    }

  my_string_destroy(&hString);

  return status;
}

Status test_mparekh_string_at_returns_NULL_at_position_neg_1(char* buffer, int length)
{
  MY_STRING hString = NULL;
  
  Status status;
  
  hString = my_string_init_default();
  
  my_string_push_back(hString, 'M');
  
  my_string_push_back(hString, 'i');
  
  my_string_push_back(hString, 'h');
  
  my_string_push_back(hString, 'i');
  
  my_string_push_back(hString, 'r');
  
  
  if(my_string_at(hString, -1) != NULL)
    {
      status = FAILURE;
      printf("Expected a retrun value of NULL but got %c\n", *my_string_at(hString, -1));
      strncpy(buffer, "test_mparekh_string_at_returns_NULL_at_position_neg_1\n"
              "Did not receive NULL from my_string_at\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_at_returns_NULL_at_position_neg_1\n"
              , length);
    }
  
  my_string_destroy(&hString);
  
  return status;
}

//string_c_str
Status test_mparekh_string_c_str_returns_char_M(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  my_string_push_back(hString, 'M');

  my_string_push_back(hString, 'i');

  my_string_push_back(hString, 'h');

  my_string_push_back(hString, 'i');

  my_string_push_back(hString, 'r');
  
  if(*my_string_c_str(hString) != 'M')
    {
      status = FAILURE;
      printf("Expected to return character M but got %c\n", *my_string_c_str(hString));
      strncpy(buffer, "test_mparekh_string_c_str_returns_char_M\n"
              "Did not receive character M from my_string_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_c_str_returns_char_M\n"
              , length);
    }
  
  my_string_destroy(&hString);

  return status;
}
/*
Status test_mparekh_string_c_str_ends_a_string_with_NULL_character(char* buffer, int length)
{
  MY_STRING hString = NULL;

  Status status;

  hString = my_string_init_default();

  my_string_push_back(hString, 'M');

  my_string_push_back(hString, 'i');

  my_string_push_back(hString, 'h');

  my_string_push_back(hString, 'i');

  my_string_push_back(hString, 'r');

  my_string_c_str(hString);
  
  if(*my_string_at(hString, 5) != '\0')
    {
      status = FAILURE;
      printf("Expected to return character NULL but got %c\n", *my_string_at(hString, 5));
      strncpy(buffer, "test_mparekh_string_c_str_ends_a_string_with_NULL_character\n"
              "Did not receive character NULL from my_string_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_c_str_ends_a_string_with_NULL_character\n"
              , length);
    }
  my_string_destroy(&hString);
  
  return status;
}
*/

//string_concat

Status test_mparekh_string_concat_returns_SUCCESS(char* buffer, int length)
{
  MY_STRING abc = NULL;
  MY_STRING def = NULL;

  abc = my_string_init_c_string("abc");
  def = my_string_init_c_string("def");

  Status status;

  if (my_string_concat(abc, def) != SUCCESS)
    {
      status = FAILURE;
      printf("Expected to return SUCCESS but got FAILURE");
      strncpy(buffer, "test_mparekh_string_concat_returns_SUCCESS\n"
              "Did not receive SUCCESS from my_string_concat\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_concat_returns_SUCCESS\n"
              , length);
    }

  my_string_destroy(&abc);
  my_string_destroy(&def);

  return status;
}

Status test_mparekh_string_concat_a_and_b_returns_ab(char* buffer, int length)
{
  MY_STRING a = NULL;
  MY_STRING b = NULL;

  a = my_string_init_c_string("a");
  b = my_string_init_c_string("b");

  Status status;

  my_string_concat(a, b);
  
  if (*my_string_at(a, 1) != 'b')
    {
      status = FAILURE;
      printf("Expected to return character b but got %c", *my_string_at(a , 1));
      strncpy(buffer, "test_mparekh_string_concat_a_and_b_returns_ab\n"
              "Did not receive character b from my_string_at\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_string_concat_a_and_b_returns_ab\n"
              , length);
    }

  my_string_destroy(&a);
  my_string_destroy(&b);

  return status;
}

//string_destroy
Status test_mparekh_my_string_empty_on_destroy_returns_1(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  Status status;

  my_string_destroy(&hString);

  
  if (hString != NULL)
    {
      status = FAILURE;
      printf("Expected to return NULL but got garbage memory\n");
      strncpy(buffer, "test_mparekh_my_string_empty_on_destroy_returns_1\n"
              "Did not receive 1 from my_string_empty\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_my_string_empty_on_destroy_returns_1\n"
              , length);
    }

  return status;
}

//pushback functions

Status test_mparekh_Car_switched_with_Jav_using_pop_push(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("Car");
  
  my_string_pop_back(hString);
  my_string_pop_back(hString);
  my_string_pop_back(hString);

  my_string_push_back(hString, 'J');
  my_string_push_back(hString, 'a');
  my_string_push_back(hString, 'v');
  
  Status status;

  if (*my_string_at(hString, 0) == 'J' && *my_string_at(hString, 1) == 'a' && *my_string_at(hString, 2) == 'v')
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_Car_switched_with_Jav_using_pop_push\n"
              , length);
    }
  else
    {
      status = FAILURE;
      printf("Expected to string to have Jav but got %c%c%c\n", *my_string_at(hString, 0), *my_string_at(hString, 1), *my_string_at(hString, 2));
      strncpy(buffer, "test_mparekh_Car_switched_with_Jav_using_pop_push\n"
              "Did not recieve Jav from my_string_at", length);

    }

  my_string_destroy(&hString);
  
  return status;
}

Status test_mparekh_Car_switched_with_Jav_using_pop_push_and_return_size_3(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("Car");

  my_string_pop_back(hString);
  my_string_pop_back(hString);
  my_string_pop_back(hString);
  
  my_string_push_back(hString, 'J');
  my_string_push_back(hString, 'a');
  my_string_push_back(hString, 'v');
  
  Status status;
  
  if (my_string_get_size(hString) == 3)
    {
      status = SUCCESS;
      strncpy(buffer, "test_mparekh_Car_switched_with_Jav_using_pop_push_and_return_size_3\n"
              , length);
    }
  else
    {
      status = FAILURE;
      printf("Expected to return 3 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_mparekh_Car_switched_with_Jav_using_pop_push_and_return_size_3\n"
              "Did not recieve a 3 from my_string_get_size", length);

    }
  
  my_string_destroy(&hString);
  
  return status;
}
