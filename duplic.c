#include<stdio.h>
#include<malloc.h>
char* redundant(char *p)
{
int i=0,j=0;
while(p[i]!='\0' && p[i]!=p[i+1])
{
	i++;j++;
}
while(p[i]!='\0')
{
if(p[i]!=p[i+1])
{
p[j]=p[i];
j++;
}
i++;
}
p[j]='\0';
return p;
}
void main()
{
char *p;
p=(char *)malloc(20*sizeof(char));
printf("\n enter the string");
scanf("%s",p);
p=redundant(p);
printf("%s",p);
}