#include<stdio.h>
char* rev(char *str,char *str1)
{
	char ch;
	if(*(str)!='\0')
	{
		ch=*str;
		str1=rev(str+1,str1);
		*str1=ch;
		str1++;
	}
		return str1;
}
int main()
{
char *s=(char *)malloc(10*sizeof(char));
char *t;
printf("\n enter the string");
scanf("%s",s);
t=rev(s,s);
printf("%s",s);
return 0;
}