#include<stdio.h>
#include<malloc.h>
void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
void main()
{
	int *a,i,j,n;
	printf("enter the size of array");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter values of array");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	i=0;
	j=n-1;
	while(i<j)
	{
	  if(a[i]!=1){
		  i++; continue;}
	  if(a[j]!=0){
	   j--;continue;}
	if((a[i]==1 && a[j]==0)&&(i<j))
 	  swap(&a[i],&a[j]);
	}
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}