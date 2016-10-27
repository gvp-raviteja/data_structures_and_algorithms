#include<stdio.h>
struct node
{
int data;
struct node *next;
};
void insert(struct node **pi,int d)
{
struct node *p;
 if(*pi==NULL)
 {
 p=(struct node *)malloc(sizeof(struct node));
 p->data=d;
 p->next=NULL;
 *pi=p;
 }
else
{
p=*pi;
while(p->next!=NULL)
	{
		p= p->next;
	}
	p->next = (struct node *)malloc(sizeof(struct node));
	p=p->next;
	p->data = d;
	p->next = NULL;
}
}
struct node* reverse( struct node *g,struct node *temp,struct node *prev)
{
if(g->next!=NULL)
{
temp=g->next;
g->next=prev;
prev=g;
g=temp;
g=reverse(g,temp,prev);
return g;
}
g->next=prev;
return g;
}
void main()
{
struct node *temp,*t,*h;
temp=NULL;
t=NULL;
h=NULL;
insert(&temp,1);
insert(&temp,2);
insert(&temp,3);
insert(&temp,4);
insert(&temp,5);
temp=reverse(temp,t,h);
while(temp->next!=NULL)
	 {
	 printf("\n%d",temp->data);
	  temp=temp->next;
	  }
	printf("\n%d",temp->data);
}