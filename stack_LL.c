#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *top = NULL;

void Push(int x)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = x;
	temp -> next = top;
	top = temp;
}

void Pop()	
{
	struct Node *temp= top;
	if(top == NULL)
	{
		printf("Error: No element to pop \n");
		return;
	}
	top = top -> next;
	free(temp);
}

int IsEmpty() 
{
	if(top==NULL)      
		return 1;     
	else
		return 0;
}

void Print()
{
	struct Node *temp = top;
	printf("Stack:");
	while(temp!=NULL)
	{
		printf(" %d",temp->data );
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	Push(2); Print(); 
	Push(4); Print();
	Push(6); Print();
	Push(8); Print();
	Pop(); Print();
	Pop(); Print();
	Push(10); Print();
	Push(12); Print();
	Pop(); Print();
	if(IsEmpty()) 
		printf("Empty!!");
	else
		printf("List has elements \n");
		
	return 0;
}
