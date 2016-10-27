// arrays.cpp :  Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void matrix_rotation(int **a,int n)
{
	int i,j,k,l,m;
	int temp,temp1;
	i=0;
	j=n-1;
	while(j>=n/2)
	{
		for(l=i,m=j;l<j;l++,m--)
		{
			temp=a[i][l];
			a[i][l]=a[m][i];
			a[m][i]=a[j][m];
			a[j][m]=a[l][j];
			a[l][j]=temp;
		}
		i=i+1;
		j=j-1;
	}
}

void main()
{
	int **a;
	int i,j,k;
	printf("enter the matrix size");
	scanf("%d",&k);
	a=(int **)malloc(k*sizeof(int));
	for(i=0;i<k;i++)
		a[i]=(int *)malloc(4*sizeof(int));
	printf("\n enter the matrix elemsnts");
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	matrix_rotation(a,k);
	printf("\n rotated matrix \n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
