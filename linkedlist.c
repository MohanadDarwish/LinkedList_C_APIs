/*
 * linkedlist.c
 *
 *  Created on: Mar 29, 2017
 *      Author: mohanad1
 */
#include "linkedlist.h"
node_type* head= NULL;

void  insert_node_at_tail(const char* str)
{
	//TODO Implement here insertion of a new node_type at the list's tail
	node_type* current_node = head;
	node_type* new_node = (node_type*)malloc(sizeof(node_type));
	new_node->txt= str;
    new_node->next = NULL;
	if(head==NULL)
	{
		head = new_node;
	}
	else if(current_node->next == NULL)
    {
        current_node->next = new_node;
    }
	else
	{
		while(current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}

}

void print_list()
{
	//TODO Implement here function print the list (address of the node_type need to be visible)
	node_type* current_node = head;
	if(current_node == NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		while(current_node != NULL)
		{
			printf("< 0x%p > : %s \n",current_node, current_node->txt);
			current_node = current_node->next;
		}
	}

}
/////////////////////////////////////
void delete_node(int index)
{
	//TODO Implement here function delete node at the given index (calculated from the head) 0 base
	node_type* current_node = head;
	node_type* temp = current_node;
	char curr_index = 0;
	if(index==0)
	{
		if(head->next == NULL)//list contains only one node
		{
			temp = head;
			head = NULL;
			free(temp);
		}
		else//list contains more than one node
		{
			current_node = head->next;
			temp = head;
			head=current_node;
			free(temp);

		}
	}
	else if(index>0)//list contains more than one node and desired node to be deleted is not 0(first node)
	{
		while( (curr_index != index) && (current_node->next!=NULL) )
			{
				temp=current_node;
				current_node = current_node->next;
				curr_index++;
			}
			temp->next=current_node->next;
			free(current_node);
	}
}

void delete_list()
{
	//TODO Implement here function delete the whole list (destroy nodes)
	node_type* current_node = head;
	node_type* temp = current_node;
	char del_num = 0;
	while(current_node->next != NULL)
	    {
			temp = current_node;
			current_node = current_node->next;
			free(temp);
			del_num++;
	    }
	free(current_node);
	del_num++;
	head = NULL;
	printf("Number of deleted nodes:= %d\n",del_num);
}

void swap_nodes(int indexA,int indexB)
{
	//TODO Implement here function swaps two nodes at indices indexA indexB (from head 0 based) (where A<B )
	node_type* current_node=head;
	node_type* prev_swap1_node;
	node_type* prev_swap2_node;
	node_type* after_swap2_node = NULL; //in case swap2 node was the last node in list
	node_type* temp;
	char curr_index = 0;
	int buf = 0;
	if(indexA > indexB)
	{
		int buf = indexA;
		indexA = indexB;
		indexB = buf;
	}
	while( (current_node != NULL) && (indexA != indexB) )
	{
		if(indexA == 0)//handling case having swap1 node as head node
		{
			prev_swap1_node= head;
		}
		if(curr_index == (indexA-1) )//swap1 node
		{
			prev_swap1_node = current_node;
		}
		else if(curr_index == (indexB-1) )//swap2 node
		{
			prev_swap2_node = current_node;

		}
		else if(curr_index == (indexB+1) )
		{
			after_swap2_node = current_node;
		}
		current_node= current_node->next;
		curr_index++;
	}
	if(indexA == 0)
	{
		if(indexB == 1)//handling case having swap2 node as FIRST NODE after head node
		{
			temp=head;
					head = head->next;
					head->next = temp;
					head->next->next = after_swap2_node;

		}
		else
		{
			temp = prev_swap2_node->next;				//temp -> swap2 node
			temp->next = prev_swap1_node->next;			//F->D
			prev_swap2_node->next = head;				//
			prev_swap1_node->next = after_swap2_node;	//B->G
			head = temp;								//Head->F
		}

	}
	else
	{
		temp = prev_swap1_node->next; // temp --> swap1
		prev_swap1_node->next = prev_swap2_node->next; // prev1 --> swap2
		prev_swap2_node->next = temp;	//
		prev_swap1_node->next->next = temp->next;
		temp->next = after_swap2_node;
	}
}
