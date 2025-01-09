#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[51];
char stack[51];
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
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(')
		{
			push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (head == -1)
			{
				return 0;
			}
			else
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
	int num = 0, count = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		memset(str, '\0', 51);
		memset(stack, '\0', 51);
		scanf("%s", str);
		if (check())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}