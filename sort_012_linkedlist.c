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
struct node * sort(struct node *p)
{
	struct node *i=NULL,*temp,*j=NULL,*k=NULL;
	while(p!=NULL)
	{
		temp=p;
		p=p->next;
		if(temp->data=='0')
		{
			if(i==NULL)
			{
				i=temp;
				if(j==NULL)
					j=i;
				else
					i->next=j;
			}
			else 
			{
				temp->next=i;
				i=temp;
			}
		}
		else if(temp->data=='1')
		{
			if(j==NULL)
			{
				j=temp;
				if(i==NULL)
					i=j;
			}
			else
			{
				j->next=temp;
				j=temp;
			}
		}
		else if(temp->data=='2')
		{
			if(k==NULL)
			{
				k=temp;
				k->next=NULL;
			}
			else
			{
				temp->next=k;
				k=temp;
			}
		}
		else 
			return NULL;
	}
	if(j==NULL)
		return k;

	j->next=k;
	return i;


}
void main()
{
char *d=(char *)malloc(10*sizeof(char));
struct node *temp;
printf("\n enter the string");
scanf("%s",d);
temp=create(d);
temp=sort(temp);
if(temp==NULL)
	printf("invalid data");
else
{
while(temp->next!=NULL)
	 {
	 printf("\n%c",temp->data);
	  temp=temp->next;
	  }
	printf("\n%c",temp->data);
}
}