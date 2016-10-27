#include<stdio.h>
#include<malloc.h>
char num(char ch)
{
	if(ch=='a' || ch=='b' || ch=='c' || ch=='A' || ch=='B' || ch=='C')
		return '2';
	else if( ch=='d' || ch=='e' || ch=='f' || ch=='D' || ch=='E' || ch=='F')
		return '3';
	else if( ch=='g' || ch=='h' || ch=='i' || ch=='G' || ch=='H' || ch=='I')
		return '4';
	else if( ch=='j' || ch=='k' || ch=='l' || ch=='J' || ch=='K' || ch=='L')
		return '5';
	else if( ch=='m' || ch=='n' || ch=='o' || ch=='N' || ch=='M' || ch=='O')
		return '6';
	else if( ch=='p' || ch=='q' || ch=='r' ||ch=='s' || ch=='P' || ch=='Q' || ch=='R' || ch=='S')
		return '7';
	else if( ch=='t' || ch=='u' || ch=='v' || ch=='T' || ch=='U' || ch=='V')
		return '8';
	else if( ch=='w' || ch=='x' || ch=='y' ||ch=='z' || ch=='W' || ch=='X' || ch=='Y' || ch=='Z')
		return '9';
	else if(ch==' ')
		return '0';
	else
		return '1';
}
void digits(char *d)
{
	int k=0;
	while(d[k]!='\0')
	{
		if(d[k]<'0' || d[k]>'9') 
		{
			d[k]=num(d[k]);
		}
		k++;
	}
}
void main()
{
	int i;
	char *d;
	printf("\n enter the size of string");
	scanf("%d",&i);
	d=(char*)malloc((i+1)*sizeof(char));
	printf("\n enter the string");
	scanf("%s",d);
	digits(d);
	printf("\n NUMERIC KEYPAD VALUE: %s",d);
}