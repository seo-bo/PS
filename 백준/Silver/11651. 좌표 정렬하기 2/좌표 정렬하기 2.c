#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
	int x;
	int y;
}Point;

int compare(const void* num1, const void* num2)
{
	if (((Point*)num1)->y == ((Point*)num2)->y)
	{
		return ((Point*)num1)->x - ((Point*)num2)->x;
	}
	else
	{
		return ((Point*)num1)->y - ((Point*)num2)->y;
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Point* ary = (Point*)malloc(sizeof(Point) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].x, &ary[i].y);
	}
	qsort(ary, num, sizeof(Point), compare);
	for (int i = 0; i < num; i++)
	{
		printf("%d %d\n", ary[i].x, ary[i].y);
	}
	free(ary);
}