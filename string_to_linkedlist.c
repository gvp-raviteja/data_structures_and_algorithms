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
	if(*d=='\0')
		return NULL;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=*d;
	head->link=(struct node*)malloc(sizeof(struct node));
	temp=head->link;
	d++;
	if(*d=='\0')
	{
		head->link=NULL;
		return head;
	}
	while(*(d+1)!='\0')
	{
		temp->data=*d;
		d++;
		temp->link=(struct node*)malloc(sizeof(struct node));
		temp=temp->link;
		
	}
	temp->data=*d;
	temp->link=NULL;
	return head;
}
void main()
{
char *d;
int n;
struct node *head;
printf("\n enter the size of string");
scanf("%d",&n);
d=(char *)malloc(n*sizeof(char));
printf("\n enter the string");
scanf("%s",d);
head=create(d);
if(head==NULL)
	printf("null string");
else
{
while(head->link!=NULL)
{
printf("%c ->",head->data);
head=head->link;
}
printf("%c",head->data);
}
}