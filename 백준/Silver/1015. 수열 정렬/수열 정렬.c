#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Geo
{
	int number;
	int order;
	int sort;
}Geo;

int compare(const void* num1, const void* num2)
{
	if ((*(Geo*)num1).number == (*(Geo*)num2).number)
	{
		return (*(Geo*)num1).order - (*(Geo*)num2).order;
	}
	else 
	{
		return (*(Geo*)num1).number - (*(Geo*)num2).number;
	}
}

int compare2(const void* num1, const void* num2)
{
	return (*(Geo*)num1).order - (*(Geo*)num2).order;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Geo* get = (Geo*)malloc(sizeof(Geo) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &get[i].number);
		get[i].order = i;
	}
	qsort(get, num, sizeof(Geo), compare);
	for (int i = 0; i < num; i++)
	{
		get[i].sort = i;
	}
	qsort(get, num, sizeof(Geo), compare2);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", get[i].sort);
	}
	free(get);
}