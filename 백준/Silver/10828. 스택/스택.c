#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int stack[10001] = { 0, };
int head = -1;
char get[6];

void push(int num)
{
	stack[++head] = num;
}

int pop()
{
	return stack[head--];
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		memset(get, 0, sizeof(get));
		scanf("%s", get);
		getchar();
		if (strcmp(get, "push") == 0)
		{
			int temp = 0;
			scanf("%d", &temp);
			push(temp);
		}
		else if (strcmp(get, "pop") == 0)
		{
			if (head < 0)
			{
				printf("%d\n", -1);
			}
			else
			{
				printf("%d\n", pop());
			}
		}
		else if (strcmp(get, "size") == 0)
		{
			printf("%d\n", head + 1);
		}
		else if (strcmp(get, "empty") == 0)
		{
			if (head == -1)
			{
				printf("%d\n", 1);
			}
			else
			{
				printf("%d\n", 0);
			}
		}
		else if (strcmp(get, "top") == 0)
		{
			if (head < 0)
			{
				printf("%d\n", -1);
			}
			else
			{
				printf("%d\n", stack[head]);
			}
		}
	}
}
