#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *link;
};

struct node * push(struct node *head,int data)
{
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=data;
		head->link=NULL;
	}
	else
	{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=head;
	head=temp;
	}
	return head;
}

struct node * pop(struct node *head)
{
	if(head==NULL)
		return NULL;
	head=head->link;
	return head;
}

int peek(struct node *head)
{
	if(head==NULL)
		return INT_MIN;
	return head->data;
}

struct node * sort(struct node *head)
{
	struct node *newhead=NULL;
	int data,temp;
	while(head!=NULL)
	{
		data=peek(head);
		head=pop(head);
		if(newhead==NULL)
			newhead=push(newhead,data);
		else
		{
			temp=peek(newhead);
			while(data>temp)
			{
				head=push(head,temp);
				newhead=pop(newhead);
				temp=peek(newhead);
				if(temp==INT_MIN)
					break;
			}
			newhead=push(newhead,data);
		}
	}
	return newhead;
}

void print_stack(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->link;
	}
}

void main()
{
	int *p=(int*)malloc(sizeof(int));
	struct node *head=NULL;
	head=push(head,10);
	head=push(head,-10);
	head=push(head,5);
	head=push(head,-20);
	head=sort(head);
	print_stack(head);

}