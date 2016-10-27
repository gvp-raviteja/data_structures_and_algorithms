// message_buffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include "string.h"

struct offsets
{
int offset;
int metadata_offset;
int data_offset;
int metadata_id;
int user_id;
};

struct metadata
{
	int id;
	int user_id;
	int datat_ptr;
	int length;
	int level_ptr;
	int next_ptr;
};

void frite(char *str,int i,int j,FILE *fp)
{
	while(j>0)
	{
	fputc(*str,fp);
	str++;
	j--;
	}
}

void f_read(char *str,int i,int j,FILE *fp)
{
	while(i>0)
	{
	*str=fgetc(fp);
	i--;
	str++;
	}
}

char string(int i)
{
	char c;
	if(0<=i && i<=9)
	{
		c='0'+i;
		return c;
	}
	else if(10<=i && i<=16)
	{
		c='a'+i-10;
		return c;
	}
}

int len(char *str)
{
	int i=0;
	while(*str)
	{
		i++;
		str++;
	}
	return i;
}

char * int_to_str(int i)
{
	int j=i&255,k=3;
	char *s=(char *)malloc(5*sizeof(char));
	s[4]='\0';
	while(k>=0)
	{
	s[k]=(char)j;
	i=i>>8;
	k--;
	j=i&255;
	}
	return s;
}

int str_to_int(char *s)
{
	int i=0;
	int k=0;
	while(k<3)
	{
		if(s[k]<0)
		{
			i=i+256+s[k];
		}
		else
		i+=s[k];
		i=i<<8;
		k++;
	}
	if(s[k]<0)
		{
			i=i+256+s[k];
		}
	else
	i+=s[k];
	return i;
}

char * padding(char *s,int i)
{
	int j=0;
	while(s[j]!='\0')
		j++;
	while(j<i)
	{
		s[j]=' ';
		j++;
	}
	s[j]='\0';
	return s;
}

void startup(FILE *fp,struct offsets obj)
{
	char *str;
	fseek(fp,1024,SEEK_SET);
	obj.offset=2048;
	str=int_to_str(obj.offset);
	frite(str,sizeof(char),4,fp);
	obj.metadata_offset=4096;
	str=int_to_str(obj.metadata_offset);
	frite(str,sizeof(char),4,fp);
	obj.data_offset=1000000;
	str=int_to_str(obj.data_offset);
	frite(str,sizeof(char),4,fp);
	obj.metadata_id=0;
	str=int_to_str(obj.metadata_id);
	frite(str,sizeof(char),4,fp);
	obj.user_id=0;
	str=int_to_str(obj.user_id);
	frite(str,sizeof(char),4,fp);
}

struct offsets begin(FILE *fp,struct offsets obj)
{
	char *str=(char *) malloc(42*sizeof(char));
	fseek(fp,1024,SEEK_SET);
	f_read(str,20,sizeof(char),fp);
	obj.offset=str_to_int(&str[0]);
	obj.metadata_offset=str_to_int(&str[4]);
	obj.data_offset=str_to_int(&str[8]);
	obj.metadata_id=str_to_int(&str[12]);
	obj.user_id=str_to_int(&str[16]);
	return obj;
}

void  category(FILE *fp,struct offsets obj)
{
	char *str=(char *)malloc(20*sizeof(char));
	char cat[]="bondy0";
	int i=0,j,offseek=obj.offset;
	char **s=(char **)malloc(6*sizeof(char));
	for(i=0;i<6;i++)
	{
		s[i]=(char*)malloc(22*sizeof(char));
	}
	printf("enter 6 category names:");
	for(i=0;i<6;i++)
	{
		cat[5]=string(i);
		strcpy(s[i],cat);
	}
	for(i=0;i<6;i++)
	{
		fseek(fp,offseek,SEEK_SET);
		*str=(i+1);
		frite(str,sizeof(char),1,fp);
		s[i]=padding(s[i],15);
		frite(s[i],sizeof(char),15,fp);
		str=int_to_str(1);
		frite(str,sizeof(char),4,fp);
		offseek=offseek+20;
	}
	//i=str_to_int(str);
	cat[6]='\0';
	//printf("%d %s",i,str);
	//printf("%d",obj.offset);
}

