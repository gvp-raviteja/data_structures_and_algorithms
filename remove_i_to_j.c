#include<stdio.h>
#include<malloc.h>
void rm(char *s,int i,int j)
{
	int k=i;
if(i>j || (i<0 && j<0))
  return ;
else if(i<j)
{
 if(i<0)
    i=0;
 if(*(s+i)=='\0')
	 return;
 while(*(s+k)!='\0')
	 k++;
 if(k>j)
 {
while(*(s+j)!='\0')
{
*(s+i)=*(s+j);
i++;
j++;
}
 }
*(s+i)='\0';
}
}
void main()
{
char *s;
int n,i,j;
printf("\n enter the size of string");
scanf("%d",&n);
s=(char *)malloc(n*sizeof(char));
printf("\n enter the string");
scanf("%s",s);
printf("enter the i nd j values");
scanf("%d %d",&i,&j);
rm(s,i-1,j);
printf("%s",s);
}