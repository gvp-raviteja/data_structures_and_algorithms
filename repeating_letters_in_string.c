#include<stdio.h>
#include<malloc.h>
void repeat(char *d,int i,int j)//i is the length of string and j is the repetition count
{
	int k=0,l,m;
	l=i*j-1;
	m=i-1;
	while(m>=0)
	{
		if(k<j)
		{
			d[l]=d[m];
			l--;k++;
		}
		else
		{
			k=0;
			m--;
		}
	}
	d[i*j]='\0';
}
void main()
{
	int i,j;
	char *d;
	printf("\n enter the size of string");
	scanf("%d",&i);
	d=(char*)malloc((i+1)*sizeof(char));
	printf("\n enter the string");
	scanf("%s",d);
	printf("\n enter the count");
	scanf("%d",&j);
	d=(char *)realloc(d,(i*j+1)*sizeof(char));
	repeat(d,i,j);
	printf("\n %s",d);
}