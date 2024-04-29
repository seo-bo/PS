#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word
{
	char str[1001];
}Word;

char ary[1001] = { 0, };

int compare(const void* num1, const void* num2)
{
	return strcmp((*(Word*)num1).str, (*(Word*)num2).str);
}

int main(void)
{
	scanf("%s", ary);
	int size = strlen(ary);
	Word* getword = (Word*)malloc(sizeof(Word) * size);
	for (int i = 0; i < size; i++)
	{
		strcpy(getword[i].str, ary + i);
	}
	qsort(getword, size, sizeof(Word), compare);

	for (int i = 0; i < size; i++)
	{
		printf("%s\n", getword[i].str);
	}
}
