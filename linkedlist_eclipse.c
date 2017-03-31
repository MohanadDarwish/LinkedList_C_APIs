/*
 ============================================================================
 Name        : linkedlist_eclipse.c
 Author      : MohanadDarwish
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void)
{
	printf("------------TEST insertion-----------\n");
	insert_node_at_tail("AA");
	insert_node_at_tail("BB");
	insert_node_at_tail("CC");
	insert_node_at_tail("DD");
	print_list();
	/*
	 * The output should be something like this:
	 * <address> : A
	 * <address> : B
	 * <address> : C
	 * <address> : D
	 */

	printf("-------------------------------------\n");
	printf("------------TEST delete list---------\n");
	delete_list();
	print_list();
//
//	  The output should be something like this: (nothing)

	printf("-------------------------------------\n");

	printf("------------TEST delete node---------\n");
	insert_node_at_tail("A");
	insert_node_at_tail("B");
	insert_node_at_tail("C");
	insert_node_at_tail("D");
	delete_node(0);
	delete_node(1);
	print_list();
//
//	 The output should be something like this:
//	  <address> : B
//	  <address> : D
//
	printf("-------------------------------------\n");
	printf("------------TEST swap nodes---------\n");
		insert_node_at_tail("E");
		insert_node_at_tail("F");
		insert_node_at_tail("G");
		insert_node_at_tail("H");
		swap_nodes(2,4);
		print_list();
//
//		  The output should be something like this:
//		  <address> : B
//		  <address> : D
//		  <address> : G
//		  <address> : F
//		  <address> : E
//		  <address> : H
//

		printf("-------------------------------------\n");

return 0;
}
