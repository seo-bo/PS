#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char result[21];
typedef struct Pokemon
{
	char name[21];
	int count;
}Pokemon;

int strsearch(Pokemon* ary, char* get, int size)
{
	int start = 0, end = size - 1;
	while (1)
	{
		int cen = (start + end) / 2;
		if (start > end)
		{
			break;
		}
		if (strcmp(ary[cen].name, get) == 0)
		{
			return ary[cen].count;
		}
		else if (strcmp(ary[cen].name, get) > 0)
		{
			end = cen - 1;
		}
		else if (strcmp(ary[cen].name, get) < 0)
		{
			start = cen + 1;
		}
	}
	return -1;
}

int strcompare(const void* num1, const void* num2)
{
	return strcmp(((Pokemon*)num1)->name, ((Pokemon*)num2)->name);
}

int main(void)
{
	int num = 0, prob = 0;
	scanf("%d %d", &num, &prob);
	getchar();
	Pokemon* str = (Pokemon*)malloc(sizeof(Pokemon) * num);
	Pokemon* dig = (Pokemon*)malloc(sizeof(Pokemon) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", str[i].name);
		getchar();
		strcpy(dig[i].name, str[i].name);
		str[i].count = i; dig[i].count = i;
	}
	qsort(str, num, sizeof(Pokemon), strcompare);
	for (int i = 0; i < prob; i++)
	{
		memset(result, 0, sizeof(result));
		scanf("%s", result);
		getchar();
		if (isdigit(result[0]))
		{
			int a = atoi(result);
			printf("%s\n", dig[a - 1].name);
		}
		else
		{
			printf("%d\n", strsearch(str, result, num) + 1);
		}
	}
	free(str);
	free(dig);

}