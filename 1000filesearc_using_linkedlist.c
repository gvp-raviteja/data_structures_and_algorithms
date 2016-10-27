#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
typedef struct tree
{
	char *str;
	struct tree *left;
	struct tree *right;
}node;
void removal(char *str);
/*compare function returns 2 if the element(which we have to insert) if less the element in t*/
/*retur 1 for greater*/
/*return 0 for equal*/
int compare(char *str1,char *str2)
{
	int i=0;
	while(str1[i]&&str2[i])
		if((str1[i]>str2[i])&&!(str1[i]-32==str2[i]))
				return 1;
		else if(str1[i]<str2[i]&&!(str1[i]+32==str2[i]))
				return 2;
		else
			i++;
		if(str1[i])
			return 1;
		else if(str2[i])
			return 2;
		else
			return 0;
}
node *insert(char *s,node *t)
{
	int i=0,c;
	node *root=t,*t1;
	while(t)
	{
		c=compare(s,t->str);
		if(c==2)
			t=t->left;
		else if(c==1)
			t=t->right;
		else
			break;
	}
	if(c)
	{
		t1=(node *)malloc(sizeof(node));
		i=0;
		t1->left=t1->right=NULL;
		while(s[i])
			t1->str[i]=s[i];
		t1->str[i]='\0';
		if(c==2)
			t->left=t1;
		else
			t->right=t1;
		}
		if(!root)
			root=t1;
		return root;
		
		
		
}
void removal(char *str)
{
	int i=0,j=0;
	while(str[i]!='\0'&&str[i]!='\n')
	{
		if(str[i]=='-'||str[i]=='='||str[i]==' ')
		{
			i++;
			continue;
		}
	
		str[j++]=str[i++];
	}
		str[j]='\0';
}
node *reading(node *t)
{
	char *str,i,c,*s;
	FILE *f,*f1;
	f1=fopen("ravi.txt","r");
	while(!feof(f1))
	{
	s=(char *)malloc(sizeof(char)*60);
	fscanf(f1,"%s",s);
	printf("\n%s",s);
	printf("\nend");
	f=fopen(s,"r");
	printf("\nopen");
	while(!feof(f))
	{	
		c=fgetc(f);
		i=0;
		str=(char *)malloc(sizeof(char)*256);
		fscanf(f,"%s",str);
			removal(str);
			if(!s)
			t=insert(str,t);
			free(str);
	}
	}
	return t;
}
int search(char *str,node *t)
{
	int j;
	while(t)
	{
		j=compare(str,t->str);
		if(j==2)
			t=t->left;
		else if(j==1)
			t=t->right;
		else
		{
			printf("\n%s ",t->str);
			return 1;
		}
	}
	return 0;
	
}


 
int main()
{
	char *str;
	int k=0;
	node *t=NULL;
	reading(t);
	printf("\nenter the word do you want to search");
	str=(char *)malloc(sizeof(char)*15);
	scanf("%s",str);
	k=search(str,t);
	if(k==0)
		printf("\nnot found");
	return 0;
}



