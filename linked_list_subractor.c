#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};

struct node * str_to_list(char *str)
{
	struct node *root,*x;
	root=(struct node *)malloc(sizeof(struct node));
	root->data= *str-'0';
	root->link=NULL;
	x=root;
	str++;
	while(*str!='\0')
	{
		root->link=(struct node *)malloc(sizeof(struct node));
		root=root->link;
		root->data=*str-'0';
		root->link=NULL;
		str++;
	}
	return x;
}

int sub(int a,int b, int *c)
{
	int k=a-b;
	*c=0;
	if(k<0)
	{
		*c=-1;
		k=10+k;
	}
	return k;
}

int len(struct node *root)
{
	int i=0;
	while(root!=NULL)
	{
		i++;
		root=root->link;
	}
	return i;
}

int cmp(struct node *root,struct node *root1)
{
	while(root!=NULL)
	{
		if(root->data>root1->data)
			return 1;
		else if(root->data<root1->data)
			return -1;
		root=root->link;
		root1=root1->link;
	}
}

struct node* subractor(struct node *root,struct node *root1)
{
	int *borrow,length=0,flag=0,flag1=0;
	struct node *temp1,*back=NULL,*head=NULL,*temp=NULL;
	borrow=(int *)malloc(sizeof(int));
	length=len(root)-len(root1);
	if(length!=0)
	{
		if(length<0)
		{
			temp1=root;
			root=root1;
			root1=temp1;
			flag1=1;
			length=-(length);
		}
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=root->data;
		head=temp;
		back=temp;
		root=root->link;
		while(length!=1)
		{
			temp->link=(struct node*)malloc(sizeof(struct node));
			temp=temp->link;
			temp->data=root->data;
			if(temp->data!=0)
				back=temp;
			length--;
			root=root->link;
		}
	}
	else if(length==0)
	{
		if(cmp(root,root1)==-1)
		{
			temp1=root;
			root=root1;
			root1=temp1;
			flag1=1;
		}
	}
	if(root!=NULL)
	{
		if(temp==NULL)
			temp=(struct node*)malloc(sizeof(struct node));
		else
		{
			temp->link=(struct node*)malloc(sizeof(struct node));
			temp=temp->link;
		}
		if(back==NULL)
			back=temp;
		temp->data=sub(root->data,root1->data,borrow);
		if(*borrow==-1)
		{
			back->data-=1;
			back=back->link;
			while(back!=temp)
			{
				back->data=9;
				back=back->link;
			}
		}
		if(head==NULL)
			head=temp;
		root=root->link;
		root1=root1->link;
	}
	while(root!=NULL)
	{
		temp->link=(struct node*)malloc(sizeof(struct node));
		temp=temp->link;
		temp->data=sub(root->data,root1->data,borrow);
		if(temp->data!=0)
		{
			if(*borrow == -1)
			{
				back->data-=1;
				back=back->link;
				while(back!=temp)
				{
					back->data=9;
					back=back->link;
				}
			}
			else
				back=temp;
		}
		root=root->link;
		root1=root1->link;
	}
	temp->link=NULL;
	while(head->data==0)
		head=head->link;
	if(flag1==1)
		head->data=-(head->data);
	return head;
}

void main()
{
	char *str;
	int i;
	struct node *root,*root1,*add;
	printf("enter the length of string");
	scanf("%d",&i);
	str=(char *)malloc((i+1)*sizeof(char));
	printf("enter the string ");
	scanf("%s",str);
	root=str_to_list(str);
	printf("enter the length of string");
	scanf("%d",&i);
	printf("enter the string ");
	scanf("%s",str);
	root1=str_to_list(str);
	add=subractor(root,root1);
	while(add!=NULL)
	{
		printf("%d",add->data);
		add=add->link;
	}
}