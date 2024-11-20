#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct treenode
{
 struct treenode *lchild;
 int data;
 struct treenode *rchild;
};
typedef struct treenode treenode;
void treecreate(treenode **rt, int item);
void treedisplay(treenode *rt, int level);
treenode *getnode();
int main()
{
 treenode *root=NULL;
 treecreate(&root,6);
 treecreate(&root,4);
 treecreate(&root,8);
 treecreate(&root,3);
 treecreate(&root,7);
 treecreate(&root,5);
 treecreate(&root,9);
 treecreate(&root,11);
 treecreate(&root,10);
 clrscr();
 treedisplay(root,1);
 getch();
 return 0;
}
void treecreate(treenode **rt,int item)
{
 treenode *current=(*rt),*temp;
 if((*rt)==NULL)
 {
  (*rt)=getnode();
  (*rt)->data=item;
  (*rt)->lchild=NULL;
  (*rt)->rchild=NULL;
   return;
 }
 while(1)
 {
  if(item<current->data)
  {
   if(current->lchild != NULL)
   {
     current=current->lchild;
   }
   else
   {
    temp=getnode();
    current->lchild=temp;
    temp->data=item;
    temp->rchild=NULL;
    temp->lchild=NULL;
    return;
   }
  }
  else if(item > current->data)
   {
    if(current->rchild != NULL)
    {
     current=current->rchild;
    }
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
 }
}
void treedisplay(treenode *rt,int level)
{
 int i;
 if((rt)!=NULL)
 {
  treedisplay((rt)->rchild,level+1);
  printf("\n");
  for(i=0;i<level;i++)
   printf(" ");
  printf("%d",(rt)->data);
  treedisplay((rt)->lchild,level+1);
 }
}
treenode *getnode()
{
 treenode *t=(treenode *)malloc(sizeof(treenode));
 if (t == NULL) {
       fprintf(stderr, "Memory allocation failed\n");
       exit(1); // Exit if memory allocation fails
 }
 return t;
}