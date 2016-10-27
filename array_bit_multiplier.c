#include<stdio.h>
#include<malloc.h>

unsigned int pow(int x,int y)
{
	unsigned int k=1;
	while(y!=0)
	{
		k=k*x;
		y--;
	}
	return k;
}

void lshift(unsigned int *c,unsigned int k)
{
	unsigned int i=0,j,l=0,x=pow(2,31);
	while(i<k)
	{
		j=c[i]&x;
		c[i]=c[i]<<1;
		c[i]=c[i]+l;
		if(j==x)
			l=1;
		else
			l=0;
		i++;
	}
}

void add(unsigned int *a,unsigned int *b,unsigned int i,unsigned int j)
{
	unsigned int k,m,carry=0;
	unsigned int l=4294967295;
	m=i;
	for(k=0;k<m;k++)
	{
		b[k]=b[k]+a[k]+carry;
		carry=0;
		if(l-a[k]<b[k])
			carry=1;	
	}
	while(k<j)
	{
		if(b[k]==l)
			b[k]=b[k]+carry;
		else
		{
			b[k]=b[k]+carry;
			break;
		}
		k++;
	}
}

void multiply(unsigned int *a,unsigned int *b,unsigned int *c,unsigned int i,unsigned int j,unsigned int k)
{
	 unsigned int x=pow(2,31),m=1,l=j*32;
	 while(l>0)
	 {
		 lshift(c,k);
		 if((b[j-1]&x)==x)
		 {
			 add(a,c,i,k);
		 }
		 lshift(b,j);
		 l--;
	 }
}

void main()
{
	unsigned int *a,*b,*c,i,j,k;
	int l;
	printf("enter length of array");
	scanf("%d",&i);
	a=(unsigned int *)malloc(i*sizeof(unsigned int));
	for(j=0;j<i;j++)
	{
		scanf("%d",&a[j]);
	}
	printf("enter length of array");
	scanf("%d",&k);
	b=(unsigned int *)malloc(k*sizeof(unsigned int));
	for(j=0;j<k;j++)
		scanf("%d",&b[j]);
	j=i+k;
	c=(unsigned int *)malloc(j*sizeof(unsigned int));
	for(l=0;l<j;l++)
		c[l]=0;
	multiply(a,b,c,i,k,j);
	for(l=j-1;l>=0;l--)
		printf("\n %u",c[l]);

}