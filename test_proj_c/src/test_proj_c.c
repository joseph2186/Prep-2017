/*
 ============================================================================
 Name        : test_proj_c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int bit_set(int n)
{
	int count = 0;
	while(n)
	{
		n &= (n-1);
		count++;
	}
	return count;
}

struct node{
	struct node *next;
	int value;
};

typedef struct node node_s;

void display(node_s *head)
{
	node_s *temp;

	if(head->next == NULL)
	{
		printf("list is empty\n");
		return;
	}

	temp = head->next;
	while(temp->next != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	printf("%d\n", temp->value);
}

void insert_rear(node_s *head, int value)
{
	node_s *temp = head;

	node_s *node = (struct node *)malloc(sizeof(struct node));
	node->value = value;
	node->next = NULL;

	/* if list is empty, set new node as head */
	if (head == NULL)
	{
		head = node;
		return;
	}

	/* if there is only one element in the list */
	if (head->next == NULL)
	{
		head->next = node;
		return;
	}

	/* traverse till the end of the list, insert after the last element */
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
}

void insert_front(node_s *head, int value)
{
	node_s *node = (struct node *)malloc(sizeof(struct node));
	node->value = value;
	node->next = NULL;

	/*if the list is empty, set new node as head */
	if (head->next == NULL)
	{
		head->next = node;
		return;
	}

	/* set the new node to point to head and reset head */
    node->next = head->next;
	head->next = node;
}

void delete_node(node_s *head, int value)
{
	node_s *temp = head;
	node_s *prev;

	/* no elements in the list - return */
	if (head == NULL)
	{
		printf("linked list is empty\n");
		return;
	}

	/* value to be deleted in the head - move head and delete first element */
	if (head->value == value)
	{
		head = head->next;
		free(temp);
	}

	/* only one element in the list - check if that is the element */
	if (temp->next == NULL)
	{
		if(temp->value == value)
		{
			free(temp);
			head = NULL;
		}
		else
		{
			printf("element with value %d is not present\n", value);
		}
		return;
	}

	/* all other elements */
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
		if (temp->value == value)
		{
			prev->next = temp->next;
			free(temp);
			return;
		}
	}

	printf("element with value %d is not present\n", value);
}

int main(void)
{
	int input;
	int value;
	while(1)
	{
	  printf("1. bit set\n2. linked list\n3. Exit\n");
	  scanf("%d", &input);

	  switch(input)
	  {
	  case 1:
		  printf("enter the number to set bit set:");
		  scanf("%d", &input);

		  value = bit_set(input);
		  printf("bits set = %d\n", value);

		  break;
	  case 2:
	  printf ("***LINKED LIST CODE***\n");

	  node_s *head = (struct node*)malloc(sizeof(struct node));
	  head->next = NULL;

	  while(1)
	  {
		  printf("what do you want to do??\n");
		  printf("1. Insert rear\n2. Insert front\n3. Delete element\n4. Display list\n5. Exit\n");

		  printf("choice: ");
		  scanf("%d", &input);

		  switch(input)
		  {
		  case 1:
			  printf("value to be entered: ");
			  scanf("%d", &value);

			  insert_rear(head, value);
			  break;
		  case 2:
			  printf("value to be entered: ");
			  scanf("%d", &value);

			  insert_front(head, value);
			  break;
		  case 3:
			  printf("value to be deleted: ");
			  scanf("%d", &value);

			  delete_node(head, value);
			  break;
		  case 4:
			  printf("linked list created so far..\n");

			  display(head);
			  break;
		  case 5:
			  exit(0);
		  default:
			  printf("invalid entry, please try again\n");
			  break;
		  }
	  }
	  break;
	  case 3:
		  exit(0);
		  break;
	  }

	}
	return EXIT_SUCCESS;
}
