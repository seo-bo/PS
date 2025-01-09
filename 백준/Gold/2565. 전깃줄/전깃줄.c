#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
	int idx;
	int value;
}line;

line ary[503];
int dp[503] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int compare(const void* num1, const void* num2)
{
	if (((line*)num1)->value == 0)
	{
		return 1;
	}
	if (((line*)num2)->value == 0)
	{
		return -1;
	}
	return ((line*)num1)->idx - ((line*)num2)->idx;
}

int main(void)
{
	int num = 0, result = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d %d", &ary[i].idx, &ary[i].value);
	}
	qsort(ary + 1, 501, sizeof(line), compare);
	int j = 0;
	for (int i = 1; i <= num; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (ary[i].value > ary[j].value)
			{
				dp[i] = Max(dp[i], dp[j] + 1);
			}
		}
		result = Max(result, dp[i]);
	}
	printf("%d", num - result);
}

