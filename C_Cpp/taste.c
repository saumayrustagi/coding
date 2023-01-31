#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} node;

typedef struct list{
	node* head;
} list;

void append_list(list* list, int data){
	node* new = malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	node** p = &list->head;
	while((*p)->next!=NULL)
		p=&((*p)->next);
	
	(*p)->next = new;
}

void delete_node(list* list, int data){
	node** p = &(list->head);
	while((*p)->data!=data){
		p=&(*p)->next;
	}
	(*p) = (*p)->next;
}

void print(list* list){
	node* tmp = list->head;
	while(tmp!=NULL){
		printf("%d ", tmp->data);
		tmp=tmp->next;
	}
}

int main(){
	list* list = malloc(sizeof(list));
	node* node = malloc(sizeof(node));
	node->data=1;
	node->next=NULL;
	list->head=node;
	append_list(list, 2);
	append_list(list, 3);
	print(list);printf("\n");
	delete_node(list, 1);
	print(list);
	return 0;
}
