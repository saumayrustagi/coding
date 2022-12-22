#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int dt;
	struct node *next;
} node;

void append_to_LL(node *head, int inp) // append at end
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	node *newnode = malloc(sizeof(node));
	newnode->dt = inp;
	newnode->next = NULL;
	head->next = newnode;
}

void insert_after(node *head, int target, int insert) // insert after a given data element
{
	node *newnode = NULL;
	while (head != NULL)
	{
		if (head->dt == target)
		{
			newnode = malloc(sizeof(node));
			newnode->dt = insert;
			newnode->next = head->next;
			head->next = newnode;
			break;
		}
		head = head->next;
	}
	if (newnode == NULL)
	{
		printf("Element not found!\n");
	}
}

node *insert_before(node *head, int target, int insert)
{
	node *hd = head;
	node *newnode = malloc(sizeof(node));
	newnode->dt = insert;
	newnode->next = NULL;
	if (head->dt == target)
	{
		newnode->next = head;
		head = newnode;
		return head;
	}
	else if (head->next != NULL)
	{
		while (head->next->next != NULL)
		{
			if (head->next->dt == target)
			{
				newnode->next = head->next;
				head->next = newnode;
				break;
			}
			head = head->next;
		}
		if (head->next->dt == target)
		{
			newnode->next = head->next;
			head->next = newnode;
		}
	}

	if (head->next != newnode)
	{
		printf("Element not found!\n");
	}
	return hd;
}

node *delete_node(node *head, int del)
{
	node *hd = head;
	if (head->dt == del)
	{
		head = head->next;
		return head;
	}
	else if (head->next != NULL)
	{
		while (head->next->next != NULL)
		{
			if (head->next->dt == del)
			{
				head->next = head->next->next;
				break;
			}
			head = head->next;
		}
		if (head->next->dt == del)
		{
			head->next = head->next->next;
		}
	}
	return hd;
}

void pL(node *head)
{
	while (head != NULL)
	{
		printf("%d", head->dt);
		if (head->next != NULL)
		{
			printf("-->");
		}
		head = head->next;
	}
	printf("\n");
}

int main()
{
	node *head = malloc(sizeof(node));
	head->dt = 1;
	head->next = NULL;

	pL(head);

	insert_after(head, 1, 2);
	insert_after(head, 2, 3);
	insert_after(head, 4, 2); // gives an error
	append_to_LL(head, 4);

	pL(head);

	delete_node(head, 4);

	pL(head);

	delete_node(head, 2);

	pL(head);

	delete_node(head, 1); // won't work without double pointers (pointer to a pointer) when operating on header

	pL(head);
	printf("Didn't work without reassigning the header\n");

	head = delete_node(head, 1); // will work since value of header getting reassigned when operating on header

	pL(head);

	head = insert_before(head, 3, 1); // since we are changing header, need the assignment operator

	pL(head);

	insert_before(head, 3, 2);

	pL(head);

	append_to_LL(head, 4);

	pL(head);

	insert_before(head, 5, 6);
	return 0;
}