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

struct Node* FindMin(struct Node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

struct Node* Delete(struct Node *root, int data) 
{
	if(root == NULL)
	{
		return root;
	} 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else 
	{
		if(root->left == NULL && root->right == NULL) 
		{ 
			 free(root);
			root = NULL;
		}
		else if(root->left == NULL) 
		{
			struct Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) 
		{
			struct Node *temp = root;
			root = root->left;
			free(temp);
		}
		else 
		{ 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
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
	int k;
	printf("Enter the number you want to delete: ");
	scanf("%d", &k);
	printf("\n");
	root = Delete(root,k);	
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
