#include<stdio.h>
#include<malloc.h>
char base4(char *p)
	{
	int i=0,j=0;
	char c;
	while(j<2)
		{
		i=i<<1;
		i=i-48+(int)*p;
		p++;
		j++;
		}
	c=i+48;
	return c;
	}
char* base2to4(char *d,int n)
{
	char *c,*e;
	int i=0,j=0;
	c=(char *)malloc(n*sizeof(int));
	e=(char *)malloc(n*sizeof(int));
	if(*d=='\0')
		 return NULL;
	if(*(d+1)!='\0')
	{
		while(*(d+1)!='\0')
		{
			c[j]=base4(d);
			d=d+2;
			j++;
			i=i+2;
			if(*d=='\0')
			{
				c[j]='\0';
		 		return c;
			}
		}
		d--;
	}
	c[j+1]='\0';
	while(i>=0)
	{
		if(i==0)
		{
			e[1]=*d;
			e[0]='0';
			c[j]=base4(e);
			i--;
		}
		else
		{
			c[j]=base4(d);
			j--;
			i=i-2;
			if(i==0)
 			d--;
			else
			d=d-2;
		}
	}
	return c;
}
void main()
{
	char *c="1101";
	char *d;
	int i=0,n;
	printf("\n enter the size of input");
	scanf("%d",&n);
	c=(char *)malloc(n*sizeof(int));
	printf("\n enter the string");
	scanf("%s",c);
	d=base2to4(c,n);
	printf("%s",d);
}
