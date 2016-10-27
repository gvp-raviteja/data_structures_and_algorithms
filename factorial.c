#include<stdio.h>
#include<malloc.h>
int iterative(int n)
{
	int k=n;
	while(n>1)
	{
		k=k*(n-1);
		n--;
	}
	return k;
}
int recursive(int n)
{
	if(n==0)
		return 1;
	else
		return n*recursive(n-1);
}
void main()
{
	int n;
	printf("enter the number");
	scanf("%d",&n);
	n=recursive(n);
	printf("%d",n);
}