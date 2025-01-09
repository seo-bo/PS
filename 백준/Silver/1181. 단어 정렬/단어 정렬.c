#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct English
{
	char word[51];
}English;

int compare(const void* num1, const void* num2)
{
	if (strlen((*(English*)num1).word) == strlen((*(English*)num2).word))
	{
		return strcmp((*(English*)num1).word, (*(English*)num2).word);
	}
	else
	{
		return strlen((*(English*)num1).word) - strlen((*(English*)num2).word);
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	English* words = (English*)malloc(sizeof(English) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", &words[i].word);
	}
	qsort(words, num, sizeof(English), compare);
		for (int i = 0; i < num; i++)
		{
			if (i == 0)
			{
				printf("%s\n", words[i].word);
			}
			if (i > 0)
			{
				if (strcmp(words[i].word , words[i - 1].word) != 0)
				{
					printf("%s\n", words[i].word);
				}
			}
			
		}
		free(words);
}
