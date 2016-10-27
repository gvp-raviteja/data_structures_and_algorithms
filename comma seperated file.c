#include<stdio.h>
void disply(FILE *fp)
{
	char ch='a';
	int a[10],i=0,j=0;
	while((ch=fgetc(fp))!='\n')
	{
		if(ch==',')
		{
			a[i]=j;
			i++;
			j=0;
		}
		else
		{
			j++;
		}
	}
	a[i]=j;
	i=0;j=0;
	ch=fgetc(fp);
	while(1)
	{
		if(ch!='\n' && ch !=EOF)
		{
			if(ch==',')
			{
				if(a[i]<j)
					a[i]=j;
				j=0;
				i++;
			}
			else
				j++;
		}
		if(a[i]<j)
			a[i]=j;
		if(ch=='\n')
		{
		i=0;
		j=0;
		}
		if(ch==EOF)
			break;
		ch=fgetc(fp);
	}
	i=0;j=0;
	rewind(fp);
	ch=fgetc(fp);
	while(1)
	{
		if(ch!='\n' && ch !=EOF)
		{
			if(ch==',')
			{
				if(a[i]>j)
				{
					j=a[i]-j;
					while(j!=0)
					{
						printf(" ");
						j--;
					}
				}
				printf(" ");
				j=0;
				i++;
			}
			else
			{
				printf("%c",ch);
				j++;
			}
		}
		else if(ch=='\n')
		{
			printf("\n");
			i=0;
			j=0;
		}		
		if(ch==EOF)
			break;
		ch=fgetc(fp);
	} 
}
void main()
{
	FILE *fp;
	fp=fopen("ravi.txt","r");
	disply(fp);
	fclose ( fp ) ;
} 