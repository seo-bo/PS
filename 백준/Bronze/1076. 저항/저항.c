#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>

char get[7];

typedef struct color
{
	char str[7];
	int num;
}color;

int compare(const void* num1, const void* num2)
{
	return strcmp(((color*)num1)->str, ((color*)num2)->str);
}

int search(color* ary, char* key, int size)
{
	int start = 0, end = size - 1;
	while (start<=end)
	{
		int cen = (start + end) / 2;
		if (strcmp(ary[cen].str, key) == 0)
		{
			return ary[cen].num;
		}
		else if (strcmp(ary[cen].str, key) > 0)
		{
			end = cen - 1;
		}
		else if (strcmp(ary[cen].str, key) < 0)
		{
			start = cen + 1;
		}
	}
	return -1;
}

int main(void)
{
	long long result = 0;
	color* ary = (color*)malloc(sizeof(color) * 10);
	strcpy(ary[0].str, "black"); ary[0].num = 0;
	strcpy(ary[1].str, "brown"); ary[1].num = 1;
	strcpy(ary[2].str, "red"); ary[2].num = 2;
	strcpy(ary[3].str, "orange"); ary[3].num = 3;
	strcpy(ary[4].str, "yellow"); ary[4].num = 4;
	strcpy(ary[5].str, "green"); ary[5].num = 5;
	strcpy(ary[6].str, "blue"); ary[6].num = 6;
	strcpy(ary[7].str, "violet"); ary[7].num = 7;
	strcpy(ary[8].str, "grey"); ary[8].num = 8;
	strcpy(ary[9].str, "white"); ary[9].num = 9;
	qsort(ary, 10, sizeof(color), compare);
	for (int i = 0; i < 2; i++)
	{
		memset(get, 0, sizeof(get));
		scanf("%s", get);
		result += (long long)search(ary, get, 10) * pow(10,1-i);
		
	}
	memset(get, 0, sizeof(get));
	scanf("%s", get);
	result *= (long long)pow(10, search(ary, get, 10));
	free(ary);
	printf("%lld", result);
}