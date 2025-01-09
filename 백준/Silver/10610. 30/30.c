#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ary[100001];

int compare(const void* num1, const void* num2)
{
	return *(char*)num2 - *(char*)num1;
}


int main(void)
{
	int result = 0;
	scanf("%s", ary);
	getchar();
	int size = strlen(ary);
	qsort(ary, size, sizeof(char), compare);
	if (ary[size - 1] != '0')
	{
		printf("%d", -1);
		return 0;
	}
	else
	{
		for (int i = 0; i <= size - 2; i++)
		{
			result += ary[i] - '0';
		}
		if (result % 3 == 0)
		{
			printf("%s", ary);
			return 0;
		}
		else
		{
			printf("%d", -1);
			return 0;
		}
	}
}
