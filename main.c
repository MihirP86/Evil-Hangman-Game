#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic_vector.h"
#include "tree.h"
//#include "avl.h"
#include <ctype.h>

void clear_keyboard_buffer(void);

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);

int main(int argc, char* argv[])
{
  NODE max;
  NODE hTree;
  GENERIC_VECTOR vector[30];
  GENERIC_VECTOR curr_vector;
  GENERIC_VECTOR temp;
  MY_STRING curr_word;
  MY_STRING current_word_family;
  MY_STRING new_key;
  MY_STRING word;
  MY_STRING guessed_letters;
  FILE* fp;
  int i;
  int word_size;
  int word_length;
  int total_guesses;
  int current_guess;
  int noc;
  int dash_count = 0;
  int num_count = 0;
  int num;
  char guess;
  char again;
 
  //infinite loop
  while (1)
    {
      //Step 1:
      for ( i = 0; i < 30; i++)
	{
	  vector[i] = generic_vector_init_default((ITEM)my_string_assignment,(ITEM)my_string_destroy);
	}
      curr_vector = generic_vector_init_default((ITEM)my_string_assignment, (ITEM) my_string_destroy);
      
      //Step 2:
      fp = fopen("dictionary.txt", "r");
      curr_word = my_string_init_default();

      while (my_string_extraction(curr_word, fp))
	{
	  //find the vector by length
	  word_size = my_string_get_size(curr_word);
	  //put current word in vector
	  generic_vector_push_back(vector[word_size], curr_word);
	  //reset curr_word for next loop
	  my_string_destroy(&curr_word); 
	  curr_word = my_string_init_default();
	}
      
      fclose(fp);
      my_string_destroy(&curr_word);
      
      //Step 3:
      word_length = 0;
      do
	{
	  printf("Enter a valid word length:\n");
	  noc = scanf("%d", &word_length);
	  clear_keyboard_buffer();
	 }
      while(word_length < 0 || word_length > 46 || noc != 1);
      
      //Step 4:
      
      for (i = 0; i < 30; i++)
	{
	  if (i != word_length)
	    {
	      generic_vector_destroy(&vector[i]);
	    }
	}
      
      //Step 5:
      // curr_vector = vector[word_length];
      for (i = 0; i < generic_vector_get_size(vector[word_length]) ; i++)
        {
	  generic_vector_push_back(curr_vector, generic_vector_at(vector[word_length], i));
        }
      
      current_word_family = my_string_init_default();
      
      for (i = 0; i < word_length; i++)
	{
	  my_string_push_back(current_word_family, '-');
	}

      //Step 6:
      total_guesses = 0;
      
      do
	{
	  printf("Enter a valid number of guesses:\n");
	  noc = scanf("%d", &total_guesses);
	  clear_keyboard_buffer();
	}
      while(total_guesses < 0 || total_guesses > 26 || noc != 1);
      
      current_guess = 0;
      
      //Step 7:
      
      guessed_letters = my_string_init_default();
      
      //HANGMAN GAME START:
      while( total_guesses != 0)
	{
	  
	  dash_count = 0;
	  
	  for (i = 0; i < my_string_get_size(current_word_family); i++)
	    {
	      if (*my_string_at(current_word_family, i) != '-')
		{
		  dash_count++;
		}
	    }
		  
	  if (dash_count == my_string_get_size(current_word_family))
	    {
	      printf("Congratulations you guessed a letter!\n");
	      break;
	    }
	  /*
	  if (current_guess != 0)
	    {
	      in_order_print(hTree);
	    }
	  */ 	      
	  printf("Word: %s\n", my_string_c_str(current_word_family));
	  
	  printf("You have %d guesses left\n", (total_guesses));
	  hTree = tree_init_default();
	  
	  if (current_guess != 0)
	    {
	      printf("You have guessed these letters so far: ");
	      for (i = 0; i < my_string_get_size(guessed_letters); i++)
		{
		  printf("%c ", *my_string_at(guessed_letters, i));
		}
	      printf("\n");
	    }
	  
	  do
	    {
	      printf("Guess a letter:\n");
	      noc = scanf(" %c", &guess);
	      clear_keyboard_buffer();
	      
	    }
	  while (noc != 1);
	  // printf("Bro\n");
	  
	  guess = tolower(guess);
	  // printf("Fool\n");
	  my_string_push_back(guessed_letters, guess);
	  //Makes keys 
	  //printf("The new curr_vector size is: %d\n", generic_vector_get_size(curr_vector));
	  
	  for(i = 0; i < generic_vector_get_size(curr_vector); i++)
	    {
	      // printf("The %d\n", generic_vector_get_size(curr_vector));
	      new_key = my_string_init_default();
	      
	      word = generic_vector_at(curr_vector, i);
	      // printf("The word is: %s ", my_string_c_str(word));
	      get_word_key_value(current_word_family, new_key, word, guess);
	      // get_word_key_value(new_key, current_word_family, word, guess);
	      // printf("The key is: %s ", my_string_c_str(new_key));
	      // printf("The key is: %s", my_string_c_str(new_key));
	      hTree = tree_insert(hTree, new_key, word);
	      // key_print(hTree);
	      // printf("Hi\n");
	      my_string_destroy(&new_key);
	      // my_string_destroy(&word);
	    }
	  //change current word family here
	  /*
	  for (i = 0; i < my_string_get_size(current_word_family); i++)
            {
              if (*my_string_at(current_word_family, i) == '-')
                {
                  num_count++;
                }
            }

	  if (num_count == my_string_get_size(current_word_family))
	    {
	      printf("You weren't able to guess a letter!\n");
	    }
	  */
	  
	  generic_vector_destroy(&curr_vector);
	  max = max_init_default();
	  // printf("THIS IS THE TREE!\n");
	  // key_print(hTree);
	  // pre_order_print(hTree);
	  // max = in_order_trav_max(hTree, max);
	  //printf("THIS IS THE MAX OF THE TREE\n");
	  // key_print(max)
	  // pre_order_print(max);
	  // printf("Hi\n");
	  in_order_print(hTree);
	  
	  max = in_order_trav_max(hTree, max);
	  
	  temp = generic_vector_init_default((ITEM)my_string_assignment, (ITEM) my_string_destroy);
	    
	  for (i = 0; i < generic_vector_get_size(swap_known_generic(max)); i++)
	    {
	      generic_vector_push_back(temp, generic_vector_at(swap_known_generic(max), i));
	    }

	  for (i = 0; i < my_string_get_size(current_word_family); i++)
            {
              if (*my_string_at(current_word_family, i) == '-')
                {
                  num_count++;
                }
            }

          if (num_count == my_string_get_size(current_word_family))
            {
              printf("You weren't able to guess a letter!\n\n");
            }

	  //in_order_print(hTree);
	  /*
	  for (i = 0; i < generic_vector_get_size(temp); i++)
	    {
	      printf("%s ", my_string_c_str(generic_vector_at(temp, i)));
	    }
	  */
	  // printf("Sleep");
	  
	  // generic_vector_push_back(
	  swap(&curr_vector, &temp);
	  //printf("After swap curr_vector has a size of: %d\n", generic_vector_get_size(curr_vector) );
	  //pre_order_print(max);
	  my_string_destroy(&current_word_family);
	  // printf("Hi3\n");
	  current_word_family = my_string_init_default();
	  // printf("Hi4\n");
	  //make a deep copy of key and destroy
	  // temp_string = my_string_init_c_str(*my_string_c_str(swap_known_string(max)));
	  my_string_concat(current_word_family, swap_known_string(max));
	  // in_order_print(hTree);
	  num = total_guesses - 1;
	  
	  if(num == 0)
	    {
	      num = rand() % generic_vector_get_size(curr_vector);
	      printf("Sorry your out of guesses! The word was: %s\n", my_string_c_str(generic_vector_at(curr_vector, num)));
	      //in_order_print(hTree);
	      tree_destroy(&hTree);
	      tree_destroy(&max);
	      break;
	    }
	  else
	    {
	      total_guesses--;
	    }
	  
	  // free(&(swap_known_string(max)))
	  //p printf("The key is: %s", my_string_c_str(new_key));
	  // printf("Hi5\n");
	  tree_destroy(&hTree);
	  tree_destroy(&max);
	  current_guess++;
	}
      
      // pre_order_print(hTree);
      generic_vector_destroy(&vector[word_length]);
      // printf("Hi6\n");
      generic_vector_destroy(&curr_vector);
      // printf("Hi7\n");
      my_string_destroy(&current_word_family);
      // printf("Hi8\n");
      // my_string_destroy(&new_key);
      // printf("Hi9\n");
      my_string_destroy(&guessed_letters);
      // printf("Hi10\n");
      // tree_destroy(&max);
      // printf("H11\n");
      // tree_destroy(&hTree);
      printf("Do you want to play again?(y/n)\n");
      scanf("%c", &again);
      if ( again != 'y' || again != 'Y')
	{
	  break;
	}
      
    }
  return 0;
}
 
 void clear_keyboard_buffer(void)
{
    char c;
    int noc;

    noc = scanf("%c", &c);

    while (noc == 1 && c != '\n')
    {
        noc = scanf("%c", &c);
    }
}
  
Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
  /*
  My_string* pCurrent_wf = (My_string*) current_word_family;
  My_string* pNew_key = (My_string*) new_key;
  My_string* pWord = (My_string*) word;
  */
  //if new_key already has something
  // printf("The guess is: %c\n", guess);
  // pNew_key->size = 0;
  
  //my_string_destroy(&new_key);
  //new_key = my_string_init_default();
  //copy

  // my_string_concat(pNew_key , pCurrent_wf);

  for (int i = 0; i < my_string_get_size(current_word_family); i++)
    {
      my_string_push_back(new_key, *my_string_at(current_word_family, i));
    }

  for(int i = 0; i < my_string_get_size(word); i++)
    {
      //printf("%c %c\n" , pWord->data[i], guess);
      if (*my_string_at(word, i) == guess)
        {
          //printf("Hi\n");
          *my_string_at(new_key, i) = tolower(*my_string_at(word, i));
        }
    }
  return SUCCESS;
}
