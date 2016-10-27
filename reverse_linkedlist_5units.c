#include<stdio.h>
#include<malloc.h>
struct node
{
	char data;
	struct node *next;
};
//given a string, this functions generates a linked list from that string
struct node * strlist(char *s)
{
	struct node *temp,*head=(struct node *)malloc(sizeof(struct node));
	if(*s=='\0')
		return NULL;
	head->data=*s;
	head->next=(struct node *)malloc(sizeof(struct node));
	temp=head->next;
	s++;
	if(*s=='\0')
	{
		head->next=NULL;
		return head;
	}
	while(*(s+1))
	{
		temp->data=*s;
		temp->next=(struct node *)malloc(sizeof(struct node));
		temp=temp->next;
		s++;
	}
	temp->data=*s;
	temp->next=NULL;
	return head;
}
// given a linked list, this function reverse the linked list 5 units at a tym... 
// i.e. given linked list of 1000 nodes ,reverse first 5 elements, then 6 to 10 elements, then 11 to 15 elements, and so on...
struct node * rev(struct node * head)
{
	int count=0;
	struct node *temp,*prev,*curr,*t,*h;
	h=t=temp=curr=head;
	prev=NULL;
	while(curr && count<5)
	{
		temp=curr;
		curr=temp->next;
		temp->next=prev;
		prev=temp;
		count++;
	}
	if(curr)
	{
	t->next=curr;
	t=curr;
	head=temp;
	}
	else
	{
		head=temp;
		return head;
	}
	count=0;
	while(curr)
	{
		while(curr && count <5)
		{
			temp=curr;
			curr=temp->next;
			temp->next=prev;
			prev=temp;
			count++;
		}
		h->next=temp;
		t->next=curr;
		h=t;
		t=curr;
		count=0;
	}
	return head;
}
void main()
{
	int i;
	char *s;
	struct node *head;
	head=NULL;
	printf("\n enter the size of linkedlist");
	scanf("%d",&i);
	s=(char *)malloc(i*sizeof(char));
	printf("\n enter the string");
	scanf("%s",s);
	head=strlist(s);
	head=rev(head);
	while(head)
	{
		printf("%c->",head->data);
		head=head->next;
	}
	printf("\\0");
}