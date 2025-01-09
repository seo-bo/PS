#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[200001];
int sum[26][200001] = { 0, };
int main(void)
{
	int num = 0;
	scanf("%s", str);
	getchar();
	scanf("%d", &num);
	getchar();
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 26; j++) 
		{
			if (i == 0)
			{
				if (j == str[i] - 'a')
				{
					sum[j][i] = 1;
					break;
				}
			}
			else
			{
				if (j == str[i] - 'a')
				{
					sum[j][i] = sum[j][i - 1] + 1;
				}
				else
				{
					sum[j][i] = sum[j][i - 1];
				}
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		char get = 0;
		int start = 0, end = 0, result = 0;
		scanf("%c %d %d", &get, &start, &end);
		getchar();
		if (start - 1 < 0)
		{
			result = sum[get - 'a'][end];
		}
		else
		{
			result = sum[get - 'a'][end] - sum[get - 'a'][start - 1];
		}
		printf("%d\n", result);
	}
	
}