#include<stdio.h>
#include<malloc.h>

int binary_search(int *a,int i,int j,int x)
{
	int mid,y=0;
	if(i<=j)
	{
		mid=(i+j)/2;
		if(a[mid]==x)
			return mid;
		else if(mid-1>=0 && mid+1<=j)
		{
			if(a[mid-1]==x)
				return mid-1;
			if(a[mid+1]==x)
				return mid+1;
			if(a[mid-1]<=a[mid] )
				{
					if(a[mid]<=a[mid+1])	
					{
						if(x<a[mid])
							return binary_search(a,i,mid-2,x);
						else
							return binary_search(a,mid+2,j,x);
					}
					else
					{
						if(x>a[mid])
							return binary_search(a,mid+2,j,x);
						else
						{
							y=binary_search(a,i,mid-2,x);
							if(y==-1)
								y=binary_search(a,mid+2,j,x);
							return y;
						}
					}
				}	
			else if(a[mid-1]>a[mid])
			{
				if(a[mid]<=a[mid+1])
				{
					if(x<a[mid])
						return binary_search(a,i,mid-2,x);
					else
					{
						y=binary_search(a,mid+2,j,x);
						if(y==-1)
							y=binary_search(a,i,mid-2,x);
						return y;
					}
				}
				else
				{
					y=binary_search(a,mid+2,j,x);
					if(y==-1)
						y=binary_search(a,i,mid-2,x);
					return y;
				}
			}
		}
	}
	return -1;
}

void main()
{
	int i,j;
	int *a;
	printf("enter the elnght of array");
	scanf("%d",&i);
	a=(int *)malloc(i*sizeof(int));
	for(j=0;j<i;j++)
		scanf("%d",&a[j]);
	printf("enter the search element");
	scanf("%d",&j);
	j=binary_search(a,0,i-1,j);
	printf("%d",j);
}