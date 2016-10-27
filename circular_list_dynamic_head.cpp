#include<stdio.h>
#include<malloc.h>
struct node 
{
	int data;
	struct node *next;
};
struct node * insert_next(struct node *root,int data)
{
	struct node *temp;
	temp=root->next;
	root->next=(struct node *)malloc(sizeof(struct node));
	root=root->next;
	root->data=data;
	root->next=temp;
	return root;
}

struct node *insert(struct node *head,int data)
{
	struct node *temp=head;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=data;
		head->next=head;
	}
		if(head->data==data)
		return head;
	if(temp->next==head)
		return insert_next(temp,data);
	do
	{
		if(temp->data==data)
			return temp;
		else if(temp->data<data)
		{
			if(temp->data < temp->next->data)
			{
				if(data < temp->next->data)
					return insert_next(temp,data);
			}
			else if(temp->data > temp->next->data)
			{
				if(temp->next->data < data)
					return insert_next(temp,data);
			}
		}
		else
		{
			if(data < temp->next->data)
				return insert_next(temp,data);
		}
		temp=temp->next;
	}while(temp!=head);
}

void print(struct node *root)
{
	struct node *temp;
	if(root==NULL)
		return;
	temp=root;
	do
	{
		printf("\n %d",root->data);
		root=root->next;
	}while(temp!=root);
}

void main()
{
	struct node *root=NULL;
	char ch;
	int i;
	while(1)
	{
		printf("enter the elemnt to be inserted");
		scanf("%d",&i);
		root=insert(root,i);
		printf("do you want to continue y/n");
		fflush(stdin);

		scanf("%c",&ch);
		if(ch=='n' || ch=='N')
			break;
	}
	print(root);
}