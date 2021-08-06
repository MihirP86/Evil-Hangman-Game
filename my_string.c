#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "status.h"
#include <ctype.h>

struct my_string {
  int size;
  int capacity;
  char* data;
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void) {
  My_string* pString;

  pString = (My_string*)malloc(sizeof(My_string));

  if(pString != NULL) {
    pString->size = 0;
    pString->capacity = 7;
    pString->data = (char*)malloc(sizeof(char) * pString->capacity);
    if(pString->data == NULL) {
      free(pString);
      return NULL;
    }
  }
  return pString;
}

MY_STRING my_string_init_c_string(const char* c_string) {
  // int i;
  int count = 0;
  // int j = 0;
  My_string* pString2;

  pString2 = (My_string*)malloc(sizeof(My_string));

  if(pString2 != NULL)
    {
      for(int i = 0; c_string[i] != '\0'; i++)
	{
	  count++;
	}
      pString2->size = count;
      //  printf("The size is: %d\n", pString2->size);
    
      pString2->capacity = count + 1;
      pString2->data = (char*)malloc(sizeof(char) * pString2->capacity);

      if(pString2->data == NULL) {
	return NULL;
      }

      for(int i = 0; i < pString2->capacity; i++)
	{
	  pString2->data[i] = c_string[i];
	} 
    }

  return (MY_STRING)pString2;
  
}

int my_string_get_capacity(MY_STRING hMy_string) {
  My_string* pString = (My_string*)hMy_string;
return pString->capacity;

}

int my_string_get_size(MY_STRING hMy_string) {
  My_string* pString = (My_string*)hMy_string;
  return pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
				  
  My_string* pString_Left = (My_string*) hLeft_string;
  My_string* pString_Right = (My_string*) hRight_string;
  
  int i;
  //ask tutor
  //compares stuff like app and apple but will exit this for loop
  for (i = 0; i != pString_Left->size && i != pString_Left->size; i++)
    {
      if(pString_Left->data[i] > pString_Right->data[i])
	{
	  return 1;
	}
      if(pString_Right->data[i] > pString_Left->data[i])
	{
	  return -1;
	}
    }
  
  int left_subtract = pString_Left->size - pString_Right->size;
  int right_subtract = pString_Right->size - pString_Left->size;

  if (left_subtract > right_subtract)
    {
      return 1;
    }
  else if (right_subtract > left_subtract)
    {
      return -1;
    }
  else
    {
      return 0;
    }
}
/*
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {

  My_string* pString_Left = (My_string*) hLeft_string;
  My_string* pString_Right = (My_string*) hRight_string;

  int i = 0;
  //ask tutor
  while( pString_Left->data[i] != '\0' && pString_Right->data[i] != '\0')
    {
      if(pString_Left->data[i] > pString_Right->data[i])
	{
	  return 1;
	}
      else if(pString_Right->data[i] > pString_Left->data[i])
	{
	  return -1;
	}
      i++;
    }
  
  return 0;
}
*/
Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
  
  My_string* pString = (My_string*) hMy_string;
  
  pString->size = 0;
  //char ch;
  int i;
  if(fp == NULL)
    {
      return FAILURE;
    }
  
  char c  = fgetc(fp);
  
  if(c == EOF)
    {
      return FAILURE;
    }
  
  // int noc = fscanf(fp, "%c", &c);
  //ignores leading white space
  /*
    while (isspace(ch) == 1)
    {
       ch = fgetc(fp);
    }
  */
  //isspace c type library
  
  while(!isspace(c) && c != EOF){
    
    pString->data[pString->size] = c;
    
    pString->size++;
    
    if( pString->size >= pString->capacity) {
      
      char* temp = (char*)malloc(sizeof(char) * pString->capacity * 2);
     
      if(temp == NULL)
	{
	  return FAILURE;
	}
      
      for (i = 0; i < pString->size; i++)
	{
	  temp[i] = pString->data[i];
	}
      
      free(pString->data);
     
      pString->data = temp;
      pString->capacity *= 2;
    }
    
    c = fgetc(fp);
    
  }
  //while ends here
  
  if(c == ' ' || c == EOF )
    {
      ungetc(c, fp);
    }

  return SUCCESS;
  
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {

  My_string* pString = (My_string*) hMy_string;
  
  int i;

  // printf("%d", my_string_get_size(hMy_string));
  
  for( i = 0; i < my_string_get_size(hMy_string); i++) {
    fputc(pString->data[i], fp);
  }
  
  return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item) {

  My_string* pString = (My_string*) hMy_string;

  int i;


  if(pString->size >= pString->capacity)
    {
      char* temp = (char*)malloc(sizeof(char) * pString->capacity  * 2);

      if( temp == NULL)
	{
	  return FAILURE;
	}
   
      for (i = 0; i < pString->size; ++i)
	{
	  temp[i] = pString->data[i];
	}

      free(pString->data);

      pString->data = temp;

      pString->capacity *= 2;
    }

  pString->data[pString->size] = item;
  pString->size++;

  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string* pString = (My_string*) hMy_string;

  //add code to check if string is empty later 

  if(my_string_empty(hMy_string))
    {
      return FAILURE;
    }
  
  pString->size--;

  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string* pString = (My_string*) hMy_string;

  if( index < 0 || index >= pString->size )
    {
      return NULL;
    }

  return &pString->data[index];
}
  
