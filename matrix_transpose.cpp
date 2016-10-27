#include<stdio.h>
#include<malloc.h>
void transpose(int *a,int i ,int j)
{
	if(i==1 || j==1)
		return;
	int m=0,n=1,k=1;
	int *b;
	b=(int *) malloc(i*j*sizeof(int));
	b[0]=1;
	for(;k<i*j-1;k++)
		b[k]=0;
	b[k]=1;
	int flag=1,temp,temp1;
	k=1;
	while(flag==1)
	{
	flag=0;
	int l=k;
	m=k/j;
	n=k%j;
	b[k]=1;
	temp=a[k];
	do
	{
		k=n*i + m;
		b[k]=1;
		temp1=a[k];
		a[k]=temp;
		temp=temp1;
		m=k/j;
		n=k%j;
	}
	while(k!=l);
	for(k=1;k<i*j-1;k++)
	{
		if(b[k]==0)
		{
			flag=1;
			break;
		}
	}
	}
}

void main()
{
	int *a;
	int i,j,k,l,m=0;
	printf("enter the no of rows and columns");
	scanf("%d%d",&i,&j);
	a=(int *) malloc(i*j*sizeof(int));
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			scanf("%d",&a[m]);
			m++;
		}
	}
	transpose(a,i,j);
	for(i=0;i<m;i++)
	printf("%d ",a[i]);
}