#include<stdio.h>
#include<malloc.h>
void insert(char*i,char*j,int p)
{
int a=1;
if(p<0)
return;
while(*i&&*j)
{
if(a>=p)
{
*i=*j;
j++;
}
i++;
a++;
}
}
void main()
{
	int n;
	char *string1,*string2;
	printf("enter the size of input");
	scanf("%d",&n);
	string1=(char *)malloc(n*sizeof(char));
	printf("enter the string1");
	scanf("%s",string1);
	printf("enter the size of replacing string");
	scanf("%d",&n);
	string2=(char *)malloc(n*sizeof(char));
	printf("enter the string2");
	scanf("%s",string2);
	printf("enter the position");
	scanf("%d",&n);
	insert(string1,string2,n);
	printf("%s",string1);
}