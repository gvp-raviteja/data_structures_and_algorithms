#include<stdio.h>
void lshift(int *s,int n,int i)
{
	int k,temp,j;
 	if(n<0)return;
	n=n%i;
	for(k=0;k<n;k++)
	{
		temp=s[0];
		for(j=1;j<i;j++)
		{
			s[j-1]=s[j];
		}
		s[j-1]=temp;
	}
}
void main()
{
int n,*s,i;
printf("enter size of array");
scanf("%d",&n);
s=(int *)malloc(n*sizeof(int));
printf("enter array");
for(i=0;i<n;i++)
scanf("%d",&s[i]);
lshift(s,10,n);
for(i=0;i<n;i++)
printf("%d",s[i]);
getch();
}