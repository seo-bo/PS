#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct CV
{
	char minsik[101];
	char con[101];
}CV;

char minA[22] = "abkdeghilmnoprstuwy";
char engA[22] = "abcdefghijkmnopqrst";

int compare(const void* num1, const void* num2)
{
	return strcmp(((CV*)num1)->con, ((CV*)num2)->con);
}

void convert(CV* word, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (word->minsik[i] == 'n' && word->minsik[i + 1] == 'g')
		{
			word->con[j] = 'l';
			i++;
		}
		else
		{
			char* pos = strchr(minA, word->minsik[i]);
			int index = pos - minA;
			word->con[j] = engA[index];
		}
		j++;
	}
	word->con[j] = '\0';
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	CV* word = (CV*)malloc(sizeof(CV) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", word[i].minsik);
		getchar();
		int size = strlen(word[i].minsik);
		convert(&word[i],size);
	}
	qsort(word, num, sizeof(CV), compare);
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", word[i].minsik);
	}
	free(word);
}
