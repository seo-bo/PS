#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
typedef struct Word1
{
	char str[21];
}Word1;

typedef struct Word2
{
	char str2[21];
}Word2;

struct Word1 str[1000001];
struct Word2 str2[500001];

int compare(const void* num1, const void* num2) 
{
	return (strcmp((char*)num1, (char*)num2));
}

int main()
{
	int num1 = 0, num2 = 0, count = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1 + num2; i++)
	{
		scanf("%s", str[i].str);
	}
	qsort(str, num1 + num2, sizeof(str[0]), compare);
	for (int i = 0; i < num1 + num2; i++)
	{
		if (strcmp(str[i].str, str[i + 1].str) == 0)
		{
			strcpy(str2[count].str2, str[i].str);
			i++;
			count++;
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", str2[i].str2);
	}
}
