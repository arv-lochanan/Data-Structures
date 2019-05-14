#include<iostream>
#include<queue>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

void LevelOrder(Node *root) 
{
	if(root == NULL)
	{
		return;
	}
	queue<Node*> Q;
	Q.push(root);  
	while(!Q.empty())
	{
		Node* current = Q.front();
		Q.pop();
		cout<<current->data<<" ";
		if(current->left != NULL)
		{
			Q.push(current->left);
		}
		if(current->right != NULL)
		{
			Q.push(current->right);
		}
	}
	cout<<"\n";
}

Node* Insert(Node *root,char data)
{
	if(root == NULL)
	{
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
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

int main() 
{	
	Node* root = NULL;
	int n;
	cout<<"Please enter the number of elements you want to enter in the BST: \n";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int data;
		cout<<"Please Enter the element to be addeed in your BST: ";
		cin>> data;
		root = Insert(root,data);
		cout<<"\n";
	}	
	cout<<"Your Level Order Traversal is: ";
	LevelOrder(root);
}

