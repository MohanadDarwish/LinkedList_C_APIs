/*
 * linkedlist.h
 *
 *  Created on: Mar 29, 2017
 *      Author: mohanad1
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	//TODO Implement here what a linked list node should contain
	char* txt;
	struct node* next;
}node_type;
node_type* head ; // this is pointer to the first node in the list (when empty it points to null)

void  insert_node_at_tail(const char* str);

void print_list();

void delete_node(int index);

void delete_list();

void swap_nodes(int indA,int indB);

#endif /* LINKEDLIST_H_ */
