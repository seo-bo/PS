#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ary[11];
int compare(const void* num1, const void* num2)
{
	if (*(char*)num1 > *(char*)num2)
	{
		return -1;
	}
	if (*(char*)num1 < *(char*)num2)
	{
		return 1;
	}
	else return 0;
}
int main(void)
{
	scanf("%s", ary);
	int size = strlen(ary);
	qsort(ary, size, sizeof(char), compare);
	for (int i = 0; i < size; i++)
	{
		printf("%c", ary[i]);
	}
}
