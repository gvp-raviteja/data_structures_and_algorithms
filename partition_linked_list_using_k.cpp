// linked_lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};

struct node * str_to_list(char *str)
{
	struct node *root,*x;
	root=(struct node *)malloc(sizeof(struct node));
	if(str==NULL)
		return NULL;
	if(*str<'0' || *str>'9')
		return NULL;
	root->data= *str-'0';
	root->link=NULL;
	x=root;
	str++;
	while(*str!='\0')
	{
		if(*str<'0' || *str>'9')
			return NULL;
		root->link=(struct node *)malloc(sizeof(struct node));
		root=root->link;
		root->data=*str-'0';
		root->link=NULL;
		str++;
	}
	return x;
}
//method 1, 4 pointers
struct node * partition(struct node *root,int data)
{
	struct node *first=NULL,*last=NULL,*head,*temp;
	while(root!=NULL)
	{
		if(root->data<data)
		{
			if(first==NULL)
			{
				first=root;
				head=first;
			}
			else
			{
				first->link=root;
				first=first->link;
			}
			root=root->link;
		}
		else
		{
			if(last==NULL)
			{
				last=root;
				root=root->link;
				last->link=NULL;
			}
			else
			{
				temp=last;
				last=root;
				root=root->link;
				last->link=temp;
				
			}
		}
		
	}
	if(first==NULL)
		return last;
	first->link=last;
	return head;
}
// method 2, 3 pointers
struct node * partition1(struct node *root,int data)
{
	struct node *first=NULL,*last=NULL,*temp;
	while(root!=NULL)
	{
		if(root->data<data)
		{
			if(first==NULL)
			{
				first=root;
				last=root;
				root=root->link;
			}
			else
			{
				temp=first;
				first=root;
				root=root->link;
				first->link=temp;
			}
		}
		else
		{
			if(last==NULL)
			{
				first=last=root;
			}
			else
			{
				last->link=root;
				last=last->link;
			}
			root=root->link;
		}
	}
	last->link=NULL;
	return first;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *str;
	int i;
	struct node *root,*root1,*add;
	printf("enter the length of string");
	scanf("%d",&i);
	str=(char *)malloc((i+1)*sizeof(char));
	printf("enter the string ");
	scanf("%s",str);
	root=str_to_list(str);
	root=partition1(root,5);
	while(root!=NULL)
	{
		printf("%d",root->data);
		root=root->link;
	}
	return 0;
}

