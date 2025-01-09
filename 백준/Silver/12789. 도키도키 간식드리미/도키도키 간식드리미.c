#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1001] = { 0, };
int stack[1001] = { 0, };
int head = -1;

void push(int num)
{
	stack[++head] = num;
}

void pop()
{
	stack[head--];
}

int check(int size)
{
	head = -1;
	int start = 1;
	for (int i = 0; i < size; i++)
	{
		if (ary[i] > start)
		{
			push(ary[i]);
		}
		else if (ary[i] == start)
		{
			start++;
		}
		if (head > -1 && stack[head] == start)
		{
			while (stack[head] == start && head > -1)
			{
				pop();
				start++;
			}
		}
	}
	if (head == -1)
	{
		return 1;
	}
	else
	{
		int newsize = head;
		for (int i = newsize; i > -1; i--)
		{
			if (stack[i] != start)
			{
				return 0;
			}
			else
			{
				pop();
				start++;
			}
		}
		return 1;
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
	int result = check(num);
	if (result == 0)
	{
		printf("Sad");
	}
	else if (result == 1)
	{
		printf("Nice");
	}
}
