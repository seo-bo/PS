#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Point
{
	int posx;
	int posy;
}Point;
int compare(const void* num1, const void* num2)
{
	Point* pointA = (Point*)num1;
	Point* pointB = (Point*)num2;
	if (pointA->posx == pointB->posx)
	{
		return pointA->posy - pointB->posy;
	}
	else
		return pointA->posx - pointB->posx;
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Point* ary = (Point*)malloc(sizeof(Point) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].posx, &ary[i].posy);
	}
	qsort(ary, num, sizeof(Point), compare);
	for (int i = 0; i < num; i++)
	{
		printf("%d %d\n", ary[i].posx, ary[i].posy);
	}
	free(ary);
}
