#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	int num = 0, sum = 0;
	scanf("%d %d", &num, &sum);
	getchar();
	int* prefix = (int*)malloc(sizeof(int) * (num + 1));
	prefix[0] = 0;
	for (int i = 1; i <= num; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		getchar();
		prefix[i] = prefix[i - 1] + temp;
	}
	int start = 0, end = 1, len = num + 1;
	while (end <= num && start <= num)
	{
		int current = prefix[end] - prefix[start];
		if (current >= sum)
		{
			len = Min(len, (end - start));
			start++;
		}
		else
		{
			end++;
		}
	}
	if (len > num)
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", len);
	}
	free(prefix);
}