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
void inorder(struct node * root)
{
	if(root)
	{
		printf("\n %d",root->data);
		inorder(root->left);
		inorder(root->right);
	}
}
struct node * convert(struct node *top)
{
	if(top!=NULL)
	{
		struct node *temp1,*temp2;
		temp1=convert(top->left);
		temp2=convert(top->right);
		if(temp1!=NULL)
		{
			while(temp1->right!=NULL)
				temp1=temp1->right;
			temp1->right=top;
			top->left=temp1;
		}
		if(temp2!=NULL)
		{
			while(temp2->left!=NULL)
				temp2=temp2->left;
			temp2->left=top;
			top->right=temp2;
		}
	}
	return top;
}

void main()
{
	int i;
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
	inorder(root);
	top=convert(root);
	 while(top->left!=NULL)
	 top=top->left;
 while(top!=NULL)
 {
	 printf("%d",top->data);
	 top=top->right;
 }
}