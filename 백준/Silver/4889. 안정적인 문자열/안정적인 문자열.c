#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char ary[2001];
char stack[2001];
int head = -1;

int empty()
{
	return head == -1;
}

void push(char str)
{
	stack[++head] = str;
}

char pop()
{
	if (empty())
	{
		return 0;
	}
	return stack[head--];
}


int main(void)
{
	int test = 0;
	while (1)
	{
		memset(ary, '\0', sizeof(ary));
		memset(stack, '\0', sizeof(stack));
		scanf("%s", ary);
		getchar();
		if (ary[0] == '-')
		{
			break;
		}
		int size = strlen(ary);
		head = -1;
		int count = 0;

		for (int i = 0; i < size; i++)
		{
			if (ary[i] == '{')
			{
				push('{');
			}
			else if (ary[i] == '}')
			{
				if (!empty())
				{
					pop();
				}
				else
				{
					count++;
					push('{');
				}
			}
		}
		count += (head + 1) / 2;
		printf("%d. %d\n", ++test, count);
	}
}


