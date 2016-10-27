 // tries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>

struct trie
{
	char character;
	struct trie *next[26];
	bool end_mark;
};
 
struct trie * initialize(struct trie *root)
{
	root=(struct trie *)malloc(sizeof(struct trie));
	root->character=NULL;
	root->end_mark=false;
	int i=0;
	while(i<26)
	{
		root->next[i]=NULL;
		i++;
	}
	return root;
}

2

void insert_to_trie(char *str,struct trie *root)
{
	int i=*str-'a';
	if(*str!=NULL && *str!='\n' && *str!=EOF)
	{
		if(root->next[i]==NULL)
		{
			root->next[i]=initialize(root->next[i]);
			root->next[i]->character=*str;

		}
		insert_to_trie(++str,root->next[i]);

	}
	else
	{
		if(root->character!=NULL)
			root->end_mark=true;
	}
}

int search(char *str,struct trie *root)
{
	int i;
	while(*str!=NULL)
	{
		i=*str-'a';
		if(root->next[i]==NULL)
			return 0;
		root=root->next[i];
		str++;
	}
	if(root->end_mark==true)
		return 1;
	return 0;
}

void indexing(FILE *fp,struct trie *root)
{
	char *str=(char *)malloc(15*sizeof(char));
	fgets(str,15,fp);
	while(*str!='0')
	{
		insert_to_trie(str,root);
		fgets(str,15,fp);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct trie *root=(struct trie *)malloc(sizeof(struct trie));
	char *str;
	int i;
	FILE *fp=fopen("dictionary_words.txt","r+");
	root=initialize(root);
	indexing(fp,root);
	//insert_to_trie(str,root);
	printf("enter the lenght of word");
	scanf("%d",&i);
	str=(char *)malloc(i*sizeof(char));
	printf("\n enter the word to search in dictionary");
	scanf("%s",str);
	i=search(str,root);
	if(i==0)
		printf("word not found in dictionary");
	else
		printf("word is present in dictionary");
	return 0;
}

