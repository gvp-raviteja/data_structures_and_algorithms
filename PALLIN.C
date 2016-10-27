#include<stdio.h>
#include<malloc.h>
struct node
{
	char data;
	struct node *link;
};
struct node* create(char *d)
{
	struct node *temp,*head;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=*d;
	head->link=(struct node*)malloc(sizeof(struct node));
	temp=head->link;
	d++;
	while(*(d+1)!='\0')
	{
		temp->data=*d;
		temp->link=(struct node*)malloc(sizeof(struct node));
		temp=temp->link;
		d++;
	}
	temp->data=*d;
	temp->link=NULL;
	return head;
}
struct node* reverse( struct node *g,struct node *temp,struct node *prev)
{	
	while(g->link!=NULL)
	{
		temp=g->link;
		g->link=prev;
		prev=g;
		g=temp;
	}
	g->link=prev;
	return g;
}
int ispallindrome(struct node *head)
{
	int flag=0;
	struct node *mid,*last,*temp,*prev,*curr;
	prev=NULL;
	curr=NULL;
	mid=head;
	last=head;
	while(last!=NULL &&  last->link!=NULL )
	{
		last=last->link->link;
		temp=mid;
		mid=mid->link;
	}
	temp->link=NULL;
	mid=reverse(mid,curr,prev);
	last=mid;
	while(head->link!=NULL)
	{
		if(head->data!=mid->data)
 		flag=1;
		head=head->link;
		mid=mid->link;
	}
	if(head->data!=mid->data)
 		flag=1;
	head->link=reverse(last,curr,prev);
	return flag;
}
void main()
{
	int i;
	char *d;
	struct node *head;
	printf("\n enter the size of string");
	scanf("%d",&i);
	d=(char*)malloc((i+1)*sizeof(char));
	printf("\n enter the string");
	scanf("%s",d);
	head=create(d);
	i=ispallindrome(head);
        if(i==0)
           printf("is pallindrome \n");
        else 
	printf("not pallindrome \n ");
	while(head->link!=NULL)
	{
		printf("%c",head->data);
		head=head->link;
	}
	printf("%c",head->data);
}