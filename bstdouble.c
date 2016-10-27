#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
void create(struct node **head1,struct node **tail1 )
{
	struct node *temp,*temp1;
	int i=2;
	temp=(*head1);
	(*head1)->data=1;
	(*head1)->prev=NULL;
	for(;i<16;i++)
	{
		temp1=temp;
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		temp->data=i;
		temp->prev=temp1;
	}
	temp->next=NULL;
	(*tail1)=temp;
}
struct node* bintre(struct node *head1,struct node *tail1)
{
	struct node *head,*tail,*mid;
	head=head1;
	tail=tail1;
	if(head==NULL || tail==NULL)
		return NULL;
	if(head->next==tail)
	{
		 head->prev=NULL;
		 tail->next=tail->prev=NULL;
		 return head;
	}
	if(head==tail)
	{
		head->next=head->prev=NULL;
		return head;
	}
	while(head->next!=tail->prev && head->next!=tail)
	{
		head=head->next;
		tail=tail->prev;
	}
	mid=head->next;
	mid->prev=bintre(head1,mid->prev);
	mid->next=bintre(mid->next,tail1);
	return mid;
}
void inorder(struct node *head)
{
	if(head!=NULL)
	{
	inorder(head->prev);
	printf("\n %d",head->data);
	inorder(head->next);	
	}
}
void  main()
{
	struct node *head,*tail;
	head=(struct node*)malloc(sizeof(struct node));
	create(&head,&tail);
	printf("%d ,%d",head->data,tail->data);
	head=bintre(head,tail);
	printf(" %d %d %d",head->data,head->next->data,head->prev->data);
	inorder(head);
}