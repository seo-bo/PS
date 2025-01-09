#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Info
{
	char file[101];
	int count;
}Info;

int compare(const void* num1, const void* num2)
{
	return strcmp(((Info*)num1)->file, ((Info*)num2)->file);
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Info* clean = (Info*)malloc(sizeof(Info) * num);
	for (int i = 0; i < num; i++)
	{
		char str[101] = {0,};
		scanf("%s", str);
		char *get = strchr(str, '.');
		if (get != NULL)
		{
			strcpy(clean[i].file, get + 1);
			clean[i].count = 1;
		}
	}
	qsort(clean, num, sizeof(Info), compare);
	for (int i = 0; i < num; i++)
	{
		if (strcmp(clean[i].file, clean[i + 1].file) == 0)
		{
			clean[i + 1].count += clean[i].count;
			clean[i].count = 0;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (clean[i].count != 0)
		{
			printf("%s %d\n", clean[i].file, clean[i].count);
		}
	}
}