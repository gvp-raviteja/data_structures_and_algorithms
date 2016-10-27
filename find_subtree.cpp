#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left,*right;
};


void tree_match(struct node *root, struct node *root1,int *i)
{
	if(root!=NULL && root1!=NULL && *i==0)
	{
		if(root->data!=root1->data)
			*i=1;
		else
		{
			tree_match(root->left,root1->left,i);
			if(*i==0)
				tree_match(root->right,root1->right,i);
		}
	}
	else if(root!=NULL || root1!=NULL)
	{
		*i=1;
	} 
}

void is_subtree(struct node *root,struct node *root1,int *k)
{
	int i=0;
	if(root!=NULL && *k==1)
	{
		if(root->data==root1->data)
		{
			tree_match(root,root1,&i);
			*k=i;
		}
		if(*k==1)
			is_subtree(root->left,root1,k);
		if(*k==1)
			is_subtree(root->right,root1,k);
	}
}

int str_to_int(char *str)
{
	int data=0;
	while(*str!='\0' && *str!=',' && *str!=')')
	{
		data=data*10 + *str - '0';
		(str)++;
	}
	return data;
}

void next_position(char **str)
{
	(*str)++;
	while( **str !=',')
	{
		(*str)++;
	}
	(*str)++;
}

struct node * create_tree_from_string(char **str)
{
	struct node *root;
	if(**str=='(')
	{
		(*str)++;
		root=(struct node *) malloc(sizeof(struct node));
		root->data=str_to_int(*str);
		next_position(str);
		root->left=create_tree_from_string(str);
		next_position(str);
		root->right=create_tree_from_string(str);
	}
	else
	{
		if(**str=='N')
			return NULL;
		root=(struct node *) malloc(sizeof(struct node));
		root->data=str_to_int(*str);
		root->left=root->right=NULL;
	}
	return root;
}

void main()
{
	int k=1;
	char str[]="(1,(2,N,1),(3,0,0))";
	char *temp=str;
	struct node *root=create_tree_from_string(&temp);
	char str1[]="(2,3,1)";
	temp=str1;
	struct node *root1=create_tree_from_string(&temp);
	is_subtree(root,root1,&k);
	if(k==0)
	{
		printf(" it is a subtree");
	}
}