char * strconcat(char *s, char *t,int i,int j)
{
	int k=0;
	s=(char *)realloc(s,(i+j+1)*sizeof(char));
	while(k<j)
	{
		s[i]=t[k];
		k++;
		i++;
	}
	s[i]='\0';
	return s;
}

struct offsets create_forums(char *forum_name,int cat_id,FILE *fp,struct offsets obj)
{
	char *str=(char *)malloc(25*sizeof(char));
	char *s;
	int offseek=obj.offset,i=0,j,k;
	fseek(fp,offseek,SEEK_SET);
	while(i<6)
	{
		fseek(fp,offseek+i*20,SEEK_SET);
		f_read(str,20,sizeof(char),fp);
		str[20]='\0';
		//printf("%s",str);
		if(cat_id==str[0]-0)
		{
			j=str_to_int(&str[16]);
			fseek(fp,-4,SEEK_CUR);
			s=int_to_str(obj.metadata_offset);
			frite(s,sizeof(char),4,fp);
			fseek(fp,obj.metadata_offset,SEEK_SET);
			obj.metadata_offset+=24;
			s=int_to_str(obj.metadata_id);
			s=strconcat(s,int_to_str(obj.user_id),4,4);
			s=strconcat(s,int_to_str(obj.data_offset),8,4);
			k=len(forum_name);
			s=strconcat(s,int_to_str(k),12,4);
			s=strconcat(s,int_to_str(j),16,4);
			s=strconcat(s,int_to_str(1),20,4);
			frite(s,sizeof(char),24,fp);
			fseek(fp,obj.data_offset,SEEK_SET);
			frite(forum_name,sizeof(char),k,fp);
			obj.data_offset+=k;
			fseek(fp,1024+4,SEEK_SET);
			s=int_to_str(obj.metadata_offset);
			s=strconcat(s,int_to_str(obj.data_offset),4,4);
			s=strconcat(s,int_to_str(++obj.metadata_id),8,4);
			frite(s,sizeof(char),12,fp);
			return obj;
		}
		i++;
	}
	return obj;
}

void get_forums(int cat_id,FILE *fp,struct offsets obj)
{
	int i=0,j;
	int data_address,data_length;
	char *str=(char *)malloc(49*sizeof(char)),*str1;
	while(i<6)
	{
		fseek(fp,obj.offset+i*20,SEEK_SET);
		f_read(str,20,sizeof(char),fp);
		str[20]='\0';
		if(cat_id==str[0]-0)
		{
			j=str_to_int(&str[16]);
			while(j!=1)
			{
				fseek(fp,j,SEEK_SET);
				f_read(str,24,sizeof(char),fp);
				printf("%d ",str_to_int(&str[0]));
				data_address=str_to_int(&str[8]);
				data_length=str_to_int(&str[12]);
				fseek(fp,data_address,SEEK_SET);
				str1=(char*)malloc((data_length+2)*sizeof(char));
				f_read(str1,data_length,sizeof(char),fp);
				str1[data_length]='\0';
				printf("%s \n",str1);
				j=str_to_int(&str[16]);
			}
			printf("end of forums");
			return ;
		}
		i++;
	}
	printf("invalid category");
}

void print(char *s)
{
	int i=0;
	while(i<6)
	{
		printf("\n %d",str_to_int(&s[i*4]));
		i++;
	}
}

