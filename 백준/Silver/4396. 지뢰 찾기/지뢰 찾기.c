#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	int num = 0, count =0;
	scanf("%d", &num);
	getchar();
	int temp = num + 3;
	char** ary = (char**)malloc(sizeof(char*) * temp);
	for (int i = 0; i < temp; i++)
	{
		ary[i] = (char*)malloc(sizeof(char) * temp);
		memset(ary[i], 0, temp);
	}
	char** bry = (char**)malloc(sizeof(char*) * temp);
	for (int i = 0; i < temp; i++)
	{
		bry[i] = (char*)malloc(sizeof(char) * temp);
		memset(bry[i], 0, temp);
	}
	for (int i = 1; i <= num; i++)
	{
		fgets(ary[i] + 1, num + 1, stdin);
		ary[i][num + 1] = 0;
		getchar();
	}
	for (int i = 1; i <= num; i++)
	{
		fgets(bry[i] + 1, num + 1, stdin);
		bry[i][num + 1] = 0;
		getchar();
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			if (bry[i][j] == 'x' && ary[i][j] == '*')
			{
				count++;
			}
			else if (bry[i][j] == 'x')
			{
				int sum = (ary[i - 1][j - 1] == '*') + (ary[i - 1][j] == '*') + (ary[i - 1][j + 1] == '*') + (ary[i][j - 1] == '*') + (ary[i][j + 1] == '*') + (ary[i + 1][j - 1] == '*') + (ary[i + 1][j] == '*') + (ary[i + 1][j + 1] == '*');
				bry[i][j] = sum + '0';
			}
		}
	}
	if (count > 0)
	{
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				if (ary[i][j] == '*')
				{
					bry[i][j] = '*';
				}
			}
		}
	}
	for (int i = 1; i <= num; i++)
	{
		printf("%s\n", bry[i]+1);
	}
	for (int i = 0; i < temp; i++)
	{
		free(ary[i]);
		free(bry[i]);
	}
	free(ary);
	free(bry);
}