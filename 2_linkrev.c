#include<stdio.h>
struct node
{
int data;
struct node *next;
};
struct node* create(char *d)
{
	struct node *temp,*head;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=*d;
	head->next=(struct node*)malloc(sizeof(struct node));
	temp=head->next;
	d++;
	if(*d=='\0')
		head->next=NULL;
	else
	{
	while(*(d+1)!='\0')
	{
		temp->data=*d;
		d++;
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		
	}
	temp->data=*d;
	temp->next=NULL;
	}
	return head;
}
struct node* rev(struct node *temp)
{
	struct node *k,*i,*j;
	i=temp;
	k=temp;
	if(i!='\0' && i->next!='\0')
	{
		k=i->next;
		i->next=k->next;
		k->next=i;
		i=i->next;
	}
	while(i!='\0' && i->next!='\0')
	{
		j=i->next;
		i->next=j->next;
		j->next=i;
		i=i->next;
		temp->next=j;
		temp=temp->next->next;
	}
	return k;
}
void main()
{
char *d=(char *)malloc(10*sizeof(char));
struct node *temp;
printf("\n enter the string");
scanf("%s",d);
temp=create(d);
temp=rev(temp);
while(temp->next!=NULL)
	 {
	 printf("\n%c",temp->data);
	  temp=temp->next;
	  }
	printf("\n%c",temp->data);
}