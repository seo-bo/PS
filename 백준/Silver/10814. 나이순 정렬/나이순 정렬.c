#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
	int age;
	int count;
	char name[101];
}Point;

int compare(const void* num1, const void* num2)
{
	if (((Point*)num1)->age == ((Point*)num2)->age)
	{
		return (((Point*)num1)->count - ((Point*)num2)->count);
	}
	else
	{
		return ((Point*)num1)->age - ((Point*)num2)->age;
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Point* ary = (Point*)malloc(sizeof(Point) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %s", &ary[i].age, ary[i].name);
		getchar();
		ary[i].count = i;
	}
	qsort(ary, num, sizeof(Point), compare);
	for (int i = 0; i < num; i++)
	{
		printf("%d %s\n", ary[i].age, ary[i].name);
	}
	free(ary);
}