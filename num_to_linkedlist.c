#include<stdio.h>
struct node
{
int data;
struct node *link;
};
struct node* create(struct node *head,int d)
{
struct node *temp;
while(d)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->data=d%10;
temp->link=head;
head=temp;
d=d/10;
}
return head;
}
void main()
{
int d;
struct node *head;
head=NULL;
printf("\n enter the number");
scanf("%d",&d);
head=create(head,d);
while(head->link!=NULL)
{
printf("%d->",head->data);
head=head->link;
}
printf("%d",head->data);
}