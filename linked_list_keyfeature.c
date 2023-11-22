#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};
typedef struct node node;

node * make_node (int value);
void insert_at_begin(node ** head,int value);
void insert_at_end(node ** head,int value);
int size_of_linked_list(node * head);
void insert_after_pos(node ** head,int value,int pos);
void delete_at_begin(node ** head);
void delete_by_value(node ** head,int keyvalue);
void delete_at_end(node ** head);

int main()
{
	node * head = NULL;
	insert_at_begin(&head,10);
	insert_at_begin(&head,20);
	insert_at_begin(&head,30);
	insert_at_begin(&head,40);
	insert_at_begin(&head,50);
	delete_at_end(&head);
	while (head != NULL)
	{
		printf("  %d",head->data);
		head = head->next;
	}
	return 0;
}


node * make_node (int value)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}

void insert_at_begin(node ** head,int value)
{
	node * newnode = make_node(value);
	newnode->next = *head;
	*head = newnode;
}

void insert_at_end(node ** head,int value)
{
	node * newnode = make_node(value);
	node * temp = * head;
	if (*head == NULL)
	{
		*head = newnode;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = NULL;
	return;
}

int size_of_linked_list(node * head)
{
	int cnt = 0;
	while (head != NULL)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insert_after_pos(node ** head,int value,int pos)
{
	int size = size_of_linked_list(*head);
	int i;
	node * temp = * head;
	if (pos < 1 || pos > size + 1)
	{
		return;
	}
	if (pos == 1)
	{
		insert_at_begin(head,value);
		return;
	}
	for (i = 0;i < pos - 1;i++)
	{
		temp = temp->next;
	}
	node * newnode = make_node(value);
	newnode->next = temp->next;
	temp->next = newnode;
	return;
}

void delete_at_begin(node ** head)
{
	node * temp = * head;
	*head = (*head)->next;
	free(temp);
}

void delete_by_value(node ** head,int keyvalue)
{
	node * temp = * head;
	while (temp->next->data != keyvalue)
	{
		temp = temp->next;
	}
	node * delnode = temp->next;
	temp->next = delnode->next;
	free(delnode);
}

void delete_at_end(node ** head)
{
	node * temp = * head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	node * delnode = temp->next;
	temp->next = NULL;
	free(delnode);
}
