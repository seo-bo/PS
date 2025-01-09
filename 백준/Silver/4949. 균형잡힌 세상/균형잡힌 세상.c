#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char ary[103];
char stack[103];
int head = -1;

void push(char c)
{
	stack[++head] = c;
}

char pop()
{
	return stack[head--];
}

int check()
{
	head = -1;
	int size = strlen(ary);
	for (int i = 0; i < size; i++)
	{
		if (ary[i] == '(' || ary[i] == '[')
		{
			push(ary[i]);
		}
		else if (ary[i] == ')')
		{
			if (head == -1)
			{
				return 0;
			}
			else if (stack[head] != '(')
			{
				return 0;
			}
			else if (stack[head] == '(')
			{
				pop();
			}
		}
		else if (ary[i] == ']')
		{
			if (head == -1)
			{
				return 0;
			}
			else if (stack[head] != '[')
			{
				return 0;
			}
			else if (stack[head] == '[')
			{
				pop();
			}
		}
	}
	if (head == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{

	while (1)
	{
		memset(ary, 0, sizeof(ary));
		memset(ary, 0, sizeof(stack));
		fgets(ary, 102, stdin);
		ary[strcspn(ary, "\n")] = '\0';
		if (ary[0] == '.')
		{
			return 0;
		}
		int result = check();
		if (result == 1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}

