#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long size = 0;
char temp[2000001];
char S[4000005];
long long A[4000005] = { 0, };

long long Min(long long num1, long long num2)
{
	return (num1 > num2) ? num2 : num1;
}

long long manacher()
{
	long long r = 0, p = 0, result = 0;
	for (long long i = 0; i < size; i++)
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
		result += ((A[i] + 1) / 2);
	}
	return result;
}

int main(void)
{
	scanf("%s", temp);
	long long tlen = strlen(temp), j = 0, result = 0;
	for (long long i = 0; i < tlen; i++)
	{
		S[j] = '?';
		j++;
		S[j] = temp[i];
		j++;
	}
	S[j] = '?', S[j+1] = '\0';
	size = strlen(S);
	printf("%lld", manacher());
}