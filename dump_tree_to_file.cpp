#include <stdio.h>
#include<malloc.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
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
		else if(root->data<i)
			root->right=insert(root->right,i);
		return root;
	}
}

struct node * create_tree()
{
	struct node *root=NULL;
	int i,j,k;
	printf("enter the number of entries of bst");
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		scanf("%d",&k);
		root=insert(root,k);
	}
	return root;
}

int len1(int data)
{
	int i=1;
	while(data/10!=0)
	{
		data=data/10;
		i++;
	}
	return i;
}

char * str_int_concat(int data)
{
	int i=len1(data);
	char *str=(char *)malloc(i*sizeof(char));
	str[i--]='\0';
	while(data/10!=0)
	{
		str[i]= data%10 +'0';
		i--;
		data=data/10;
	}
	str[i]=data+'0';
	return str;
}

int len(char *str)
{
	int i=0;
	if(str==NULL)
		return i;
	while(*str!='\0')
	{
		str++;
		i++;
	}
	return i;
}

char * str_concat(int data,char *str1,char *str2)
{
	char *str,*c;
	int i,j=0;
	i=len1(data)+len(str1)+len(str2)+4;
	str=(char *)malloc(i*sizeof(char));
	str[j++]='(';
	c=str_int_concat(data);
	while(*c!='\0')
	{
		str[j++]=*c;
		c++;
	}
	str[j++]=',';
	if(str1==NULL)
		str[j++]='N';
	else
	{
		while(*str1!=NULL)
		{
			str[j++]=*str1;
			str1++;
		}
	}
	str[j++]=',';
	if(str2==NULL)
		str[j++]='N';
	else
	{
		while(*str2!=NULL)
		{
			str[j++]=*str2;
			str2++;
		}
	}
	str[j++]=')';
	str[j]='\0';
	return str;
}

char * tree_to_string(struct node * root)
{
	char *left,*right,*str;
	if(root!=NULL)
	{
		left=tree_to_string(root->left);
		right=tree_to_string(root->right);
		if(left==NULL && right==NULL)
			return str=str_int_concat(root->data);
		return str=str_concat(root->data,left,right);
	}
	return NULL;
}

void main()
{
	int a=NULL;
	char *str=(char *)malloc(100*sizeof(char));
	FILE *fp=fopen("tree.txt","w+");
	str='\0';
	struct node *root=create_tree();
	str=tree_to_string(root);
	printf("%s",str);
	fprintf(fp,"%s",str);
	fclose(fp);
}