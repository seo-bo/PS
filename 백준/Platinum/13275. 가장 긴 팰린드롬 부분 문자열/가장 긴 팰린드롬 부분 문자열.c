#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
char S[200005];
int A[200005] = { 0, };

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
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
	char temp[100001];
	scanf("%s", temp);
	int tlen = strlen(temp), j = 0, result = 0;
	for (int i = 0; i < tlen; i++)
	{
		S[j] = '?';
		j++;
		S[j] = temp[i];
		j++;
	}
	S[j] = '?', S[j+1] = '\0';
	size = strlen(S);
	manacher();
	for (int i = 0; i < size; i++)
	{
		result = Max(result, A[i]);
	}
	printf("%d", result);
}