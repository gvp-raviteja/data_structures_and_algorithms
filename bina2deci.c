#include<stdio.h>
int bin2dec(char *p)
{
int i=0;
while(*p)
{
i=i<<1;
i=i-48+(int)*p;
p++;
}
return i;
}
void main()
{
int num,i;
char *c=(char *)malloc(10*sizeof(char));
scanf("%d",i);
while(i--)
{
scanf("%s",c);
num=bin2dec(c);
printf("%d\n",num);
}
}