char* my_string_c_str(MY_STRING hMy_string)
{
  My_string* pString = (My_string*) hMy_string;

  int i;

  if (pString->size >= pString->capacity)
    {
      char* temp = (char*)malloc(sizeof(char) *( pString->capacity + 1));

       if( temp == NULL)
        {
          return NULL;
        }

      for (i = 0; i < pString->size; ++i)
        {
          temp[i] = pString->data[i];
        }

      free(pString->data);

      pString->data = temp;

      pString->capacity = pString->capacity * 2;
    }
  
  pString->data[pString->size] = '\0';

  // return &(pString->data[0]);
  return my_string_at(hMy_string, 0);
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  My_string* pString = (My_string*) hMy_string;

  return (Boolean)(pString->size <= 0);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{

  My_string* pResult = (My_string*) hResult;
  My_string* pAppend = (My_string*) hAppend;

  int arr_size = pResult->size + pAppend->size;
  char* temp;
  int i;
  int j;
  
  if (arr_size >= pResult->capacity)
    {
      temp =  (char*)malloc(sizeof(char) * arr_size);

      if (temp == NULL)
	{
	  return FAILURE;
	}

      for (i = 0; i < pResult->size; i++)
	{
	  temp[i] = pResult->data[i];
	}
      free(pResult->data);

      pResult->data = temp;


      pResult->capacity = arr_size;

      //  pResult->size = pResult->capacity - 1;
    }

  // printf("Append size is: %d\n", pAppend->size);

  for (j = 0; j < pAppend->size; j++)
	 {
	   // printf("I'm in the j loop\n");
	   pResult->data[pResult->size++] = pAppend->data[j];
	   // printf("pResult: %c\n",  pResult->data[pResult->size - 1]);
	   // printf("pAppend: %c\n", pAppend->data[j]);
	 }
      
  // pResult->size = arr_size;
  return SUCCESS;
}

void my_string_assignment(ITEM* pLeft, ITEM Right)
{
  My_string* ppL = (My_string*) *pLeft;
  My_string* pR = (My_string*) Right;
  
  if(ppL == NULL)
    {
      char* temp_char = my_string_c_str(pR);
      ppL = my_string_init_c_string(temp_char);
      *pLeft = ppL;
    }
  else
    {//include this code in if statement too
      if (my_string_empty(ppL))
	{
	  my_string_concat((MY_STRING)ppL,(MY_STRING) pR);
	  *pLeft = ppL;
	}
      else
	{
	  for (int i = 0; i < ppL->size; i++)
	    {
	      my_string_pop_back(ppL);
	    }
	  
	  my_string_concat((MY_STRING)ppL,(MY_STRING) pR);
	  *pLeft = ppL;
	}
    }
}
//MOVE THIS TO THE MAIN.C
/*
Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
  My_string* pCurrent_wf = (My_string*) current_word_family;
  My_string* pNew_key = (My_string*) new_key; 
  My_string* pWord = (My_string*) word;

  //if new_key already has something
  // printf("The guess is: %c\n", guess);
  pNew_key->size = 0;
  
  //copy

  // my_string_concat(pNew_key , pCurrent_wf);
  
  for (int i = 0; i < pCurrent_wf->size; i++)
    {
      my_string_push_back(pNew_key, pCurrent_wf->data[i]);
    }
  
  for(int i = 0; i < pWord->size; i++)
    {
      //printf("%c %c\n" , pWord->data[i], guess);
      if (pWord->data[i] == guess)
	{
	  //printf("Hi\n");
	  pNew_key->data[i] = tolower(pWord->data[i]);
	}
    }

  printf("\nOld Key\n");

  for (int i = 0; i < pCurrent_wf->size; i++)
    {
      printf("%c", pCurrent_wf->data[i]);
    }

  printf("\nNew Key\n");
  
  for (int i = 0; i < pNew_key->size; i++)
    {
      printf("%c", pNew_key->data[i]);
    }
  
  printf("\n");
  
  return SUCCESS;
}
*/
void my_string_destroy(ITEM* pItem) {
  My_string* pString = (My_string*) *pItem;

  free(pString->data);
  free(pString);

  *pItem = NULL;
}
