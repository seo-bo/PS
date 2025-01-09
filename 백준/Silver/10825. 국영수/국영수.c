#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
	char name[11];
	int kor;
	int eng;
	int math;
}Point;

int compare(const void* num1, const void* num2)
{
	if (((Point*)num1)->kor == ((Point*)num2)->kor && ((Point*)num1)->eng == ((Point*)num2)->eng && ((Point*)num1)->math == ((Point*)num2)->math)
	{
		return strcmp(((Point*)num1)->name , ((Point*)num2)->name);
	}
	else if (((Point*)num1)->kor == ((Point*)num2)->kor && ((Point*)num1)->eng == ((Point*)num2)->eng)
	{
		return ((Point*)num2)->math - ((Point*)num1)->math;
	}
	else if (((Point*)num1)->kor == ((Point*)num2)->kor)
	{
		return ((Point*)num1)->eng - ((Point*)num2)->eng;
	}
	else
	{
		return ((Point*)num2)->kor - ((Point*)num1)->kor;
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Point* ary = (Point*)malloc(sizeof(Point) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s %d %d %d", ary[i].name, &ary[i].kor, &ary[i].eng, &ary[i].math);
		getchar();
	}
	qsort(ary, num, sizeof(Point), compare);
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", ary[i].name);
	}
	free(ary);
}