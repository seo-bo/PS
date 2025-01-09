#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int bry[120] = { 0, };
typedef struct Winner
{
	int country;
	int number;
	int score;
}Winner;

int compare(const void* num1, const void* num2)
{
	return ((Winner*)num2)->score - ((Winner*)num1)->score;
}

int main(void) 
{
	int num = 0, count = 0;
	scanf("%d", &num);
	Winner* ary = (Winner*)malloc(sizeof(Winner) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d", &ary[i].country, &ary[i].number, &ary[i].score);
		getchar();
	}
	qsort(ary, num, sizeof(Winner), compare);
	for (int i = 0; i < num; i++)
	{
		if (count > 2)
		{
			break;
		}
		if (bry[ary[i].country] <= 1)
		{
			printf("%d %d\n", ary[i].country, ary[i].number);
			bry[ary[i].country]++;
			count++;
		}
	}
}