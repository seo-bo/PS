#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
	char str[51];
	int frequency;
}Book;

int compare(const void* num1, const void* num2)
{
	return strcmp((*(Book*)num1).str, (*(Book*)num2).str);
}

int frcompare(const void* num1, const void* num2)
{
	return (*(Book*)num2).frequency - (*(Book*)num1).frequency;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Book* getfre = (Book*)malloc(sizeof(Book) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", getfre[i].str);
		getfre[i].frequency = 1;
	}
	qsort(getfre, num, sizeof(Book), compare);

	for (int i = 0; i < num; i++)
	{
		if (i > 0)
		{
			if (strcmp(getfre[i].str, getfre[i - 1].str) == 0)
			{
				getfre[i].frequency += getfre[i - 1].frequency;
				getfre[i - 1].frequency = 0;
			}
		}
	}
	qsort(getfre, num, sizeof(Book), frcompare);
	printf("%s", getfre[0].str);
}