#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
 };

struct Node *head;
void insert(int value, int pos);
void print();

int main()
{
  head = NULL;
  int n,value,pos;
  printf("Hello! Please enter number of elements \n");
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
     printf("Enter your elements and the position: ");
     scanf("%d %d", &value, &pos);
     insert(value, pos);
    }
   print();
}

void insert(int value, int pos)
{
   struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
   temp1->data = value;
   temp1->next = NULL;
   if(pos==1)
    {
       temp1->next = head;
       head = temp1;
       return;
      }
   struct Node *temp2 = head;
   for(int i=0; i<pos-2; i++)
    {
      temp2 = temp2->next;
      }
    
    temp1->next = temp2->next;
    temp2->next = temp1;
 }
void print()
{
   struct Node *temp = head;
   printf("Yor List is:");
   while(temp->next != NULL)
    {
       printf("%d ", temp->data);
       temp = temp->next;
      }
    printf("%d", temp->data);
    printf("\n");
 }

