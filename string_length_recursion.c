#include<stdio.h>
#include<malloc.h>
void length(char *c,int *i)
{
	if(*c!='\0')
	{
		*i=*i+1;
		length(++c,i);
	}
}
void main()
{
	char *c;
	int *i;
	i=(int *)malloc(sizeof(int));
	c=(char *)malloc(100*sizeof(char));
	printf("\n enter the string");
	scanf("%s",c);
	*i=0;
	length(c,i);
	printf("%s",c);
	printf(" %d",*i);
}