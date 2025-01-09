#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct English
{
	char word[11];
	int frequency;
}English;

int compareAlpha(const void* num1, const void* num2)
{
	English* a = (English*)num1;
	English* b = (English*)num2;

	return strcmp(a->word, b->word);
}

int compare(const void* num1, const void* num2)
{
	English* a = (English*)num1;
	English* b = (English*)num2;

	if (a->frequency != b->frequency)
	{
		return b->frequency - a->frequency;
	}
	if (strlen(a->word) != strlen(b->word))
	{
		return strlen(b->word) - strlen(a->word);
	}
	return strcmp(a->word, b->word);
}

int main(void)
{
	int num = 0, limit = 0, com = 0, count =0;
	scanf("%d %d", &num, &limit);
	English* word = (English*)malloc(sizeof(English) * num);
	for (int i = 0; i < num; i++)
	{
		char getword[11] = {0,};
		scanf("%s", getword);
		int size = strlen(getword);
		if (size >= limit)
		{
				strcpy(word[count].word, getword);
				word[count].frequency = 1;
				count++;
		}
	}
	qsort(word, count, sizeof(English), compareAlpha);
	for (int i = 1; i < count; i++)
	{
		if (strcmp(word[i].word, word[i - 1].word) == 0)
		{
			word[i].frequency = word[i - 1].frequency + 1;
			word[i - 1].frequency = 0;
		}
	}
	qsort(word, count, sizeof(English), compare);
	for (int i = 0; i < count; i++)
	{
		if (word[i].frequency > 0)
		{
			printf("%s\n", word[i].word);
		}
	}
	free(word);
}

