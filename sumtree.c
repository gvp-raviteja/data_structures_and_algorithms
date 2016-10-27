#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
char data;
struct node *left,*right;
};
struct node* create(int n)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=temp->right=NULL;
    return temp;
}
struct node * insert(int n,struct node *temp)//pass head to it
{ 
	int d;
	if(temp==NULL)
		return create(n);
	printf("left-0 right-1 ");
	scanf("%d",&d);
    if(d==0)
        temp->left=insert(n,temp->left);
    else
        temp->right=insert(n,temp->right);
    return temp;
}
void inorder(struct node *head)
{
	if(head!=NULL)
	{
	inorder(head->left);
	printf("\n %d",head->data);
	inorder(head->right);	
	}
}
int sumtree(struct node *p,int x,int y)
{
	if(p!=NULL)
	{
		x=sumtree(p->left,x,y);
		y=sumtree(p->right,x,y);
		if((p->left==NULL)&&(p->right==NULL))
			return p->data;
		else
		{
			if(p->data==(x+y))
				return 2*p->data;
			else
			{
				printf("not a sumtree");
				exit(0);
			}
		}
	}
	else
	return 0;
}
void main()
{
	struct node *q;
	int n;char ch;
	q=NULL;
	while(1)
	{
		printf("enter the node value");
		scanf("%d",&n);
		q=insert(n,q);
		printf("more values");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='n')
			break;
	}
	inorder(q);
	sumtree(q,0,0);
	printf("\n given tree is sumtree ");
}
