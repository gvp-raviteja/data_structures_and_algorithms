#include<stdio.h>
#include<malloc.h>
void reverse(int *a, int i , int j)
{
	int temp;
	while(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
}
void sort(int *a,int k,int n)
{
	int flag=0,i=0,j=0;
	while(i<n && a[i]<a[i+1])
	{
		i++;
		flag=1;
	}
	if(i==(n-1)) return;
	if(flag==1)
	{
		j=i;
		while(a[i]>a[i+1] && i+1<n)
			i++;
		if(a[k]>a[i])
		{
			reverse(a,k,j);
			sort(a,i,n);
			return;
		}
		reverse(a,j,i);
		sort(a,i,n);
		return;
	}
	while(i<n && a[i]>a[i+1])
	{
		i++;
		flag=1;
	}
	if(i==n-1) return;
	if(flag==1)
	{
		j=i;
		while(a[i]<a[i+1] && i+1<n)
			i++;
		if(a[k]<a[i])
		{
			reverse(a,k,j);
			sort(a,i,n);
			return;
		}
		reverse(a,j,i);
		sort(a,i,n);
		return;
	}
}
void main()
{
	int *a,n,i,flag=0;
	printf("enter the size of array");
	scanf("%d",&n);
	a=(int *) malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,0,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
