#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
 };

struct node *head;
void insert(int x); 
void print();

int main()
{
   head=NULL;
   int n,x;
   printf("Hello! Please enter the size of your list \n");
   scanf("%d", &n);
   for(int i=0; i<n; i++)
   {
      printf("Enter the number: ");
      scanf("%d",&x);
      insert(x);
      print();
     }
 }

void insert(int x)
{
   struct Node *temp =(struct Node*) malloc(sizeof(struct Node));
   temp->data=x;
   temp->next=head;
   head=temp;
 }

void print()
{
   struct Node *temp = head;
   printf("List is:");
   while(temp!=NULL)
     {
       printf(" %d",temp->data);
       temp=temp->next;
      }
   printf("\n");
 }
