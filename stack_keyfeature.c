#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};
typedef struct node node;

node * make_node(int value);
void push(node ** head,int value);
void pop(node ** head);
int size(node ** head);
int top(node ** head);
int is_empty(node ** head);

int main()
{
	node * stack = NULL;
	push(&stack,10);
	push(&stack,20);
	push(&stack,30);
	if (is_empty(&stack))
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	return 0;
}

node * make_node(int value)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}

void push(node ** head,int value)
{
	node * newnode = make_node(value);
	newnode->next = *head;
	*head = newnode;
}

int top(node ** head)
{
	if ((*head) != NULL)
	{
		return (*head)->data;
	}
	return 0;
}

void pop(node ** head)
{
	node * temp = * head;
	(* head)= (* head)->next;
	free(temp);
}

int size(node ** head)
{
	int size = 0;
	node *temp = * head;
	while ( temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

void print_stack(node ** head)
{
	node * temp = * head;
	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

int is_empty(node ** head)
{
	node * temp = * head;
	if (temp == NULL)
	{
		return 1;
	}
	return 0;	
}