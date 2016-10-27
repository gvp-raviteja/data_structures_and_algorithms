#include<stdio.h>
void compliment(char *bin)
{
int i,count=0;
while(*bin!='1')
{
 bin++;
 count++;
}
bin++;
while(count<8)
{
if(*bin=='0')
  *bin='1';
else
 *bin='0';
bin++;
count++;
}
}
void dec2bin(int dec,char *bin)
{
int i, count=0;
if(dec>=0)
{
while(dec!=0)
{
if(dec%2==0)
*bin='0';
else
 *bin='1';

bin++;
dec=dec/2;
}
}
else
{
dec=-(dec);
while(dec!=0)
{
if(dec%2==0)
*bin='0';
else
 *bin='1';
bin++;
count++;
dec=dec/2;
}

for(i=count;i>0;i--)
bin--;
compliment(bin);
}
}
void main()
{
int dec,i;
char bin[8]={'0','0','0','0','0','0','0','0'};

printf("enter the value of dec");
scanf("%d",&dec);

dec2bin(dec,&bin[0]);
for(i=7;i>=0;i--)
printf("%c",bin[i]);
}
