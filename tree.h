
#ifndef TREE_H
#define TREE_H
#include "my_string.h"

typedef void* NODE; 

NODE tree_init_default(void);

NODE new_Node(MY_STRING key, MY_STRING word);

int height(NODE hTree);

int getBalance(NODE hTree);

NODE rightRotate(NODE y);

NODE leftRotate(NODE x);

NODE tree_insert(NODE hTree, MY_STRING key, MY_STRING word);

void pre_order_print(NODE hTree);

void in_order_print(NODE tree);
//void max_print(NODE max);

NODE max_init_default(void);

//void in_order_trav_max(NODE hTree, NODE max, GENERIC_VECTOR* curr_vector, GENERIC_VECTOR* pMax);

NODE in_order_trav_max(NODE hTree, NODE max);

GENERIC_VECTOR swap_known_generic( NODE max);

MY_STRING swap_known_string(NODE max);

//NODE in_order_trav_max(NODE hTree, NODE max);

//GENERIC_VECTOR* swap_known_type(NODE* pMax);

void swap(GENERIC_VECTOR* curr_vector, GENERIC_VECTOR* pMax);

void key_print(NODE hTree);

//void post_order_destroy(Node* hTree);

void tree_destroy(NODE* phTree);

#endif
