#include<stdio.h>
char * reverse(char *s,int i ,int j)
{
    char temp;
	j--;
    for (; i<j; i++, j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
	return s;
}
char * reversestring(char *s)
{
int i=0,j=0;
while(*(s+i)!='\0')
{
	if(*(s+i)==' ')
	{
		s=reverse(s,j,i);
		j=i+1;
	}
	i++;
}
s=reverse(s,j,i);
s=reverse(s,0,i);
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
 fflush(stdin);
scanf("%[^\n]s",s);
s=reversestring(s);
puts(s);
}