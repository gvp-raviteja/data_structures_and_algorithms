#include<stdio.h>
#include<malloc.h>
struct index
{
	long int i;
	char s[10];
};
int m=0;
int getint(char ch)
{
	if(ch=='a' || ch=='b' || ch=='c')
		return 2;
	else if( ch=='d' || ch=='e' || ch=='f')
		return 3;
	else if( ch=='g' || ch=='h' || ch=='i')
		return 4;
	else if( ch=='j' || ch=='k' || ch=='l')
		return 5;
	else if( ch=='m' || ch=='n' || ch=='o')
		return 6;
	else if( ch=='p' || ch=='q' || ch=='r' ||ch=='s')
		return 7;
	else if( ch=='t' || ch=='u' || ch=='v')
		return 8;
	else if( ch=='w' || ch=='x' || ch=='y' ||ch=='z')
		return 9;
	else
		return 0;
}
struct index* index1(FILE *fp,struct index *a)
{
	char ch,*s;
	int i,j,k,n,size=1000;
	a=(struct index*)malloc(1000*sizeof(struct index));
	s=(char *)malloc(10*sizeof(char));
	i=7;k=0;n=0;
	ch=fgetc(fp);
	printf("%c",ch);
	while(ch!=EOF)
	{
		while(ch!='\n'&& ch!=EOF)
		{
			j=getint(ch);
			k=k*10+j;
			s[n]=ch;
			n++;
			ch=fgetc(fp);
		}
		if(ch=='\n')
		{
		a[m].i=k;
		for(i=0;i<n;i++)
		a[m].s[i]=s[i];
		a[m].s[i]='\0';
		m++;
		}
		n=0;		i=7;
		k=0;
		if(m>size-1)
		{
			size=size+1000;
			a=(struct index*)realloc(a,size*sizeof(struct index));
		}
		ch=fgetc(fp);
	}
	return a;
}
void sort(struct index data[], int left, int right) 
{ 
int mid,i,j; 
struct index tmp;
i = left; 
j = right; 
mid = data[(left+right)/2].i; 
do 
{ 
	while (data[i].i < mid) 
i++; 
	while (mid < data[j].i) 
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
void search(struct index *a, int i, int n)
{
	char c;
	int j,k,l;
	for(j=0;j<m;j++)
	{
		if(a[j].i==i) break;
		if(a[j].i>i && a[j].i<n) break;
	}
	k=j;
	for(;j<m;j++)
		if(a[j].i>=n)break;
	for(l=k;l<j;l++)
		printf("\n %d %s",a[l].i,a[l].s);
	printf("\n do you want to display more numbers");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y')
	{
		if(i<10000000)
		search(a,i*10,n*10);
	}
}
void main()
{
	struct index *a;
	FILE *fp;
	int i;
	a=NULL;
	fp=fopen("dictionary.txt","r");
	if(fp==NULL)
		printf("cannot open file");
	else printf("file opened");
	a=index1(fp,a);
	printf("%d",m);
	fclose(fp);
	sort(a,0,m);
	printf("enter the search number");
	scanf("%d",&i);
	search(a,i,i+1);
}