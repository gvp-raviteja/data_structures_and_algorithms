#include<stdio.h>
#include<malloc.h>
void main()
{
int *a,*b,i,j,n,k;
printf("\n enter the size of A");
scanf("%d",&i);
a=(int *)malloc(sizeof(int)*i+1);
printf("entre the elements of array a ");
for(n=0;n<i;n++) scanf("%d",&a[n]);
printf("\n enter the size of B");
scanf("%d",&j);
b=(int *)malloc(sizeof(int)*j+1);
printf("entre the elements of array b ");
for(n=0;n<j;n++) scanf("%d",&b[n]);
a=(int *)realloc(a,(i+j)*sizeof(int));
k=i+j;
while(i>0 &&j>0)
{
 if(a[i-1]>=b[j-1])
  {
   a[i+j-1]=a[i-1];
  i--;
 }
 if(a[i-1]<b[j-1])
  {
   a[i+j-1]=b[j-1];
  j--;
 }
}
while(j>0)
{
a[j-1]=b[j-1];
j--;
}
 for(n=0;n<k;n++)
 printf("\n %d",a[n]);
}