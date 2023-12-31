#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int popularity;
    struct Node* next;
};
typedef struct Node Node;

Node* create_node(int popularity)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->popularity = popularity;
    newNode->next = NULL;
    return newNode;
}

void delete_friends(struct Node** head, int k) {
    Node* current = *head;
    Node* previous = NULL;
    int deleted = 0;
    while (k > 0)
    {
    	current = *head;
    	previous = NULL;
    	while (current && current->next && k > 0)
		{
	        if (current->popularity < current->next->popularity) {
	            if (previous == NULL) {
	                *head = current->next;
	            } else {
	                previous->next = current->next;
	            }
	            Node* temp = current;
	            current = current->next;
	            free(temp);
	            deleted++;
	            k--;
	        } else {
	            previous = current;
	            current = current->next;
	        }
    	}
	}
	/*if (k > 0) {
        Node* tail = previous;
        while (tail && tail->next) {
            tail = tail->next;
        }
        while (tail && k > 0) {
            Node* temp = tail;
            tail = tail->next;
            free(temp);
            deleted++;
            k--;
        }
        if (previous != NULL) {
            previous->next = NULL;
        } else {
            *head = NULL;
        }
    }*/
}

void insert_node(Node** head, int popularity)
{
    Node* newNode = create_node(popularity);
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

void traverse_linked_list(Node ** head)
{
    Node* temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->popularity);
        temp = temp->next;
    }
    printf("\n");
}
void free_linked_list(struct Node** head)
{
    Node* temp = *head;
    while (temp != NULL)
    {
        Node* current = temp;
        temp = temp->next;
        free(current);
    }
    *head = NULL;
}

int main()
{
    int t;
    scanf("%d", &t);
    int i;
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        struct Node* head = NULL;
        for (i = 0; i < n; i++)
	{
            int popularity;
            scanf("%d", &popularity);
            insert_node(&head, popularity);
        }
        delete_friends(&head, k);
        traverse_linked_list(&head);
        free_linked_list(&head);
    }
    return 0;
}
