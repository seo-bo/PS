#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct Info
{
	char str[1001];
}Info;
char temp[1001];

int compare(const void* num1, const void* num2)
{
	return strcmp(((Info*)num1)->str, ((Info*)num2)->str);
}

int main(void)
{
	int go = 0, dupli = 0;
	scanf("%s", temp);
	int size = strlen(temp);
	int num = size * (size + 1) / 2;
	Info* clean = (Info*)malloc(sizeof(Info) * num);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			memset(clean[go].str, 0, size);
			strncpy(clean[go].str, temp + i, j + 1);
			clean[go].str[j + 1] = '\0';
			go++;
		}
	}
	qsort(clean, num, sizeof(Info), compare);
	for (int i = 0; i < num; i++)
	{
		
		if (strcmp(clean[i].str, clean[i + 1].str) == 0)
		{
			dupli++;
		}
	}
	free(clean);
	printf("%d", num - dupli);
}