#include<stdio.h>
#include<malloc.h>
void digits(char *d)
{
	int j=0,k=0;
	while(d[k]!='\0' && (d[k]<'0' || d[k]>'9'))
		k++;
	j=k;
	while(d[k]!='\0')
	{
		if(d[k]<'0' || d[k]>'9') 
		{
			d[j]=d[k];
			j++;
		}
		k++;
	}
	d[j]='\0';
}
void main()
{
	int i;
	char *d;
	printf("\n enter the size of string");
	scanf("%d",&i);
	d=(char*)malloc((i+1)*sizeof(char));
	printf("\n enter the string");
	scanf("%s",d);
	digits(d);
	printf("%s",d);
}