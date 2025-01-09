#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

void search(char * ary,char*bry, int virus, int size)
{
	for (int i = 0; i < size; i++)
	{
		int start = 0;
		int end = 0;
		if (ary[i] == 'R')
		{
			start = Max(0, i - virus);
			end = Min(size-1, i + virus);
			for (int j = start; j <= end; j++)
			{
				if (bry[j] == '.')
				{
					bry[j] = 'R';
				}
			}
		}
	}
}

int main(void)
{
	int num = 0, med = 0, virus = 0, result =0;
	scanf("%d %d %d", &num, &med, &virus);
	char* ary = (char*)malloc(sizeof(char) * (num + 1));
	char* bry = (char*)malloc(sizeof(char) * (num + 1));
	scanf("%s", ary);
	strcpy(bry, ary);
	search(ary, bry, virus, num);
	for (int i = 0; i < num; i++)
	{
		if (bry[i] == 'R')
		{
			result++;
		}
	}
	if (result > med)
	{
		printf("No");
	}
	else
	{
		printf("Yes");
	}
	free(ary);
	free(bry);
}