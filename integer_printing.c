#include<stdio.h>
#include<malloc.h>
void print(int i)
{
	int j=0,k;
	char *c;
	k=i;
	while(k/10!=0)
	{
		j++;
		k=k/10;
	}
	c=(char *)malloc((j+2)*sizeof(char));
	c[j+1]='\0';
	while(i/10!=0)
	{
		k=i%10;
		c[j]=k+'0';
		j--;
		i=i/10;
	}
	c[j]=i+'0';
	printf("%s",c);
}
void main()
{
	int i;
	char *c;
	printf("\n enter an integer");
	scanf("%d",&i);
	print(i);
}
