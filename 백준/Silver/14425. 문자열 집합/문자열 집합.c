#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Set
{
	char str[501];
}Set;

typedef struct Test
{
	char str[501];
}Test;

int search(Set* ary, char* ward, int size)
{
	int start = 0, end = size - 1;
	while (1)
	{
		int cen = (start + end) / 2;
		if (start > end)
		{
			break;
		}
		if (strcmp(ary[cen].str, ward) == 0)
		{
			return 1;
		}
		else if (strcmp(ary[cen].str, ward) > 0)
		{
			end = cen - 1;
		}
		else if (strcmp(ary[cen].str, ward) < 0)
		{
			start = cen + 1;
		}
	}
		return -1;
}

int compare(const void* num1, const void* num2)
{
	return strcmp((*(Set*)num1).str, (*(Set*)num2).str);
}

int main(void)
{
	int num = 0, num2 = 0, result =0;
	scanf("%d %d", &num, &num2);
	Set* word = (Set*)malloc(sizeof(Set) * num);
	Test* judge = (Test*)malloc(sizeof(Test) * num2);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", word[i].str);
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%s", judge[i].str);
	}
	qsort(word, num, sizeof(Set), compare);
	for (int i = 0; i < num2; i++)
	{
		int count = search(word, judge[i].str, num);
		if (count == 1)
		{
			result++;
		}
	}
	free(word);
	free(judge);
	printf("%d", result);
}