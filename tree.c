#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "my_string.h"
#include "tree.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct node Node;

struct node
{
  MY_STRING key;
  GENERIC_VECTOR words;
  Node* Left;
  Node* Right;
  int height;
};
/*
typedef struct tree Tree;

struct tree
{
  Node* root;
};

*/


//Functions NEEDED:
void post_order_destroy(Node* hTree);  
//INIT?
//HAVE A MEMORY LEAK!!!
NODE tree_init_default(void)
{
  Node* pTree = NULL;
  
  return (NODE)pTree;
}

NODE new_Node(MY_STRING key, MY_STRING word)
{
  Node* pTree = (Node*)malloc(sizeof(Node));

  if (pTree != NULL)
    {
      // printf("Here\n");
      pTree->key = my_string_init_c_string(my_string_c_str(key));
      pTree->words = generic_vector_init_default((ITEM)my_string_assignment, (ITEM)my_string_destroy);
      generic_vector_push_back(pTree->words,(ITEM) word);
      pTree->Left = NULL;
      pTree->Right = NULL;
      pTree->height = 1;
    }
  return (NODE)pTree;
}
/*
NODE max_node(NODE a, NODE b)
{
  Node* pA = (Node*) a;
  Node* pB = (Node*) b;

  if(generic_vector_get_size(pA->words) > generic_vector_get_size(pB->words))
    {
      return (NODE)pA;
    }
  
  return (NODE)pB;
}
*/
//MAX FUNCTION:
int height(NODE hTree)
{
  Node* pTree = (Node*) hTree;
  if (pTree == NULL)
    {
      return 0;
    }
  return pTree->height;
}

int getBalance(NODE hTree)
{
  Node* pTree = (Node*) hTree;

  if (pTree == NULL)
    {
      return 0;
    }
  return height(pTree->Left) - height(pTree->Right);
}

NODE rightRotate(NODE y)
{
  // printf("Enter right rotate\n");
  Node* pY = (Node*) y;

  // printf("The key of y is: %s\n", my_string_c_str(pY->key));
  //IS not valid
  Node* x = pY->Left;
  // printf("The key of x is: %s\n", my_string_c_str(x->key));
  Node* T2 = x->Right;
  // printf("The key of T2 is: %s\n", my_string_c_str(T2->key));

  //rotation
  // printf("Hi1\n");
  x->Right = pY;
  // printf("Hi2\n");
  pY->Left = T2;
  // printf("Hi3\n");

  //Update Heights
  pY->height = max(height(pY->Left), height(pY->Right)) + 1;
  // printf("Hi4\n");
  
  x->height = max(height(x->Left), height(x->Right)) + 1;
  
  // printf("Hi5");

  return (NODE)x;
}

NODE leftRotate(NODE x)
{
  Node* pX = (Node*) x;
  Node* y = pX->Right;
  Node* T2 = y->Left;

  //perform rotation
  y->Left = pX;
  pX->Right = T2;

  pX->height = max(height(pX->Left), height(pX->Right)) + 1;
  y->height = max(height(y->Left), height(y->Right)) + 1;

  return y;
}

//  Node* newNode(
//BST
NODE tree_insert(NODE hTree, MY_STRING key, MY_STRING word)
{
  Node* pTree = (Node*) hTree;

  if (pTree == NULL)
    {
      return new_Node(key, word);
    }
  if (my_string_compare(key, pTree->key) == -1) //key is smaller
    {
      pTree->Left = tree_insert(pTree->Left , key, word);
    }
  else if (my_string_compare(key, pTree->key) == 1) //key is bigger
    {
      pTree->Right = tree_insert(pTree->Right, key, word);
    }
  else
    {
      generic_vector_push_back(pTree->words, (ITEM) word);
      return (NODE)pTree;
    }

  //Update height of this ancestor node
  pTree->height = 1 + max(height(pTree->Left), height(pTree->Right));

  int balance = getBalance(pTree);

  //Left Left Case
  if (balance > 1 && (my_string_compare(key, pTree->Left->key) == -1)) //key is smaller
    {
      //printf("The pTree is: %s\n", my_string_c_str(pTree->key));
      // printf("A\n");
      //in_order_print(pTree);
      // printf("\n---------\n");
      return rightRotate((NODE)pTree);
    }
  //Right Right Case
  if(balance < -1 && (my_string_compare(key, pTree->Right->key) == 1)) //key is biggerA
    {
      // printf("V\n");
      return leftRotate((NODE)pTree);
    }
  //Left Right Case
  if(balance > 1 && (my_string_compare(key, pTree->Left->key) == 1))
    {
      // printf("L\n");
      pTree->Left = leftRotate(pTree->Left);
      return rightRotate((NODE)pTree);
    }
  //Right Left Case
  if(balance < -1 && (my_string_compare(key, pTree->Right->key) == -1))
    {
      //printf("J\n");
      //in_order_print(pTree);
      //printf("\n---------\n");
      // printf("The right of the tree is: %s\n", my_string_c_str(pTree->Right->key));
      pTree->Right = rightRotate(pTree->Right);
      return leftRotate((NODE)pTree);
    }

  return (NODE)pTree;
}

