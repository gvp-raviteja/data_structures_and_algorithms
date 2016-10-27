#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right,*parent;
};
int depth(struct node *root,struct node *p)
{
	int d=0;
	while(root!=p)
	{
		p=p->parent;
		d++;
	}
	return d;
}
struct node* leastparent(struct node *root,struct node *p,struct node *q)
{
	int depth1,depth2;
	depth1=depth(root,p);
	depth2=depth(root,q);
	if(depth1>depth2)
	{
		while(depth1!=depth2)
		{
			p=p->parent;
			depth1--;
		}
	}
	if(depth1<depth2)
	{
		while(depth1!=depth2)
		{
			q=q->parent;
			depth2--;
		}
	}
	while(p!=q)
	{
		p=p->parent;
		q=q->parent;
	}
	return p;
}

void preorder(struct node *root,int i,int j,int h,char **a,int **e)
{
	int k,c,d,l;
	c=i;d=j;
	if(root!=NULL && h!=0)
	{
		a[i][j]=e[i][j]=root->data;
		k=h-1;
		if(k!=0)
		k=((k-1)*(k-1)) +1;
		l=k;
		if(root->left!=NULL)
		{
			for(;k>0;k--)
			{
				i--;j--;
				a[i][j]='/';
			}
			i--;j--;
		}
		if(root->right!=NULL)
		{
			for(;l>0;l--)
			{
				c--;d++;
				a[c][d]='\\';
			}
			c--;d++;	
		}
		if(root->left!=NULL)
			preorder(root->left,i,j,h-1,a,e);
		if(root->right!=NULL)
			preorder(root->right,c,d,h-1,a,e);
	}
}
void print(struct node *root,int h)
{
	int **c,i=0,j=0;
	char **a;
	a=(char **)malloc(12*sizeof(char *));
	for(i=0;i<12;i++)
		a[i]=(char *)malloc(23*sizeof(char));
	for(i=0;i<12;i++)
		for(j=0;j<23;j++)
			a[i][j]=' ';
	c=(int **)malloc(12*sizeof(int *));
	for(i=0;i<12;i++)
		c[i]=(int *)malloc(23*sizeof(int));
	for(i=0;i<12;i++)
		for(j=0;j<23;j++)
			c[i][j]=0;
	preorder(root,11,11,h,a,c);
	for(i=11;i>=0;i--)
	{
		for(j=0;j<23;j++)
		{
			if(a[i][j]==c[i][j])
				printf("%d ",c[i][j]);
			else
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
}
int height(struct node *root,int h)
{
	int h1,h2;
	if(root!=NULL)
	{
		h1=height(root->left,h+1);
		h2=height(root->right,h+1);
		if(h1>h2)return h1;
		else return h2;
	}
	else
		return h;
}
void main()
{
	int h=0;
	struct node *parent1,*root,*temp,*temp1,*temp2,*temp3,*temp4,*temp5;
	root=(struct node*)malloc(sizeof(struct node));
	temp=(struct node*)malloc(sizeof(struct node));
	temp1=(struct node*)malloc(sizeof(struct node));
	temp2=(struct node*)malloc(sizeof(struct node));
	temp3=(struct node*)malloc(sizeof(struct node));
	temp4=(struct node*)malloc(sizeof(struct node));
	temp5=(struct node*)malloc(sizeof(struct node));
	root->data=18;
	root->parent=NULL;
	temp->data=4;
	root->left=temp;
	temp->parent=root;
	temp1->data=5;
	temp1->parent=root;
	root->right=temp1;
	temp2->data=2;
	temp2->parent=temp;
	temp->right=temp2;
	temp->left=NULL;
	temp2->right=NULL;
	temp3->data=7;
	temp3->parent=temp2;
	temp2->left=temp3;
	temp3->left=NULL;
	temp3->right=NULL;
	temp4->data=9;
	temp1->left=temp4;
	temp5->data=3;
	temp1->right=temp5;
	temp4->left=NULL;
	temp4->right=NULL;
	temp5->left=NULL;
	temp5->right=NULL;
	temp4->parent=temp1;
	temp5->parent=temp1;
	h=height(root,h);
	print(root,h);
	parent1=leastparent(root,temp,temp2);
	printf("common parent of %d and %d is %d",temp->data,temp2->data,parent1->data);
}