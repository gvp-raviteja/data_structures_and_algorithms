#include<stdio.h>
#include<malloc.h>
int path(char **b,int i,int j,int k,int h,int n,int m,int l,int **a,int **c,int d)
{
	a[i][j]=1;
	if(b[i][j]=='0') return 0;
	if(i==(k) && j==(h))
	{
		c[d][0]=i;c[d][1]=j;
		return d;
	}
	if(i+2<=(2*n-1) && j<=(4*m-2) && a[i+2][j]!=1 && l==0)
	{
		c[d][0]=i;c[d][1]=j;
		l=path(b,i+2,j,k,h,n,m,l,a,c,d+1);
	}
	if(i<=(2*n-1) && j+4<=(4*m-2) && a[i][j+4]!=1 && l==0)
	{
		c[d][0]=i;c[d][1]=j;
		l=path(b,i,j+4,k,h,n,m,l,a,c,d+1);
	}
	if(i-2>=1 && a[i-2][j]!=1 && l==0)
	{
		c[d][0]=i;c[d][1]=j;
		l=path(b,i-2,j,k,h,n,m,l,a,c,d+1);
	}
	if(j-4>=2 && a[i][j-4]!=1 && l==0)
	{
		c[d][0]=i;c[d][1]=j;
		l=path(b,i,j-4,k,h,n,m,l,a,c,d+1);
	}	
	 return l;
}
void maze(char **b,int n,int m)
{
	int **a,v,i,j,**c,w,x,y,z;
	c=(int **)malloc((m*n)*sizeof(int*));
	for(i=0;i<m*n;i++)
		c[i]=(int *)malloc(2*sizeof(int));
	a=(int**)malloc((2*n+1)*sizeof(int));
	for(i=0;i<2*n+1;i++)
		a[i]=(int*)malloc((4*m+1)*sizeof(int));
	printf("\n enter the starting point rows nd columns");
	scanf("%d %d",&w,&x);
	printf("\n enter the end point");
	scanf("%d %d",&y,&z);
	if(w==0)
		w=1;
	else w=2*w+1;
	if(x==0)
		x=2;
	else x=4*x+2;
	if(y==0)
		y=1;
	else y=2*y+1;
	if(z==0)
		z=2;
	else z=4*z+2;
	v=path(b,w,x,y,z,n,m,0,a,c,0);
		printf("%d",v);
		for(i=0;i<=v;i++)
			printf(" %d %d\n",c[i][0],c[i][1]);
		/*b[1][0]=' ';
		b[1][2]=' ';*/
	for(i=0;i<v;i++)
	{
		if(c[i][1]<c[i+1][1])
		{
			for(j=c[i][1];j<c[i+1][1];j++)
				b[c[i][0]][j]=' ';
		}
		else if(c[i][1]>c[i+1][1])
		{
			for(j=c[i][1];j>c[i+1][1];j--)
				b[c[i][0]][j]=' ';
		}
		else if(c[i][0]<c[i+1][0])
		{
			for(j=c[i][0];j<c[i+1][0];j++)
			{
				b[j][c[i][1]-1]=' ';
				b[j][c[i][1]+1]=' ';
				b[j][c[i][1]]=' ';
			}
		}
		else
		{
			for(j=c[i][0];j>c[i+1][0];j--)
			{
				b[j][c[i][1]+1]=' ';
				b[j][c[i][1]-1]=' ';
				b[j][c[i][1]]=' ';
			}
		}
	}
	b[y][z]=' ';
	//b[2*n-1][4*m]=' ';

	for(i=0;i<2*n+1;i++)
	{
	for(j=0;j<(4*m+1);j++)
	{
		printf("%c",b[i][j]);
	}
	printf("\n");
	}
}
void main()
{
	char **a,**b;
	int k,n,m,i,j=0,l=0;
	printf("enter the rows of the input");
	scanf("%d",&n);
	a=(char**)malloc((n+1)*sizeof(char));
	printf("\n enter the columns");
	scanf("%d",&m);
	for(i=0;i<n;i++)
		a[i]=(char*)malloc((m+1)*sizeof(char));
	printf("\n enter the input");
	for(i=0;i<n;i++)
	{
		fflush(stdin);
	scanf("%s",a[i]);
	}
	b=(char **)malloc((2*n+1)*sizeof(char*));
	for(i=0;i<2*n+1;i++)
	{
		b[i]=(char*)malloc((4*m+1)*sizeof(char));
	}
	for(k=0;k<(2*n+1);k++)
	{
	for(i=0;i<(4*m+1);i++)
	{
		if(k%2==0)
			b[k][i]='-';
		else
		{
		if(i%4==0)
			b[k][i]='|';
		else if(i%2!=0)
			b[k][i]=' ';
		else
		{
			b[k][i]=a[j][l];
			l++;
		}
		}
	}
	if(k%2!=0)
	{
		l=0;
		j++;
	}
	}
for(i=0;i<2*n+1;i++)
{
	for(j=0;j<(4*m+1);j++)
	{
		printf("%c",b[i][j]);
	}
	printf("\n");
}
maze(b,n,m);
}