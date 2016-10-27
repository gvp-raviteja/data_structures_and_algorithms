#include<stdio.h>
#include<malloc.h>
void main()
{
int i,j,k,*a,*c,product;
printf("enter the size of array ");
scanf("%d",&i);
a=(int *)malloc(i*sizeof(int));
c=(int *)malloc(i*sizeof(int));
for(k=0;k<i;k++)
scanf("%d",&a[k]);
c[i-1]=a[i-1];
for(k=i-2;k>=0;k--)
{
j=a[k]*c[k+1];
c[k]=j;
}
product=a[0];
c[0]=c[1];
k=i;
for(i=1;i<k-1;i++)
{
c[i]=product*c[i+1];
product=product*a[i];
}
c[i]=product;
for(i=0;i<k;i++)
printf("%d ",c[i]);
}