struct offsets add_questions(char *question,int cat_id,int forum_id,FILE *fp,struct offsets obj)
{
	int i=0,j,k;
	int data_address,data_length;
	char *str=(char *)malloc(49*sizeof(char)),*s,*string;
	while(i<6)
	{
		fseek(fp,obj.offset+i*20,SEEK_SET);
		f_read(str,20,sizeof(char),fp);
		str[20]='\0';
		if(cat_id==str[0]-0)
		{
			j=str_to_int(&str[16]);
			while(j!=1)
			{
				fseek(fp,j,SEEK_SET);
				f_read(str,24,sizeof(char),fp);
				if(forum_id==str_to_int(&str[0]))
				{
					j=str_to_int(&str[20]);
					fseek(fp,-4,SEEK_CUR);
					s=int_to_str(obj.metadata_offset);
					frite(s,sizeof(char),4,fp);
					fseek(fp,obj.metadata_offset,SEEK_SET);
					obj.metadata_offset+=24;
					s=int_to_str(obj.metadata_id);
					s=strconcat(s,int_to_str(obj.user_id),4,4);
					s=strconcat(s,int_to_str(obj.data_offset),8,4);
					k=len(question);
					s=strconcat(s,int_to_str(k),12,4);
					s=strconcat(s,int_to_str(j),16,4);
					s=strconcat(s,int_to_str(1),20,4);
					frite(s,sizeof(char),24,fp);
					fseek(fp,obj.data_offset,SEEK_SET);
					frite(question,sizeof(char),k,fp);
					obj.data_offset+=k;
					fseek(fp,1024+4,SEEK_SET);
					s=int_to_str(obj.metadata_offset);
					s=strconcat(s,int_to_str(obj.data_offset),4,4);
					s=strconcat(s,int_to_str(++obj.metadata_id),8,4);
					frite(s,sizeof(char),12,fp);
					return obj;
				}
				j=str_to_int(&str[16]);
			}
			printf("invalid forums");
			return obj;
		}
		i++;
	}
	printf("invalid category");
}

void get_questions(int cat_id,int forum_id,FILE *fp,struct offsets obj)
{
	int i=0,j;
	int data_address,data_length;
	char *str=(char *)malloc(49*sizeof(char)),*str1;
	while(i<6)
	{
		fseek(fp,obj.offset+i*20,SEEK_SET);
		f_read(str,20,sizeof(char),fp);
		str[20]='\0';
		if(cat_id==str[0]-0)
		{
			j=str_to_int(&str[16]);
			while(j!=1)
			{
				fseek(fp,j,SEEK_SET);
				f_read(str,24,sizeof(char),fp);
				if(forum_id==str_to_int(&str[0]))
				{
					j=str_to_int(&str[20]);
					while(j!=1)
					{
						fseek(fp,j,SEEK_SET);
						f_read(str,24,sizeof(char),fp);
						data_address=str_to_int(&str[8]);
						data_length=str_to_int(&str[12]);
						fseek(fp,data_address,SEEK_SET);
						str1=(char*)malloc((data_length+2)*sizeof(char));
						f_read(str1,data_length,sizeof(char),fp);
						str1[data_length]='\0';
						printf("%d : %s \n",str_to_int(&str[0]),str1);
						j=str_to_int(&str[16]);
					}
					printf("\n end of questions");
					return;
				}
				j=str_to_int(&str[16]);
			}
			printf("end of forums");
			return ;
		}
		i++;
	}
	printf("invalid category");
}

struct offsets add_answers(char *answer,int cat_id,int forum_id,int quesn_id,FILE *fp,struct offsets obj)
{
		int i=0,j,k;
	int data_address,data_length;
	char *str=(char *)malloc(49*sizeof(char)),*s,*string;
	while(i<6)
	{
		fseek(fp,obj.offset+i*20,SEEK_SET);
		f_read(str,20,sizeof(char),fp);
		str[20]='\0';
		if(cat_id==str[0]-0)
		{
			j=str_to_int(&str[16]);
			while(j!=1)
			{
				fseek(fp,j,SEEK_SET);
				f_read(str,24,sizeof(char),fp);
				if(forum_id==str_to_int(&str[0]))
				{
					j=str_to_int(&str[20]);
					while(j!=1)
					{
						fseek(fp,j,SEEK_SET);
						f_read(str,24,sizeof(char),fp);
						if(quesn_id==str_to_int(&str[0]))
						{
							j=str_to_int(&str[20]);
							fseek(fp,-4,SEEK_CUR);
							s=int_to_str(obj.metadata_offset);
							frite(s,sizeof(char),4,fp);
							fseek(fp,obj.metadata_offset,SEEK_SET);
							obj.metadata_offset+=24;
							s=int_to_str(obj.metadata_id);
							s=strconcat(s,int_to_str(obj.user_id),4,4);
							s=strconcat(s,int_to_str(obj.data_offset),8,4);
							k=len(answer);
							s=strconcat(s,int_to_str(k),12,4);
							s=strconcat(s,int_to_str(j),16,4);
							s=strconcat(s,int_to_str(1),20,4);
							frite(s,sizeof(char),24,fp);
							fseek(fp,obj.data_offset,SEEK_SET);
							frite(answer,sizeof(char),k,fp);
							obj.data_offset+=k;
							fseek(fp,1024+4,SEEK_SET);
							s=int_to_str(obj.metadata_offset);
							s=strconcat(s,int_to_str(obj.data_offset),4,4);
							s=strconcat(s,int_to_str(++obj.metadata_id),8,4);
							frite(s,sizeof(char),12,fp);
							return obj;
						}
						j=str_to_int(&str[16]);
					}
					printf("invalid question id");
					return obj;
				}
				j=str_to_int(&str[16]);
			}
			printf("invalid forum id");
			return obj;
		}
		i++;
	}
	printf("invalid category id");


}

