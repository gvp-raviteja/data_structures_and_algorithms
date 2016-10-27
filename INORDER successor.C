#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *right,*left;
};
void insert(struct node **p,int data)
{
struct node *pi;

if(*p==NULL)
{
pi=(struct node*)malloc(sizeof(struct node));
pi->right=NULL;
pi->left=NULL;
pi->data=data;
*p=pi;

return;
}
else
{
pi=*p;
 if((pi->data>data))
 insert(&(pi->left),data);
else
 insert(&(pi->right),data);
}
}
void inorder(struct node *p)
{
if(p!=NULL)
{
inorder(p->left);
printf("\n %d",p->data);
inorder(p->right);
}
else
return;
}
void inordersucc(struct node *root,struct node **head,int data)
{
if(root->data==data)
{
 if(root->right!=NULL)
   {
    (*head)=root->right;
       while((*head)->left!=NULL)
	   *head=(*head)->left;
    }
 }
else if(root->data>data)
 {
  (*head)=root;
  inordersucc(root->left,head,data);
 }
else
 inordersucc(root->right,head,data);
}
void main()
{
struct node *root,*head;
root=NULL;
head=NULL;
insert(&root,10);
insert(&root,7);
insert(&root,9);
insert(&root,5);
insert(&root,30);
insert(&root,20);
inorder(root);
inordersucc(root,&head,10);
printf("\n %d" , head->data);
}