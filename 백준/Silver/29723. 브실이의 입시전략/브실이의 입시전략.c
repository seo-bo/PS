#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Grade
{
	char name[21];
	int score;
}Grade;

int search(Grade* ary, char* key, int size)
{
	int start = 0, end = size - 1, result = 0;
	while (start <= end)
	{
		int cen = (start + end) / 2;
		if (strcmp(ary[cen].name, key) == 0)
		{
			result = ary[cen].score;
			ary[cen].score = 0;
			return result;
		}
		else if (strcmp(ary[cen].name, key) > 0)
		{
			end = cen - 1;
		}
		else if (strcmp(ary[cen].name, key) < 0)
		{
			start = cen + 1;
		}
	}
	return 0;
}
int icompare(const void* num1, const void* num2)
{
	return ((Grade*)num2)->score - ((Grade*)num1)->score;
}

int scompare(const void* num1, const void* num2)
{
	return strcmp(((Grade*)num1)->name, ((Grade*)num2)->name);
}

int main(void)
{
	int num = 0, want = 0, open = 0, get = 0;
	scanf("%d %d %d", &num, &want, &open);
	Grade* ary = (Grade*)malloc(sizeof(Grade) * num);
	Grade* key = (Grade*)malloc(sizeof(Grade) * open);
	for (int i = 0; i < num; i++)
	{
		scanf("%s %d", ary[i].name, &ary[i].score);
		getchar();
	}
	qsort(ary, num, sizeof(Grade), scompare);
	for (int i = 0; i < open; i++)
	{
		scanf("%s", key[i].name);
		getchar();
		get += search(ary, key[i].name, num);
	}
	int Min = get, Max = get;
	qsort(ary, num, sizeof(Grade), icompare);
	for (int i = 0; i < want - open; i++)
	{
		Min += ary[num - open - 1 - i].score;
		Max += ary[i].score;
	}
	printf("%d %d", Min, Max);
}