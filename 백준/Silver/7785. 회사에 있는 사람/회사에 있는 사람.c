#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Staff
{
	char name[6];
	char now[6];
}Staff;

int icompare(const void* num1, const void* num2)
{
	return strcmp(((Staff*)num2)->name, ((Staff*)num1)->name);
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Staff* log = (Staff*)malloc(sizeof(Staff) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s %s", &log[i].name, &log[i].now);
	}
	qsort(log, num, sizeof(Staff), icompare);
	for (int i = 0; i < num; i++)
	{
		if (strcmp(log[i].name, log[i + 1].name) == 0)
		{
			i++;
		}
		else
		{
			printf("%s\n", log[i].name);
		}
	}
	free(log);
}