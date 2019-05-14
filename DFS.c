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
void PreOrder(struct Node *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(struct Node *root)
{
	if(root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%d", root->data);
	InOrder(root->right);
}
void PostOrder(struct Node *root)
{
	if(root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d", root->data);
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
	int k;
	printf("Please enter the kind traversal you want: \n");
	printf("1.Pre-order \n");
	printf("2.Inorder \n");
	printf("3.Post-order \n");
	scanf("%d", &k);
	switch (k)
	{
		case 1: PreOrder(root);
				break;
		case 2: InOrder(root);
				break;
		case 3: PostOrder(root);
				break;
		default:printf("Oops! worng option");
				break;
	}
}	

