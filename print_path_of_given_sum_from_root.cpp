#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *left,*right;
};

void print(struct node *root,int *arr,int i,int sum)
{
	if(root!=NULL)
	{
		sum=sum-root->data;
		arr[i]=root->data;
		if(sum==0)
		{
			for(int j=0;j<=i;j++)
				printf("%d ->",arr[j]);
			printf("\n");
		}
		print(root->left,arr,i+1,sum);
		print(root->right,arr,i+1,sum);
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
	int *p=(int *)malloc(10*sizeof(int));
	char str[]="(1,(2,N,1),3)";
	char *temp=str;
	struct node *root=create_tree_from_string(&temp);
	print(root,p,0,4);

}