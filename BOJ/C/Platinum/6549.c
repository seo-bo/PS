#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

long long ary[100002] = { 0, };
long long stack[100002] = { 0, };
long long head = -1;

long long Max(long long num1, long long num2)
{
	return (num1 > num2) ? num1 : num2;
}

void push(long long num)
{
	stack[++head] = num;
}

long long pop()
{
	return stack[head--];
}

long long empty()
{
	return head == -1;
}

long long check(long long size)
{
	long long result = 0;
	for (long long i = 1; i <= size + 1; i++)
	{
		while (!empty() && ary[stack[head]] > ary[i])
		{
			long long temp = stack[head];
			pop();
			result = Max(result, ary[temp] * (i - 1 - stack[head]));
		}
		push(i);
	}
	return result;
}

int main(void)
{
	while (1)
	{
		memset(ary, 0, sizeof(ary));
		memset(stack, 0, sizeof(stack));
		head = -1;
		long long num = 0;
		scanf("%lld", &num);
		if (num == 0)
		{
			return 0;
		}
		for (long long i = 1; i <= num; i++)
		{
			scanf("%lld", &ary[i]);
		}
		push(0);
		long long get = check(num);
		printf("%lld\n", get);
	}
}
