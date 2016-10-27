// sample3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>

struct node 
{
	int data;
	struct node *next,*fifth;
};

struct node* insert(struct node *root,int data)
{
	int count=0;
	struct node *temp=root,*temp1,*temp2,*temp3;
	temp3=root;
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->data=data;
		root->next=root->fifth=NULL;
	}
	else
	{
		while(temp3->next!=NULL)
		{
			if(temp3->fifth!=NULL && temp3->fifth->data<=data)
			{
				count=5;
				temp=temp3;
				temp3=temp3->fifth;
			}
			else if(temp3->next->data<=data) 
			{
				if(count==5)
				{
					temp=temp->next;
				}
				else if(count<5)
				{
					count++;
				}
				temp3=temp3->next;
			}
			else
				break;
			
		}
		temp1=(struct node *)malloc(sizeof(struct node));
		temp1->data=data;
		temp1->fifth=NULL;
		if(temp3->next==NULL)
		{
			temp3->next=temp1;
			temp1->next=NULL;
		}
		else
		{
		temp2=temp3->next;
		temp3->next=temp1;
		temp1->next=temp2;
		}
		if(count<5)
			count++;
		else
			temp=temp->next;
		if(count==5)
		{
			temp->fifth=temp1;
			temp=temp->next;
		}
		temp1=temp1->next;
		if(count<5)
			count++;
		while(temp1!=NULL)
		{
			if(count==5)
			{
				temp->fifth=temp1;
				temp=temp->next;
			}
			else 
				count++;
			temp1=temp1->next;
		}
	}
	return root;
}

void print(struct node *root)
{
	struct node *temp=root;
	if(root !=NULL)
	{
	while(root->fifth!=NULL)
	{
		printf("%d ->",root->data);
		root=root->fifth;
	}
	printf("%d -> NULL",root->data);
	printf("\n| \n");
	print(temp->next);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *root=NULL;
	int i;
	char c;
	printf("hello world\n");
	while(1)
	{
		printf("enter the element to insert");
		scanf("%d",&i);
		root=insert(root,i);
		printf("do you want to continue inserting: y/n");
		fflush(stdin);
		scanf("%c",&c);
		if(c=='n' || c=='N')
			break;
	}
	print(root);
	return 0;
}

