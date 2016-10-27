#include<stdio.h>
#include<malloc.h>
struct node 
{
	int data;
	struct node *next;
};

struct node * str_to_list(char *str)
{
	struct node *root,*x;
	root=(struct node *)malloc(sizeof(struct node));
	if(str==NULL)
		return NULL;
	if(*str<'0' || *str>'9')
		return NULL;
	root->data= *str-'0';
	root->next=NULL;
	x=root;
	str++;
	while(*str!='\0')
	{
		if(*str<'0' || *str>'9')
			return NULL;
		root->next=(struct node *)malloc(sizeof(struct node));
		root=root->next;
		root->data=*str-'0';
		root->next=NULL;
		str++;
	}
	return x;
}

struct node * insert_next(struct node *root,int data)
{
	struct node *temp;
	temp=root->next;
	root->next=(struct node *)malloc(sizeof(struct node));
	root=root->next;
	root->data=data;
	root->next=temp;
	return root;
}

void insert_loop(struct node *root)
{
	if(root==NULL)
		return ;
	struct node *i=root,*j=root;
	while(j->next!=NULL && j->next->next!=NULL)
	{
		i=i->next;
		j=j->next->next;
	}
	while(j->next!=NULL)
		j=j->next;
	j->next=i;
}

struct node * insert_at_begin(struct node *root,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=root;
	return temp;
}

struct node * insert_node(struct node *root,int data)
{
	int flag=0;
	if(data<=root->data)
	{
		root=insert_at_begin(root,data);
		flag=1;
	}
	struct node *temp=root,*temp1=root;
	while(temp->next->data>temp->data && temp->next->next->data > temp->next->data)
	{

		if(flag==0 && temp->next->data>data )
		{
			insert_next(temp,data);
			flag=1;
		}
		else if(flag==0 && temp->next->next->data>data )
		{
			insert_next(temp->next,data);
			flag=1;
		}
		temp=temp->next->next;
		temp1=temp1->next;
	}
	if(temp->next->data<temp->data)
	{
		if(flag==0)
		{
			insert_next(temp,data);
		}
		else if(temp->next->next==temp1)
		{
			temp->next=temp1;
		}
	}
	else if(temp->next->next->data < temp->next->data)
	{
		if(flag==0)
		{
			if(data<temp->next->data)
				insert_next(temp,data);
			else
				insert_next(temp->next,data);
			temp->next->next->next=temp1->next;
		}
		else if(temp->next->next==temp1->next)
		{
			temp->next->next=temp1->next;
		}
	}
	return root;
}

void main()
{
	char *str;
	int i;
	struct node *root,*add;
	printf("enter the length of string");
	scanf("%d",&i);
	str=(char *)malloc((i+1)*sizeof(char));
	printf("enter the string ");
	scanf("%s",str);
	root=str_to_list(str);
	insert_loop(root);
	root=insert_node(root,4);
	while(root->data<root->next->data)
	{
		printf("%d",root->data);
		root=root->next;
	}
	printf("%d",root->data);
}