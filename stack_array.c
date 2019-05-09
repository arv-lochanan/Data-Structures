#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int x)
{
	if(top == MAX_SIZE-1)
	{
		printf("Error: Stack Overflow \n");
		return;
	}
	A[++top] = x;
}

void pop()
{
	if(top == -1)
	{
		printf("Error: No element to pop \n");
		return;
	}
	top--;
}


void Print()
{
	printf("Stack:");
	for(int i = 0; i<= top; i++)
	{
		printf("%d", A[i]);
	}
	printf("\n");
}
 int main()
 {
 	push(2); Print();
 	push(4); Print();
 	push(6); Print();
 	pop(); Print();
 	push(8); Print();
 	push(12); Print();
 }
