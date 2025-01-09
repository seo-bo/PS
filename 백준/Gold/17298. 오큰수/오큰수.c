#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1000001] = { 0, };
int stack[1000001] = { 0, };
int result[1000001] = { 0, };
int head = -1;

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

void check(int size)
{
	for (int i = 0; i < size; i++)
	{
		while (!empty() && ary[stack[head]] < ary[i])
		{
			result[stack[head]] = ary[i];
			pop();
		}
		push(i);
	}
	while (!empty())
	{
		result[stack[head]] = -1;
		pop();
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	check(num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", result[i]);
	}
}
