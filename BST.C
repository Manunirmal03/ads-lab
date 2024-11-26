#include <stdio.h>
#include <alloc.h>
#include <conio.h>

struct TreeNode
{
   struct TreeNode *lchild;
   struct TreeNode *rchild;
   int data;
};
typedef struct TreeNode TreeNode;
TreeNode *getnode()
{
   TreeNode *t;
   t=(TreeNode *)malloc(sizeof(TreeNode));
   return t;
}

TreeInsert(TreeNode **rt,int item)
{
    TreeNode *current=(*rt),*temp;
    if(*rt==NULL)
    {
       (*rt)=getnode();
       (*rt)->data=item;
       (*rt)->lchild=NULL;
       (*rt)->rchild=NULL;
       return;
    }
    while(current!=NULL)
    {
       if(item<current->data)
       {
	  if(current->lchild!=NULL)
	      current=current->lchild;
	  else
	  {
	      temp=getnode();
	      current->lchild=temp;
	      temp->data=item;
	      temp->lchild=NULL;
	      temp->rchild=NULL;
	      return;
	  }
       }
       else
       {
	  if(item>current->data)
	  {
	     if(current->rchild!=NULL)
		 current=current->rchild;
	     else
	     {
		temp=getnode();
		current->rchild=temp;
		temp->data=item;
		temp->rchild=NULL;
		temp->lchild=NULL;
		return;
	     }
	  }
	  else
	  {
	      printf("wrong data!");
	      exit(0);
	  }
       }
    }
}

Inorder(TreeNode (*rt))
{
   if(rt!=NULL)
   {
     Inorder(rt->lchild);
     printf("%4d",rt->data);
     Inorder(rt->rchild);
   }
   else
     return;
}

Preorder(TreeNode (*rt))
{
   if(rt!=NULL)
   {
      printf("%4d",rt->data);
      Preorder(rt->lchild);
      Preorder(rt->rchild);
   }
   else
      return;
}

Postorder(TreeNode (*rt))
{
   if(rt!=NULL)
   {
      Postorder(rt->lchild);
      Postorder(rt->rchild);
      printf("%4d",rt->data);
   }
   else
      return;
}

TreeDisplay(TreeNode *rt,int level)
{
   int i;
   if(rt!=NULL)
   {
      TreeDisplay(rt->rchild,level+1);
      printf("\n");
      for(i=0;i<level;i++)
      printf("  ");

      printf("%d",rt->data);
      TreeDisplay(rt->lchild,level+1);
   }
}

TreeDelete(TreeNode **rt,int item)
{
   TreeNode *current;
   if(*rt==NULL)
   {
     printf("ERROR");
     getch();
     return;
   }
   if(item< (*rt)->data)
      TreeDelete(&((*rt)->lchild),item);
   else
   {
      if(item>(*rt)->data)
	 TreeDelete((&(*rt)->rchild),item);
      else
      {
	 current=*rt;
	 if(current->rchild==NULL)
	 {
	    (*rt)=(*rt)->lchild;
	    free(current);
	 }
	 else
	 {
	    if(current->lchild==NULL)
	    {
	      (*rt)=(*rt)->rchild;
	      free(current);
	    }
	    else
	    {
	       current=(*rt)->rchild;
	       while(current->lchild!=NULL)
		{
		   current=current->lchild;
		   current->lchild=(*rt)->lchild;
		   current=(*rt);
		   (*rt)=(*rt)->rchild;
		   free(current);
		}
	    }

	 }
      }
   }
}

int main()
{
   int a[100],i,n,item;
   TreeNode *root=NULL;
   clrscr();

   printf("\n Enter number of elements in data list:");
   scanf("%d",&n);
   printf("Enter element:");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	    for(i=0;i<n;i++)
		TreeInsert(&root,a[i]);
printf("\nBinary Search Tree:\n");
TreeDisplay(root,1);
printf("\nInorder traversal:\n");
Inorder(root);
printf("\nPreorder Traversal:\n");
Preorder(root);
printf("\nPostorder Traversal:\n");
Postorder(root);
printf("\nEnter element to delete:\n");
scanf("%d",&item);
TreeDelete(&root,item);
printf("\n Binary tree after deletion:\n");
TreeDisplay(root,1);
getch();
}