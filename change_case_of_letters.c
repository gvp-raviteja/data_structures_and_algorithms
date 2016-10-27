#include<stdio.h>
#include<malloc.h>
void vowels(char *d)
{
	int i=0,j=0;
	while(*d!='\0')
	{
		if(*d>='a' && *d<='z') 
			*d=*d-32;
		else if(*d>='A' && *d<='Z')
			*d=*d+32;
		d++;
	}
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
	vowels(d);
	printf("%s",d);
}