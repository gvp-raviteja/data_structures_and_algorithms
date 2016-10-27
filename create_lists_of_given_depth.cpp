#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *left,*right;
};

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


struct node * create_lists(struct node *root,struct node *list)
{
	if(root!=NULL)
	{
		if(list==NULL)
		{
			list=(struct node *)malloc(sizeof(struct node));
			list->data=root->data;
			list->left=list->right=NULL;
		}
		else
		{
			struct node *temp1,*temp=(struct node *)malloc(sizeof(struct node));
			temp->data=root->data;
			if(list->left==NULL)
				temp->left=NULL;
			else
			{
				temp->left=list->left->left;
				list->left->left=NULL;
			}
			temp1=list->left;
			list->left=temp;
			temp->right=temp1;
			list=list->left;
		}
		create_lists(root->left,list);
		create_lists(root->right,list);
		return list;
	}
	return list;
}
void print_lists(struct node *p)
{
	struct node *q;
	while(p!=NULL)
	{
		q=p;
		while(q!=NULL)
		{
			printf("%d ->",q->data);
			q=q->right;
		}
		printf("\n");
		p=p->left;
	}
}

void main()
{
	char str[]="(1,(2,N,(1,3,N),(3,(0,1,N),0))";
	char *temp=str;
	struct node *root=create_tree_from_string(&temp),*p=NULL,*q;
	p=create_lists(root,p);
	print_lists(p);
}