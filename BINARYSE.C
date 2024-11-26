#include<stdio.h>
#include<conio.h>
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
void display(struct Node *root,int space)
{
 int i;
 if(root==NULL)
 return;
 space+=10;
 display(root->right,space);
 printf("\n");
 for(i=10;i<space;i++)
 printf(" ");
 printf("%d\n",root->key);
 display(root->left,space);
 }
int main()
 {
   struct Node*root=NULL;
   int choice,key;
   clrscr();
   while(1)
    {
      printf("\nMENU\n");
      printf("1.Insert\n");
      printf("2.Search\n");
      printf("3.Delete\n");
      printf("4.Inorder traversal \n");
      printf("5.Exit\n");
      printf("6.Display\n");
      printf("\n Enter your choice:\n");
      scanf("%d",&choice);
      switch(choice)
	 {
	   case 1: printf("enter value to insert:");
		   scanf("%d",&key);
		   root=insert(root,key);
		   printf("%d inserted\n",key);
		   break;

	   case 2: printf("Enter value to search\n");
		   scanf("%d",&key);
		   if(search(root,key)!=NULL)
		     {
			printf("%d found\n",key);
		     }
		   else
		     {
			printf("%d not found.\n");
		     }
		   break;

	    case 3: printf("Enter value to delete\n");
		    scanf("%d",&key);
		    root=delete(root,key);
		    printf("%d deleted.\n",key);
		    break;

	    case 4: printf("Inorder Traversal\n");
		    inorder(root);
		    printf("\n");
		    break;

	    case 5: printf("Exiting..\n");
		    exit(0);

	    case 6: printf("display tree:\n");
		    display(root,0);
		    break;

	   default: printf("Invalid choice\n");

	 }
    }
}