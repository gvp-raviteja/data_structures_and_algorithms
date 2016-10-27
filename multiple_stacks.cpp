#include<stdio.h>
#include<malloc.h>

struct set_of_stacks
{
	struct stack *data;
	struct set_of_stacks *link;
};

struct stack
{
	int data;
	struct stack *link;
};

int count=0;

struct stack * push(struct stack *head,struct set_of_stacks **stack_head,int data)
{
	if(count==10)
	{
		if(*stack_head==NULL)
		{
			*stack_head=(struct set_of_stacks *) malloc(sizeof(struct set_of_stacks));
			(*stack_head)->data=head;
			(*stack_head)->link=NULL;
		}
		else
		{
			struct set_of_stacks *temp=(struct set_of_stacks *) malloc(sizeof(struct set_of_stacks));
			temp->data=head;
			temp->link=*stack_head;
			*stack_head=temp;
		}
		count=0;
		head=NULL;
	}
	if(head==NULL)
	{
		head=(struct stack *)malloc(sizeof(struct stack));
		head->data=data;
		head->link=NULL;
	}
	else
	{
		struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
		temp->data=data;
		temp->link=head;
		head=temp;
	}
	count++;
	return head;
}

struct stack * pop(struct stack *head,struct set_of_stacks **stack_head )
{
	if(head==NULL)
	{
		if(*stack_head==NULL)
			return NULL;
		else 
		{
			count=10;
			head=(*stack_head)->data;
			*stack_head=(*stack_head)->link;
		}
	}
	struct stack *temp;
	temp=head;
	head=head->link;
	count--;
	return head;
}

void main()
{
	struct set_of_stacks *stack_head=NULL;
	struct stack *head=NULL;
	for(int i=0;i<20;i++)
	{
		head=push(head,&stack_head,i);
	}
	for(int i=0;i<15;i++)
	{
		head=pop(head,&stack_head);
	}
	
}