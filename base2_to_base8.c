#include<stdio.h>
#include<malloc.h>
char base8(char *p)
	{
	int i=0,j=0;
	char c;
	while(j<3)
		{
		i=i<<1;
		i=i-48+(int)*p;
		p++;
		j++;
		}
	c=i+'0';
	return c;
	}
char* base2to8(char *d,int n)
{
	char *c,*e;
	int i=0,j=0;
	c=(char *)malloc(n*sizeof(int));
	e=(char *)malloc(4*sizeof(int));
	if(d[i]=='\0')
		 return NULL;
	if(d[i+1]!='\0' && d[i+2]!='\0')
	{
		while(d[i+1]!='\0' && d[i+2]!='\0')
		{
			c[j]=base8(&d[i]);
			j++;
			i=i+3;
			if(d[i]=='\0')
			{
				c[j]='\0';
		 		return c;
			}
		}
	}
	while(d[i]) i++;
	i=i-1;
	c[j+1]='\0';
	while(i>=0)
	{
		if(i==0)
		{
			e[2]=d[i];
			e[0]=e[1]='0';
			c[j]=base8(e);
			i--;
		}
		else if(i==1)
		{
			e[2]=d[i];
			e[1]=d[i-1];
			e[0]='0';
			c[j]=base8(e);
			i=i-2;
		}
		else
		{
			c[j]=base8(&d[i-2]);
			j--;
			i=i-3;
		}
	}
	return c;
}
void main()
{
	char *c;
	char *d;
	int n;
	printf("\n enter the size of input");
	scanf("%d",&n);
	c=(char *)malloc(n*sizeof(int));
	printf("\n enter the string");
	scanf("%s",c);
	d=base2to8(c,n);
	printf("%s",d);
}
