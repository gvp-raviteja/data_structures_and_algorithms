#include<stdio.h>
#include<malloc.h>
void lshift(int *s,int i,int n)
{
int j,*k,h=0,temp,g;
k=(int *)malloc(sizeof(int)*i);
for(j=0;j<i;j++)
k[j]=s[j];
g=i;
temp=n-i;
for(j=0;j<temp;j++)
s[h++]=s[i++];
for(j=0;j<g;j++)
s[h++]=k[j];
}

void main()
{
int n,*s,i;
printf("enter size of array");
scanf("%d",&n);
s=(int *)malloc(n*sizeof(int));
printf("enter array");
for(i=0;i<n;i++)
scanf("%d",&s[i]);
lshift(s,2,n);
for(i=0;i<n;i++)
printf("%d",s[i]);
}