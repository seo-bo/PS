#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Pos
{
	int x, y;
}Pos;

int compare(const void* num1, const void* num2)
{
	if (((Pos*)num1)->y != ((Pos*)num2)->y)
	{
		return ((Pos*)num1)->y - ((Pos*)num2)->y;
	}
	else
	{ 
		return ((Pos*)num1)->x - ((Pos*)num2)->x;
	}
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, end = 0, count = 0;
	scanf("%d", &num);
	Pos* ary = (Pos*)malloc(sizeof(Pos) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].x, &ary[i].y);
	}
	qsort(ary, num, sizeof(ary), compare);
	for (int i = 0; i < num; i++)
	{
		if (ary[i].x >= end)
		{
			end = ary[i].y;
			count++;
		}
	}
	printf("%d", count);
	free(ary);
}