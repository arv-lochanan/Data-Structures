#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node 
{
	int data; 
	struct Node* left;
	struct Node* right;
};

struct Node* GetNewNode(int data) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* Insert(struct Node* root,int data) 
{
	if(root == NULL)
	{ 
		root = GetNewNode(data);
	}
	 
	else if(data <= root->data) 
	{
		root->left = Insert(root->left,data);
	}
	 
	else 
	{
		root->right = Insert(root->right,data);
	}
	return root;
}

bool Search(struct Node* root,int data) 
{
	if(root == NULL) 
	{
		return false;
	}
	else if(root->data == data) 
	{
		return true;
	}
	else if(data <= root->data) 
	{
		return Search(root->left,data);
	}
	else 
	{
		return Search(root->right,data);
	}
}
int main() 
{
	struct Node* root = NULL;
	int n;
	printf("Please enter the number of elements you want to enter in the BST: \n");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int data;
		printf("Please Enter the element to be addeed in your BST: ");
		scanf("%d",&data);
		root = Insert(root,data);
		printf("\n");
	}	
		/*root = Insert(root,10);	
		root = Insert(root,20);
		root = Insert(root,25);
		root = Insert(root,8);
		root = Insert(root,12);*/
	int number;
	printf("Enter number be searched\n");
	scanf("%d", &number);
	if(Search(root,number) == true)
	{
		printf("Found\n");
	}
	else
	{
		 printf("Not Found\n");
	}
}
