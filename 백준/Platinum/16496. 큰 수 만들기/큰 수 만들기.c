#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sort
{
	char get[11];
}Sort;

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int compare(const void* num1, const void* num2)
{
	char str1[21];
	char str2[21];

	strcpy(str1, ((Sort*)num1)->get);
	strcat(str1, ((Sort*)num2)->get);
	strcpy(str2, ((Sort*)num2)->get);
	strcat(str2, ((Sort*)num1)->get);

	return strcmp(str2, str1);
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Sort* ary = malloc(sizeof(Sort) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", ary[i].get);
	}
	qsort(ary, num, sizeof(Sort), compare);
	if (ary[0].get[0] == '0')
	{
		printf("0");
		return 0;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%s", ary[i].get);
	}
	free(ary);
}