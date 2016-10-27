#include<stdio.h>
struct node
{
char data;
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
	while(*(d+1)!='\0')
	{
		temp->data=*d;
		d++;
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		
	}
	temp->data=*d;
	temp->next=NULL;
	return head;
}
void loop(struct node *p)
{
	struct node *i,*j;
	i=p;
	j=p;
	do
	{
		i=i->next;
		j=j->next->next;
	}while(i!=j && j!='\0' && j->next!='\0');
	if( j=='\0' || j->next=='\0')
	{
		printf("no loop");
	}
	else
	{
		i=p;
		if(i==j || j==j->next)
		{
			j->next=NULL;
		}
		else
		{
		while(i->next!=j->next)
		{
			i=i->next;
			j=j->next;
		}
		j->next=NULL;
		}
	}
}
void main()
{
char *d=(char *)malloc(10*sizeof(char));
struct node *temp,*temp1;
printf("\n enter the string");
scanf("%s",d);
temp=create(d);
temp1=temp;
while(temp1->next!=NULL)
	 {
	  temp1=temp1->next;
	  }
	//creating a loop in the list
	temp1->next=temp->next->next->next;
loop(temp);
//printing the list by removing loop
while(temp->next!=NULL)
	 {
	 printf("\n%c",temp->data);
	  temp=temp->next;
	  }
	printf("\n%c",temp->data);
}