#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[200001] = { 0, };
int result[500001] = { 0, };
int sum[500001] = { 0, };

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num = 0, hei = 0, count = 1, Min =0;
	scanf("%d %d", &num, &hei);
	getchar();
	for (int i = 1; i <= num; i++)
	{
		int get = 0;
		scanf("%d", &get);
		getchar();
		if (i % 2 != 0)
		{
			result[get]--;
			result[0]++;
		}
		else if (i % 2 ==0)
		{
			result[hei-get]++;
		}
	} 
	sum[0] = result[0];
	for (int i = 1; i < hei; i++)
	{
		sum[i] = sum[i - 1] + result[i];
	}
	qsort(sum, hei, sizeof(int), compare);
	Min = sum[0];
	for (int i = 1; i < hei; i++)
	{
		if (sum[i] > Min)
		{
			printf("%d %d", Min, count);
			return 0;
		}
		else
		{
			count++;
		}
	}
}