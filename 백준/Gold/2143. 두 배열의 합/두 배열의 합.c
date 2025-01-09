#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* num1, const void* num2)
{
	if (*(long long*)num1 > *(long long*)num2)
	{
		return 1;
	}
	else if (*(long long*)num1 < *(long long*)num2)
	{
		return -1;
	}
	else 
	{ 
		return 0; 
	}
}

int lower(long long* ary, int size, long long key)
{
	int start = 0, end = size;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] >= key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

int upper(long long* ary, int size, long long key)
{
	int start = 0, end = size;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] > key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

int main(void)
{
	long long result = 0;
	int T = 0;
	scanf("%d", &T);
	int num = 0, num2 = 0;
	scanf("%d", &num);
	long long* A = (long long*)calloc((num + 1), sizeof(long long));
	long long* partialSumA = (long long*)calloc((num * (num + 1) / 2), sizeof(long long));
	int idx = 0;
	for (int i = 1; i <= num; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		A[i] = A[i - 1] + temp;
		for (int j = 1; j <= i; j++)
		{
			partialSumA[idx++] = A[i] - A[j - 1];
		}
	}
	scanf("%d", &num2);
	long long* B = (long long*)calloc((num2 + 1), sizeof(long long));
	long long* partialSumB = (long long*)calloc((num2 * (num2 + 1) / 2), sizeof(long long));
	idx = 0;
	for (int i = 1; i <= num2; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		B[i] = B[i - 1] + temp;
		for (int j = 1; j <= i; j++)
		{
			partialSumB[idx++] = B[i] - B[j - 1];
		}
	}
	qsort(partialSumA, num * (num + 1) / 2, sizeof(long long), compare);
	qsort(partialSumB, num2 * (num2 + 1) / 2, sizeof(long long), compare);
	for (int i = 0; i < num * (num + 1) / 2; i++)
	{
		long long diff = T - partialSumA[i];
		result += upper(partialSumB, num2 * (num2 + 1) / 2, diff) - lower(partialSumB, num2 * (num2 + 1) / 2, diff);
	}
	printf("%lld", result);
}
