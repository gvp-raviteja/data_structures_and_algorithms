#include<stdio.h>
#include<malloc.h>
void reverse(char *s)
{
	int i=0,l;
	char t;
	while(s[i])
	i++;
	l=i;
	for(i=0;i<=(l-1)/2;i++)   
	{
		t=s[i];
		s[i]=s[l-i-1];
		s[l-i-1]=t;
	}
}
char* convert(int count)
{
int i,j=0;
char *s=(char*)malloc(10*sizeof(char));
while(count /10 !=0)
{
	i=count%10;
	*(s+j)=i+'0';
	 j++;
	count=count/10;
}
*(s+j)=count+'0';
j++;
*(s+j)='\0';
reverse(s);
return s;
}
char* stringnum(char *s)
{
int count=1,i=0,j=1;
char *k;
while(*(s+i))
{
	if(*(s+i)==*(s+j))
	{
		count++;
		j++;
	}
	else
	{
		if(count!=1)
		{
			if(count<10)
			{
				*(s+i+1)=count+'0';
				i=i+2;
			}
			else
			{
				i++;
				k=convert(count);
				while(*k)
				{
					*(s+i)=*k;
					k++;
					i++;
				}
			}
		}
		else
		{
			i++;
		}
	*(s+i)=*(s+j);
	j++;
	count=1;
	}
}
return s;
}
void main()
{
char *s;
int n;
printf("\n enter the size of string");
scanf("%d",&n);
s=(char *)malloc(n*sizeof(char));
printf("\n enter the string");
scanf("%s",s);
s=stringnum(s);
printf("%s",s);
}