void in_order_print(NODE hTree)
{
  Node* pTree = (Node*) hTree;

  if (pTree != NULL)
    {
      // pre_order_print(pTree->Left);
      in_order_print(pTree->Left);
      
      printf("Key: %s ",  my_string_c_str(pTree->key));

      printf("Size: %d ", generic_vector_get_size(pTree->words));

      printf("Node Height: %d\n", pTree->height);

      in_order_print(pTree->Right);
      // pre_order_print(pTree->Right);
    }
}

void pre_order_print(NODE hTree)
{
  Node* pTree = (Node*) hTree;
  
  if (pTree != NULL)
    {
      printf("The key for this Node is:\n");
      /*
      for (int i = 0; i < mt_string_get_size(pTree->ket); i++)
	{
	  printf("%c", *my_string_c_str(pTree->key));
	}
      */

      printf("%s", my_string_c_str(pTree->key)); 
      
      // printf("\n The words inside this key are:\n{");

      /*
      for (int j = 0; j < my_string_get_size(generic_vector_at(pTree->words, j)); j++)
	{
	  printf("%c", *my_string_at(generic_vector_at(pTree->words, j) ,my_string_get_size(generic_vector_at(pTree->words, j))));
	}
      */
      //problem here
      /*
      for (int i = 0; i < generic_vector_get_size(pTree->words) ; i++)
	{
	  // printf("%d\n", generic_vector_get_size(pTree->words));
	  printf("%s ", my_string_c_str(generic_vector_at(pTree->words, i)));
	}
      */
      // printf("}\n");
      
      pre_order_print(pTree->Left);
      pre_order_print(pTree->Right);
    }
}

NODE max_init_default(void)
{
  Node* max = (Node*)malloc(sizeof(Node));
  
  if (max != NULL)
    {
      max->key = my_string_init_default();
      max->words = generic_vector_init_default((ITEM)my_string_assignment, (ITEM)my_string_destroy);
      max->Left = NULL;
      max->Right = NULL;
      max->height = 1;
    }
  return (NODE)max;
}
//Need to make a swap for curr_vector and biggest size of node
NODE in_order_trav_max(NODE hTree, NODE max)
{
  Node* pTree = (Node*) hTree;

  Node* pMax = (Node*) max;

  int i;
  
  if(pTree != NULL)
    {
      //printf("Hi1\n");
      in_order_trav_max(pTree->Left, pMax);
      //Code:
      //printf("Hi2\n");
      if(generic_vector_get_size(pTree->words) > generic_vector_get_size(pMax->words))
        {
	  // *pMax = pTree;
	  
	  for (i = 0; i < generic_vector_get_size(pTree->words); i++)
	    {
	      generic_vector_pop_back(pMax->words);
	    }
	  // printf("The size of words: %d\n", generic_vector_get_size(pTree->words));
	  for (i = 0; i < generic_vector_get_size(pTree->words); i++)
	    {
	      // printf("Here\n");
	      // printf("%s ", my_string_c_str(generic_vector_at(pTree->words, i)));
	      generic_vector_push_back(pMax->words, generic_vector_at(pTree->words, i));
	      //printf("%s ", my_string_c_str(generic_vector_at(pMax->words, i)));
	      //printf("Here\n");
	    }

	  my_string_destroy(&pMax->key);

	  pMax->key = my_string_init_c_string(my_string_c_str(pTree->key));
	  /*
	  for (i = 0; i < generic_vector_get_size(pMax->words); i++)
	    {
              printf("%s ", my_string_c_str(generic_vector_at(pMax->words, i)));
            }
	  */
	  printf("\n");
	  printf("The biggest size of max words is: %d\n", generic_vector_get_size(pMax->words));
	  printf("The biggest key is: %s\n", my_string_c_str(pMax->key));
	  
        }
      
      in_order_trav_max(pTree->Right, pMax);
    }
 
  return (NODE)pMax;
}

GENERIC_VECTOR swap_known_generic( NODE max)
{
  Node* pMax = (Node*) max;

  return pMax->words;
}

MY_STRING swap_known_string(NODE max)
{
  Node* pMax = (Node*) max;

  return pMax->key;
}


void swap(GENERIC_VECTOR* curr_vector, GENERIC_VECTOR* pMax)
{ 
  GENERIC_VECTOR temp;

  temp = *curr_vector;

  *curr_vector = *pMax;

  *pMax = temp;
  
}

void key_print(NODE hTree)
{
  Node* pTree = (Node*) hTree;
  
  printf("%s\n", my_string_c_str(pTree->key));

}
//change function
void post_order_destroy(Node* hTree)
{
  Node* pTree = (Node*) hTree;

  if (pTree != NULL)
    {
      //don't match parameter
      post_order_destroy(pTree->Left);
      post_order_destroy(pTree->Right);
      my_string_destroy((ITEM)&pTree->key);
      generic_vector_destroy(&pTree->words);
      free(pTree);
    }
  
  // pTree = NULL;
}

//Destroy
//make call to post_order

void tree_destroy(NODE* phTree)
{
  Node* pTree = (Node*) *phTree;
  
  post_order_destroy(pTree);
}

