#include<stdio.h>
#include<malloc.h>
int comp(char *s,int i,int j)
{
	int k=0;
	while(k<j)
	{
		if(s[i+k]!=s[i+j+k])
			return 1;
		k++;
	}
	return 0;
}
void stringcrunch(char *s)
{
	int count=1,i=0,j=0,k=0,l=0;
	while(s[k])k++;
	while(count<k)
	{
		if(s[i] && s[i+count-1])
		{
	while(s[i] && s[i+count-1])
	{
		if(comp(s,i,count)==1)
		{
		    while(l<count)
			{
			s[j+l]=s[i+l];
			l++;
			}
			j=j+1;
			i=i+1;
			l=0;
		}
		else
		i=i+count;
	}
	while(s[i])
	{
		i++;j++;
	}
	s[j]='\0';
	i=0;j=0;
	count++;
	}
		else
		break;
	}
	
}
void main()
{
	int i;
	char *s;
	printf("enter the size of string");
	scanf("%d",&i);
	s=(char *)malloc(i*sizeof(char));
	printf("\n enter the string");
	scanf("%s",s);
	stringcrunch(s);
	printf("%s",s);

}