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
	if(str==NULL)
		return NULL;
	if(*str<'0' || *str>'9')
		return NULL;
	root->data= *str-'0';
	root->link=NULL;
	x=root;
	str++;
	while(*str!='\0')
	{
		if(*str<'0' || *str>'9')
			return NULL;
		root->link=(struct node *)malloc(sizeof(struct node));
		root=root->link;
		root->data=*str-'0';
		root->link=NULL;
		str++;
	}
	return x;
}

int add(int a,int b, int *c)
{
	int k=a+b;
	*c=0;
	if(k>=10)
	{
		*c=k/10;
		k=k%10;
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

struct node* adder(struct node *root,struct node *root1)
{
	struct node *carry=NULL,*temp=NULL,*head=NULL;
	int diff,sum,*c=(int *)malloc(sizeof(int)),flag;

	if(root==NULL)
		return root1;
	else if(root1==NULL)
		return root;
	diff=len(root)-len(root1);
	if(diff!=0)
	{
		if(diff<0)
		{
			diff=-1*diff;
			temp=root;
			root=root1;
			root1=temp;
		}
		temp=NULL;
		while(diff>0)
		{
			if(temp==NULL)
			{
				temp=(struct node *)malloc(sizeof(struct node));
				temp->data=root->data;
				head=temp;
				carry=temp;
			}
			else
			{
				temp->link=(struct node *)malloc(sizeof(struct node));
				temp=temp->link;
				temp->data=root->data;
			}
			if(root->data==9)
				flag=1;
			else
			{
				carry=temp;
				flag=0;
			}
			diff--;
			root=root->link;
		}
	}
	while(root!=NULL)
	{
		sum=add(root->data,root1->data,c);
		if(temp==NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=sum;
			head=temp;
		}
		else
		{
			temp->link=(struct node*)malloc(sizeof(struct node));
			temp=temp->link;
			temp->data=sum;
		}
		if(*c==1)
		{
			if(carry==NULL)
			{
				carry=(struct node*)malloc(sizeof(struct node));
				carry->data=1;
				carry->link=temp;
				head=carry;
				carry=carry->link;
			}
			else 
			{
				if(flag==1)
				{
					if(carry->data==9)
					{
						struct node *c=(struct node*)malloc(sizeof(struct node));		
						c->data=1;
						c->link=carry;
						carry->data=0;
						head=c;
					}
					else
						carry->data+=1;
					carry=carry->link;
					while(carry!=temp)
					{
						carry->data=0;
						carry=carry->link;
					}
				}
				else
				{
					carry->data+=1;
					carry=carry->link;
				}
			}
		}
		else
		{
		    if(sum<9)
			    carry=temp;
		}
		if(sum==9)
			flag=1;
		else
			flag=0;
		root=root->link;
		root1=root1->link;
	}
	temp->link=NULL;
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
	str=(char *)malloc((i+1)*sizeof(char));
	printf("enter the string ");
	scanf("%s",str);
	root1=str_to_list(str);
	add=adder(root,root1);
	while(add!=NULL)
	{
		printf("%d",add->data);
		add=add->link;
	}
}