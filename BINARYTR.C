#include<stdio.h>
#include<stdlib.h>
struct Node
{
 int key;
 struct Node*left;
 struct Node*right;
};
struct Node*createNode(int key)
{
 struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->key=key;
 newNode->left=newNode->right=NULL;
 return newNode;
}
struct Node*insert(struct Node*root,int key)
{
if(root==NULL)
{
return createNode(key);
}
if(key<root->key)
{
root->left=insert(root->left,key);
}
else
{
root->right=insert(root->right,key);
}
return root;
}
struct Node*search(struct Node*root,int key)
{
if(root==NULL||root->key==key)
{
return root;
}
if(key<root->key)
{
return search(root->left,key);
}
return search(root->right,key);
}
struct Node*minvalueNode(struct Node*node)
{
struct Node*current=node;
while(current&&current->left!=NULL)
{
current=current->left;
}
return current;
}
struct Node*delete(struct Node*root,int key)
{
struct Node*temp=minvalueNode(root->right);
if(root==NULL)
{
return root;
}
if(key<root->key)
{
root->left=delete(root->left,key);
}
else if(key>root->key)
{
root->right=delete(root->right,key);
}
else
{
if(root->left==NULL)
{
struct Node*temp=root->right;
free(root);
return temp;
}
else if(root->right==NULL)
{
struct Node*temp=root->left;
free(root);
return temp;
}

root->key=temp->key;
root->right=delete(root->right,temp->key);
}
return root;
}
void inorder(struct Node*root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d",root->key);
inorder(root->right);
}
}
int main()
{
 struct Node*root=NULL;
 int choice,key;
 clrscr();
 while(1)
 {
   printf("\nMenu:\n");
   printf("1.Insert\n");
   printf("2.Search\n");
   printf("3.Delete\n");
   printf("4.Inorder traversal\n");
   printf("5.Exit\n");
   printf("Enter your choice:");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
    printf("enter value to insert:");
    scanf("%d",&key);
    root=insert(root,key);
    printf("%d inserted .\n",key);
    break;
   case 2:
     printf("Enter value to search:");
     scanf("%d",&key);
     if(search(root,key)!=NULL)
     {
     printf("%d found.\n",key);
     }
     else
     {
     printf("%d not found.\n",key);
     }
     break;
   case 3:
     printf("Enter value to delete:");
     scanf("%d",&key);
     root=delete(root,key);
     printf("%d deleted.\n",key);
     break;
   case 4:
     printf("inorder traversal:");
     inorder(root);
     printf("\n");
     break;
   case 5:
     printf("exciting....\n");
     exit(0);
     default:
     printf("invalid choice please try again.\n");
     }
}
}