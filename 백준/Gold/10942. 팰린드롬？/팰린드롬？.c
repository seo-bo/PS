#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
int S[5001] = { 0, };
int A[5001] = { 0, };

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

void manacher()
{
	int r = 0, p = 0;
	for (int i = 0; i < size; i++)
	{
		if (i <= r)
		{
			A[i] = Min(A[2 * p - i], r - i);
		}
		else
		{
			A[i] = 0;
		}
		while (0 <= i - A[i] - 1 && i + A[i] + 1 < size && S[i - A[i] - 1] == S[i + A[i] + 1])
		{
			A[i]++;
		}
		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}
}

int main(void)
{
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		S[2 * i] = 0;
		scanf("%d", &S[2 * i + 1]);
	}
	size = size * 2 + 1;
	S[size - 1] = 0;
	manacher();
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int s = 0, e = 0;
		scanf("%d %d", &s, &e);
		s--; e--;
		if (A[s + e + 1] >= e - s + 1)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
}