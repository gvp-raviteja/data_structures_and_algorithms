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

struct node * merge(struct node *list1,struct node *list2)
{
	struct node *head=NULL,*temp;
	if(list1==NULL)
		return list2;
	else if(list2==NULL)
		return list1;
	else if(list1->data<=list2->data)
	{
		head=list1;
		if(list1->data==list2->data)
			list2=list2->next;
		list1=list1->next;
	}
	else
	{
		head=list2;
		list2=list2->next;
	}
	temp=head;
	while(list1!=NULL && list2!=NULL)
	{
		if(list1->data<=list2->data)
		{
			temp->next=list1;
			if(list1->data==list2->data)
				list2=list2->next;
			list1=list1->next;
			
		}
		else
		{
			temp->next=list2;
			list2=list2->next;
		}
		temp=temp->next;
	}
	if(list1==NULL)
		temp->next=list2;
	else
		temp->next=list1;
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
	printf("enter the length of 2nd string");
	scanf("%d",&i);
	str=(char *)malloc((i+1)*sizeof(char));
	printf("enter the string ");
	scanf("%s",str);
	root1=str_to_list(str);
	add=merge(root,root1);
	while(add!=NULL)
	{
		printf("%d",add->data);
		add=add->next;
	}

}