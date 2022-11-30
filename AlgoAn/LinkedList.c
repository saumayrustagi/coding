#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} node;

void appendToList(node *list, int num);
void printList(node *list);
void freeList(node *list);

int main()
{
	node *list = NULL;

	node *n = malloc(sizeof(node));

	if (n == NULL)
	{
		return 1;
	}

	n->data = 1;
	n->next = NULL;

	list = n;

	for (int i = 2; i <= 10; i++)
	{
		appendToList(list, i);
	}

	printList(list);

	freeList(list);

	return 0;
}

void appendToList(node *list, int num)
{

	/*
	 *
	 * TAKES A LIST (list) AND APPENDS AN INTEGER (num) TO ITS END
	 *
	 */

	// NAVIGATE TO LAST NEXT
	node *temp = list;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	// CREATE NEW NODE
	node *tmp = malloc(sizeof(node));
	tmp->data = num;
	tmp->next = NULL;

	// PUT NEXT = NEW NODE
	temp->next = tmp;
}
void printList(node *list)
{

	/*
	 * PRINTS A LIST
	 */

	node *tmp = list;
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}
void freeList(node *list)
{

	/*
	 * FREES A LIST
	 *
	 */

	while (list != NULL)
	{
		node *temp = list;
		list = list->next;
		free(temp);
	}
}
