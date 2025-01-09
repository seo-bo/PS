#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char ary[102];
char stack[102];
char result[102];
int head = -1;

void push(char c)
{
	stack[++head] = c;
}

char pop()
{
	return stack[head--];
}

int empty()
{
	return head == -1;
}

void check(int size)
{
	head = -1;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if ('A' <= ary[i] && ary[i] <= 'Z')
		{
			result[k++] = ary[i];
		}
		else if (ary[i] == '-' || ary[i] == '+')
		{
			while (!empty() && stack[head] != '(')
			{
				result[k++] = pop();
			}
			push(ary[i]);
		}
		else if (ary[i] == '*' || ary[i] == '/')
		{
			while (!empty() && (stack[head] == '*' || stack[head] == '/'))
			{
				result[k++] = pop();
			}
			push(ary[i]);
		}
		else if (ary[i] == '(')
		{
			push(ary[i]);
		}
		else if (ary[i] == ')')
		{
			while (stack[head] != '(')
			{
				result[k++] = pop();
			}
			pop();
		}
	}
	while (!empty())
	{
		result[k++] = pop();
	}
	result[k] = '\0';
}

int main(void)
{
	scanf("%s", ary);
	int size = strlen(ary);
	check(size);
	printf("%s", result);
}