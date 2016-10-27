#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node * insert(struct node *root,int i)
{

	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->data=i;
		root->left=root->right=NULL;
		return root;
	}
	else
	{
		if(root->data >i)
			root->left=insert(root->left,i);
		else
			root->right=insert(root->right,i);
		return root;
	}
}
// this function checks whether the given binary tree is binary search tree or not
int bstcheck(struct node * root,int *temp)
{
	int i=0;
	if(root)
	{
		i=bstcheck(root->left,temp);
		if(i==1)
			return 1;
		if(root->data<*temp)
			return 1;
		*temp=root->data;
		i=bstcheck(root->right,temp);
	}
	return i;
}
void inorder1(struct node * root)
{
	if(root)
	{
	
		inorder1(root->left);
			printf("\n %d",root->data);
		inorder1(root->right);
	}
}
void main()
{
	int i,j=0;
	char ch='y';
	struct node *root,*top;
	root=NULL;
	top=NULL;
	while(1)
	{
		printf("enter an elemnt into tree");
		scanf("%d",&i);
		root=insert(root,i);
		printf("\n do u want to enter more input (y/n)?");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='n')
			break;
	}
	root->right->data=3;
	inorder1(root);
	i=bstcheck(root,&j);
	if(i==0) printf("bst");
	else
		printf("not bst");
}