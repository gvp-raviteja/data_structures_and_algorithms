#include<stdio.h>
#include<malloc.h>
void rev(int *a,int i,int j)
{
	int k;
	while(i>j)
	{
		k=a[i];
		a[i]=a[j];
		a[j]=k;
		i--;
		j++;
	}
}
void ls(int *a,int n,int c)
{
int i;
if(c<0) return;
c=c%n;
rev(a,c-1,0);
rev(a,n-1,c);
rev(a,n-1,0);
for(i=0;i<n;i++)
printf("\n%d",a[i]);
}
void main()
{
int *a,i,n,c;
printf("enter length:");
scanf("%d",&n);
a=(int*)malloc(n+1*sizeof(int));
printf("enter array:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter c:");
scanf("%d",&c);
ls(a,n,c);
}
