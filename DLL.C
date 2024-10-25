#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
 int data;
 struct Node* prev;
 struct Node* next;
};
struct Node* createNode(int data)
{
 struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->data=data;
 newNode->prev=NULL;
 newNode->next=NULL;
 return newNode;
}
void insertEnd(struct Node** head,int data)
{
 struct Node* temp=*head;
 struct Node* newNode=createNode(data);
 if(*head==NULL)
 {
  *head=newNode;
  return;
 }

 while(temp->next!=NULL)
 {
  temp=temp->next;
 }
 temp->next=newNode;
 newNode->prev=temp;
}
void deleteNode(struct Node** head,int data)
{
 struct Node* temp=*head;
 while(temp!=NULL)
 {
  if(temp->data==data)
  {
   if(temp->prev!=NULL)
   {
    temp->prev->next=temp->next;
   }
   else
   {
    *head=temp->next;
   }
   if(temp->next!=NULL)
   {
    temp->next->prev=temp->prev;
   }
   free(temp);
   printf("Node with data %d deleted.\n",data);
   return;
  }
  temp=temp->next;
 }
 printf("Node with data %d not found.\n",data);
}
void searchNode(struct Node* head,int data)
{
 struct Node* temp=head;
 while(temp!=NULL)
 {
  if(temp->data==data)
  {
   printf("Node with data %d found.\n",data);
   return;
  }
  temp=temp->next;
 }
 printf("Node with data %d not found.\n",data);
}
void displayList(struct Node* head)
{
 struct Node* temp=head;
 if(temp==NULL)
 {
  printf("List is empty.\n");
  return;
 }
 printf("Doubly Linked List:");
 while(temp!=NULL)
 {
  printf("%d",temp->data);
  temp=temp->next;
 }
 printf("\n");
}
int main()
{
 struct Node* head=NULL;
 int ch,data;
 clrscr();
 while(1)
 {
  printf("\nMenu: \n1.Insert node at End\n2.Delete data\n3.search Node\n4.Display List\n5.exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    printf("Enter data to insert:");
    scanf("%d",&data);
    insertEnd(&head,data);
    break;
   case 2:
    printf("Enter data to delete:");
    scanf("%d",&data);
    deleteNode(&head,data);
    break;
   case 3:
    printf("Enter data to search:");
    scanf("%d",&data);
    searchNode(head,data);
    break;
   case 4:
    displayList(head);
    break;
   case 5:
    printf("Existing..\n");
    exit(0);
   default:
    printf("Invalid choice. please try again.\n");
  }
 }
 getch();
 return 0;
}



