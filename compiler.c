#include<stdio.h>
// this method removes spaces and also rejects the input if there is space between 2 digits
int spac(char *a)
{
int i=0,n=0,j=0,k=0;
while(a[i]!='\0')
{
	if((a[i]>='0') && (a[i]<='9'))
	{
		j=i+1;
		while(a[j]==' ' )
			{k=1;
			j++;}
		if(((a[j]>='0') && (a[j]<='9')) && k==1)
			return 1;
	}
if(a[i]!=' ')
{
a[n++]=a[i];
}
i++;
}
a[n]='\0';
return 0;
//printf("%s",a);
}
//compares str and str1,  return 1 if EQUAL, else return 0
int strcm(char *str,char *str1)
{
	int i=0;
	while(str[i]!='\0' && str1[i]!='\0')
	{
		if(str[i]!=str1[i])
			return 0;
		i++;
	}
	if(str[i]!='\0')
		return 0;
	return 1;
}
//converts the string to digit
int conv(char *str)
{
	int i=0;
	while((*str>='0') && (*str<='9'))
	{
       i=i*10;
		i=i + *str-'0';
		str++;
	}
	return i;
}
int add(int n,char *str,int a[],int b[],int *fla)
{
	if((*str>='a') && (*str<='z'))
	{
		if(b[*str-'a']==1)
		{
		  n=n+a[*str-'a'];
		  return n;
		}
		else
		{
			printf(" %c is unintilized",*str);
			*fla=1;
			return 0;
		}
	}
	n=n+conv(str);
	return n;
}
int sub(int n,char *str,int a[] ,int b[],int *fla)
{
	if((*str>='a') && (*str<='z'))
	{
		if(b[*str-'a']==1)
		{
			 //printf("\n value of %c is:%d",*str,a[*str-'a'].value);
		  n=n-a[*str-'a'];
		  return n;
		}
		else
		{
			printf(" %c is unintilized",*str);
			*fla=1;
			return 0;
		}
	}
	n=n-conv(str);
	return n;
}
int mul(int n,char *str,int a[],int b[],int *fla)
{
	if((*str>='a') && (*str<='z'))
	{
		if(b[*str-'a']==1)
		{
			 //printf("\n value of %c is:%d",*str,a[*str-'a'].value);
		  n=n*a[*str-'a'];
		  return n;
		}
		else
		{
			printf(" %c is unintilized",*str);
			*fla=1;
			return 0;
		}
	}
	n=n*conv(str);
	return n;
}
int div(int n,char *str,int a[],int b[],int *fla)
{
	if((*str>='a') && (*str<='z'))
	{
		if(b[*str-'a']==1 && a[*str-'a']!=0 )
		{
		   //printf("\n value of %c is:%d",*str,a[*str-'a'].value);
			n=n/a[*str-'a'];
		  return n;
		}
		else if(a[*str-'a']==0 )
		{
			printf("error:divide by zero");
			*fla=1;
			return 0;
		}
		else
		{
			printf(" %c is unintilized",*str);
			*fla=1;
			return 0;
		}
	}
	if(conv(str)==0)
	{
		printf("error:divide by zero");
			*fla=1;
			return 0;
	}
	n=n/conv(str);
	return n;
}
// returns the value after performing +,-,* or / between operands in the RHS
// also recognizes the uninitialized variables.
int num(char *str,int a[],int b[],int *fla)
 {
	 int n;
	 n=0;
	 while(*str!='\0')
	 {
		 if((*str>='0') && (*str<='9'))
		 {
			 n=conv(str);
			 while((*str>='0') && (*str<='9'))
				 str++;
		 }
		 else if(!((*str>='0') && (*str<='9')) && !((*str>='a') && (*str<='z')))
		 {
			 if(*str=='+')
			 {str++;
			 n=add(n,str,a,b,fla);}
			 else if(*str=='-')
				  {str++;
			 n=sub(n,str,a,b,fla);}
			 else if(*str=='*')
				   {str++;
			 n=mul(n,str,a,b,fla);}
			  else
				    {str++;
			 n=div(n,str,a,b,fla);}
			 if((*str>='a') && (*str<='z'))
				 str++;
			 else if((*str>='0') && (*str<='9'))
			 {
				  while((*str>='0') && (*str<='9'))
						str++;
			 }
		 }
		 else if((*str>='a') && (*str<='z'))
		 {
			 if(b[*str-'a']==1)
			 {
				// printf("value of %c is:%d",*str,a[*str-'a'].value);
				 n=a[*str-'a'];
				 str++;
			 }
			 else{
				 printf("%c is unintialized",*str);
				 *fla=1;
				 return  0;
			 }

		 }
	 }
	 return n;
}
//getvar and search methods are used to print the values of variables present in the expression.
//array c[] is taken to make sure that no variable is printed twice in the output.
int search(char *str,char *c)
{
	int i=0;
	while(c[i]!='\0')
	{
		if(*str==c[i])
			return 0;
		i++;
	}
	return 1;
}
void getvar(char *str,int a[])
{
	char c[27];
	int i=0,p=0;
		c[0]='\0';
	while(*str!='\0')
	{
		if((*str>='a') && (*str<='z'))
		{
			p=search(str,c);
			if(p==1)
			{
				printf("\n value of %c is:%d",*str,a[*str-'a']);
				c[i]=*str;
				c[++i]='\0';
			}
		}
		str++;
	}
}
//variable in the LHS is assigned a value after computing the RHS
void compute(char *str,int a[],int b[],int *fla)
{	
	a[str[0]-'a']=num(&str[2],a,b,fla);
		if(*fla==0 )
		{
		b[str[0]-'a']=1;
			getvar(str,a);
		}
		else
		{
			printf(" invalid");
			*fla=0;
		}
}
// valid and ivalid methods are used to recognize whether the give string is in valid format or not
int ivalid(char *str)
{
	int i=0;
	if(str[i]=='*'|| str[i]=='/')
		return 0;
	while(str[i]!='\0')
	{	
		if(str[i]>='0' && str[i]<='9')
		{
			i++;
			while(str[i]>='0' && str[i]<='9')
				i++;
			if(str[i]>='a'&& str[i]<='z')
				return 0;
			if(str[i]=='\0')
				return 1;
		}
		else if(str[i]>='a'&& str[i]<='z')
		{
			i++;
			if(str[i]=='\0')
				return 1;
			if((str[i]>='0' && str[i]<='9')||(str[i]>='a'&& str[i]<='z'))
				return 0;
		}
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*'|| str[i]=='/')
		{
			i++;
			if(str[i]=='\0')
				return 0;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
int valid(char *str)
{
	int j=0;
	if(str[0]>='a'&& str[0]<='z' && (str[1]=='='))
	{
		j=ivalid(&str[2]);
	}
	return j;
}
void main()
{
int *fla;
char *str;
int a[26],b[26];
int i=0,k=0;
fla=(int *)malloc(sizeof(int));
str=(char*)malloc(sizeof(char));
*fla=0;
while(k==0)
{
	printf("\n enter the input");
	fflush(stdin);
	scanf(" %[^\n]s",str);
	k=spac(str);
	if(k==1)
	{
		printf("invalid");
		k=0;
		continue;
	}
	k=strcm(str,"exit");
	if(k==1)
		break;
	i=valid(str);
	if(i==0)
		printf("invalid");
	else
	compute(str,a,b,fla);
}
}