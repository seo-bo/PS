#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[100002] = { 0, };
int stack[100002] = { 0, };
int head = -1;

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

void push(int num)
{
	stack[++head] = num;
}

int pop()
{
	return stack[head--];
}

int empty()
{
	return head == -1;
}

int check(int size)
{
	int result = 0;
	for (int i = 1; i <= size + 1; i++)
	{
		while (!empty() && ary[stack[head]] > ary[i])
		{
			int temp = stack[head];
			pop();
			result = Max(result, ary[temp] * (i - 1 - stack[head]));
		}
		push(i);
	}
	return result;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
	}
	push(0);
	int get = check(num);
	printf("%d", get);
}