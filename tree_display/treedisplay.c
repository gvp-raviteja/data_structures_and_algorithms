#include<stdio.h>
#include<math.h>
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
	for(;i<7;i++)
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
void preorder(struct node *root,int i,int j,int h,char **a,int **e)
{
	int k,c,d,l;
	c=i;d=j;
	if(root!=NULL && h!=0)
	{
		a[i][j]=e[i][j]=root->data;
		k=h-1;
		if(k!=0)
		k=((k-1)*(k-1)) +1;
		l=k;
		if(root->prev!=NULL)
		{
			for(;k>0;k--)
			{
				i--;j--;
				a[i][j]='/';
			}
			i--;j--;
		}
		if(root->next!=NULL)
		{
			for(;l>0;l--)
			{
				c--;d++;
				a[c][d]='\\';
			}
			c--;d++;	
		}
		if(root->prev!=NULL)
			preorder(root->prev,i,j,h-1,a,e);
		if(root->next!=NULL)
			preorder(root->next,c,d,h-1,a,e);
	}
}
void print(struct node *root,int h)
{
	int **c,i=0,j=0;
	char **a;
	a=(char **)malloc(12*sizeof(char *));
	for(i=0;i<12;i++)
		a[i]=(char *)malloc(23*sizeof(char));
	for(i=0;i<12;i++)
		for(j=0;j<23;j++)
			a[i][j]=' ';
	c=(int **)malloc(12*sizeof(int *));
	for(i=0;i<12;i++)
		c[i]=(int *)malloc(23*sizeof(int));
	for(i=0;i<12;i++)
		for(j=0;j<23;j++)
			c[i][j]=0;
	preorder(root,11,11,h,a,c);
	for(i=11;i>=0;i--)
	{
		for(j=0;j<23;j++)
		{
			if(a[i][j]==c[i][j])
				printf("%d ",c[i][j]);
			else
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}

}
int height(struct node *root,int h)
{
	int h1,h2;
	if(root!=NULL)
	{
		h1=height(root->prev,h+1);
		h2=height(root->next,h+1);
		if(h1>h2)return h1;
		else return h2;
	}
	else
		return h;
}
void  main()
{
	int h=0;
	struct node *head,*tail;
	head=(struct node*)malloc(sizeof(struct node));
	create(&head,&tail);
	printf("%d ,%d \n",head->data,tail->data);
	head=bintre(head,tail);
	//printf(" %d %d %d \n",head->data,head->next->data,head->prev->data);
	h=height(head,h);
	print(head,h);
}