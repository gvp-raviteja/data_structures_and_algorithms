#include<stdio.h>
#include<malloc.h>
void vowels(char *d)
{
	int i=0,j=0;
	while(*d!='\0')
	{
		if(*d=='a' || *d=='e' || *d=='i' || *d=='o' || *d=='u' || *d=='A'|| *d=='E'|| *d=='I'|| *d=='O'|| *d=='U')
			i++;
		else if((*d>'a' && *d<='z') || (*d>'A' && *d<='Z'))
			j++;
		d++;
	}
printf("no of vowels in the string %d \n",i);
printf("no of consonants in the string %d",j);

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
	vowels(d);
}