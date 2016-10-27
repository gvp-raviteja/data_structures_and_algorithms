// arrays.cpp :  Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

//using extra memory for all the character set
int unique(char *str)
{
	int s[256];
	int i=0;
	while(i<256)
	{
		s[i]=0;
		i++;
	}
	while(*str)
	{
		if(s[*str]!=0)
			return 0;
		s[*str]=1;
		str++;
	}
	return 1;
}

//using bit vector, assumed that the input has lower case characters and took a bit vector
// of size 26.
int unique1(char *str)
{
	int i=0,j;
	while(*str)
	{
		j=1<<(*str-'a');
		if((i&j)!=j)
		{
			i+=j;
		}
		else 
			return 0;
		str++;
	}
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s;
	int i;
	printf("enter the lenght of string");
	scanf("%d",&i);
	s=(char *)malloc(i*sizeof(char));
	printf("enter the string");
	scanf("%s",s);
	i=unique1(s);
	if(i==0)
		printf("it has duplicates\n");
	else
		printf("it has all unique characters \n");
	return 0;
} 

