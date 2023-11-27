#include<stdio.h>
#include<stdlib.h>
	
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

Node * create_node(int data)
{
	Node * newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
}

void insert_node(Node** head, int data)
{
    Node* newNode = create_node(data);
    if (*head == NULL)
	{
        *head = newNode;
    }
	else
	{
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* reverse(Node* head, Node* prev)
{
	Node* temp;
	Node* curr;
	curr = head;
	while (curr != NULL && curr->data % 2 == 0) 
	{
		temp = curr->next; //store next
		curr->next = prev; // swap
		prev = curr; 
		curr = temp;
	}	
	if (curr != head)
	{
		head->next = curr;
		curr = reverse(curr, NULL);
		return prev;
	}
	else
	{	
		head->next = reverse(head->next, head);
		return head;
	}
}

void traverse_linked_list(Node ** head)
{
	Node* temp = *head;
    while (temp != NULL)
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
	
int main()
{
	int n;
	int data;
	int i;
	scanf("%d",&n);
	Node *head = NULL;
	for (i = 0;i < n;i++)
	{
		scanf("%d",&data);
		insert_node(&head,data);
	}
	head = reverse(head,NULL);
	traverse_linked_list(&head);
	return 0;
}
