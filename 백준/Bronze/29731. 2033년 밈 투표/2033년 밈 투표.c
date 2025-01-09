#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct Rick
{
	char str[51];
}Rick;
char get[51];

int search(Rick* ary, char* re, int size)
{
	int start = 0, end = size - 1;
	while (1)
	{
		int cen = (start + end) / 2;
		if (start > end)
		{
			break;
		}
		if (strcmp(ary[cen].str, re) == 0)
		{
			return 1;
		}
		else if (strcmp(ary[cen].str, re) < 0)
		{
			start = cen + 1;
		}
		else if (strcmp(ary[cen].str, re) > 0)
		{
			end = cen - 1;
		}
	}
	return 0;
}

int compare(const void* num1, const void* num2)
{
	return strcmp(((Rick*)num1)->str, ((Rick*)num2)->str);
}

int main(void)
{
	int num = 0, result =0;
	scanf("%d", &num);
	getchar();
	Rick* ary = (Rick*)malloc(sizeof(Rick) * 7);
	strcpy(ary[0].str, "Never gonna give you up");
	strcpy(ary[1].str, "Never gonna let you down");
	strcpy(ary[2].str, "Never gonna run around and desert you");
	strcpy(ary[3].str, "Never gonna make you cry");
	strcpy(ary[4].str, "Never gonna say goodbye");
	strcpy(ary[5].str, "Never gonna tell a lie and hurt you");
	strcpy(ary[6].str, "Never gonna stop");
	qsort(ary, 7, sizeof(Rick), compare);
	for (int i = 0; i < num; i++)
	{
		memset(get, '0', sizeof(char));
		fgets(get, 51, stdin);
		get[strlen(get) - 1] = '\0';
		result += search(ary, get, 7);
	}
	free(ary);
	if (result == num)
	{
		printf("No");
	}
	else
	{
		printf("Yes");
	}
}