#include<stdio.h>
#include<malloc.h>
struct index
{
	int count;
	char *word;
	char fname[30];
};
int size=1000;
int strcm(char *str,char *str1)
{
	int i=0;
	while(str[i]!='\0' && str1[i]!='\0')
	{
		if(str[i]!=str1[i])
			return 0;
		i++;
	}
	if(str[i]!='\0'|| str1[i]!='\0')
		return 0;
	return 1;
}
struct index* index1(struct index *a,FILE *fp,char *g,int *h,int *u)
{
	char ch,*s;
	int i=0,j,m,k=0,t;
	m=0;
	s=(char *)malloc(20*sizeof(char));
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		while((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z'))
		{
			s[m]=ch;
			ch=fgetc(fp);
			if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z'))
				m++;
			else
			{
				m++;
				s[m]='\0';
				t=*h;
				while(t<*u)
				{
					if((j=strcm(a[t].word,s))==1)
					{	
						a[t].count++;
						k=1;
						break;
					}
					t++;
				}
				if(k==0)
				{
					a[*u].count=1;
					a[*u].word=(char *)malloc((m+1)*sizeof(char));
					for(i=0;i<m;i++)
					a[*u].word[i]=s[i];
					a[*u].word[i]='\0';
					i=0;
					while(g[i]!='\0')
					{
						a[*u].fname[i]=g[i];
						i++;
					}a[*u].fname[i]='\0';
					(*u)++;
				}
				if(*u>size-1)
				{
					size=size+1000;
					a=(struct index*)realloc(a,size*sizeof(struct index));
				}
			}
		}j=0;
		m=0;
		k=0;
		ch=fgetc(fp);
	}
	*h=*u;
	i=0;
	/*while(i<u)
	{
	printf("\n %s %d %s",a[i].word,a[i].count,a[i].fname);
	i++;
	}*/
	return a;
}
void sort(struct index data[], int left, int right) 
{ 
int mid,i,j; 
struct index tmp;
i = left; 
j = right; 
mid = data[(left+right)/2].count; 
do 
{ 
	while (data[i].count > mid) 
i++; 
	while (mid > data[j].count) 
j--; 
if (i <= j) 
{ 
tmp = data[i]; 
data[i] = data[j]; 
data[j] = tmp; 
i++; 
j--; 
} 
} 
while (i <= j); 
{ 
if (left < j) 
sort(data,left,j); 
if (i < right) 
sort(data,i,right); 
} 
}
void serch(struct index *a,char *s,int *u)
{
	struct index b[884];
	int i=0,j=0,k=0;
	while(i<*u )
	{
		if((j=strcm(a[i].word,s))==1)
		{
			b[k]=a[i];
			k++;
		}
		i++;
	}i=0;
	sort(b,0,k-1);
	while(i<k)
	{
		printf("\n%s %s %d",b[i].word,b[i].fname,b[i].count);
		i++;
	}
}
void main()
{
	FILE *fp;
	struct index *a;
	char ch,b[885][30],*s;
	int i=0,j,n=0,h=0,u=0;
	a=(struct index*)malloc(1000*sizeof(struct index));
	s=(char*)malloc(30*sizeof(char));
	fp=fopen("ravi.txt","r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		while(ch!='\n'&& ch!=EOF)
		{
			s[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		if(ch=='\n')
		{
			for(j=0;j<i;j++)
				b[n][j]=s[j];
			b[n][j]='\0';
			n++;
		}i=0;
		ch=fgetc(fp);
	}
	fclose(fp);
	for(i=0;i<n;i++)
	{
	fp=fopen(b[i],"r");
	if(fp==NULL)
		printf("cannot open the fil");
	else
		a=index1(a,fp,b[i],&h,&u);
	fclose(fp);
	}	
	while(1)
	{
	printf("enter a serch string");
	scanf("%s",s);
	serch(a,s,&u);
	printf("y/n");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y')
		break;
	}
}