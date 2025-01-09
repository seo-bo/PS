#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num = 0;
	int result = 0;
	int ary[101][101] = { 0, };
	scanf("%d", &num);
	for(int i = 0; i< num; i++)
	{
		int num1 = 0;
		int num2 = 0;
		scanf("%d %d", &num1, &num2);
		for (int i = num1-1; i <= num1 + 8; i++)
		{
			for (int j = num2-1; j <= num2 + 8; j++)
			{
				ary[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (ary[i][j] != 0)
			{
				result++;
			}
		}
	}
	printf("%d", result);

}