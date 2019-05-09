#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;

struct Node* GetNewNode(int x)
{
	struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void InsertAtHead(int x)
{
	struct Node* newNode = GetNewNode(x);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	head -> prev = newNode;
	newNode -> next = head;
	head = newNode;
}
void print()
{
	struct Node* temp = head;
	printf("Forward: ");
	while(temp!=NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void ReversePrint()
{
	struct Node* temp = head;
	if(temp == NULL)
	{
		return;
	}
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	printf("Reverse: ");
	while(temp!=NULL)
	{
		printf("%d", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
int main()
{
	head = NULL;
	InsertAtHead(1); print(); ReversePrint();
	InsertAtHead(2); print(); ReversePrint();
	InsertAtHead(3); print(); ReversePrint();
	InsertAtHead(4); print(); ReversePrint();
}

	
	
	