void get_answers(int cat_id,int forum_id,int quesn_id,FILE *fp,struct offsets obj)
{
	int i=0,j;
	int data_address,data_length;
	char *str=(char *)malloc(49*sizeof(char)),*str1;
	while(i<6)
	{
		fseek(fp,obj.offset+i*20,SEEK_SET);
		f_read(str,20,sizeof(char),fp);
		str[20]='\0';
		if(cat_id==str[0]-0)
		{
			j=str_to_int(&str[16]);
			while(j!=1)
			{
				fseek(fp,j,SEEK_SET);
				f_read(str,24,sizeof(char),fp);
				if(forum_id==str_to_int(&str[0]))
				{
					j=str_to_int(&str[20]);
					while(j!=1)
					{
						fseek(fp,j,SEEK_SET);
						f_read(str,24,sizeof(char),fp);
						if(quesn_id==str_to_int(&str[0]))
						{
							j=str_to_int(&str[20]);
							while(j!=1)
							{
							fseek(fp,j,SEEK_SET);
							f_read(str,24,sizeof(char),fp);
							data_address=str_to_int(&str[8]);
							data_length=str_to_int(&str[12]);
							fseek(fp,data_address,SEEK_SET);
							str1=(char*)malloc((data_length+2)*sizeof(char));
							f_read(str1,data_length,sizeof(char),fp);
							str1[data_length]='\0';
							printf("%d : %s \n",str_to_int(&str[0]),str1);
							j=str_to_int(&str[16]);
							}
							printf("\n  end of answers");
							return;
						}						
						j=str_to_int(&str[16]);
					}
					printf("\n no answers");
					return;
				}
				j=str_to_int(&str[16]);
			}
			printf("end such question");
			return ;
		}
		i++;
	}
	printf("invalid category");
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	int i;
	struct offsets obj;
	char str[]="bondy007",str1[]="are you crazy1???";
	obj.data_offset=obj.metadata_id=obj.metadata_offset=obj.offset=obj.user_id=0;
	fp=fopen("ravi.txt","r+b");
	//startup(fp,obj);
	obj=begin(fp,obj);
	fseek(fp,0,0);
	/*category(fp,obj);
	obj=create_forums(str,3,fp,obj);
	str[6]='5';
	obj=create_forums(str,3,fp,obj);
	str[6]='6';
	obj=create_forums(str,3,fp,obj);
	str[6]='7';
	obj=create_forums(str,2,fp,obj);
	str[6]='8';
	obj=create_forums(str,5,fp,obj);*/
	get_forums(3,fp,obj);
	get_forums(2,fp,obj);
	get_forums(5,fp,obj);
	/*obj=add_questions(str1,3,0,fp,obj);
	get_questions(3,0,fp,obj);
	for(i=0;i<100;i++)
		obj=add_questions(str,3,0,fp,obj);
	for(i=0;i<100;i++)
		obj=add_questions(str,5,4,fp,obj);
	obj=add_questions(str,3,1,fp,obj);
	obj=add_questions(str,3,1,fp,obj);*/
	get_questions(3,1,fp,obj);
	get_questions(5,4,fp,obj);
	/*obj=add_answers(str,3,1,10,fp,obj);
	for(i=0;i<100;i++)
		obj=add_answers(str,5,4,197,fp,obj);*/
	get_answers(3,1,10,fp,obj);
	get_answers(5,4,197,fp,obj);
	return 0;
}

