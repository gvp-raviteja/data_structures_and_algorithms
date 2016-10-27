#include<stdio.h>
#include<malloc.h>
void rmvspaces(char *s)
{
	int i=0,j,k=0;
	while(s[i]!=' ' && s[i]!='\0')
		i++;
	j=i;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			i++;
		}
		else
		{
		s[j]=s[i];
		j++;
		i++;
		}
	}
	s[j]='\0';
}
void main()
{
char *string;
int n;
printf("\n enter the size of string");
scanf("%d",&n);
string=(char *)malloc((n+1)*sizeof(char));
printf("enter the string");
fflush(stdin);
scanf("%[^\n]s",string);
rmvspaces(string);
printf("%s",string);
}