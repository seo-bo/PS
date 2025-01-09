#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int result[100001] = { 0, };
int stack[100001] = { 0, };
char dtd[10000001] = { 0, };
int head = -1;

void push(int num)
{
	stack[++head] = num;
}

void pop(int num)
{
	stack[head--];
}

int check(int size)
{
	head = -1;
	int start = 1, k = 0, a = 0;
	for (int i = 0; i < size; i++)
	{
		while (start <= result[i])
		{
			push(start);
			dtd[a] = '+';
			a++;
			start++;
		}
		if (stack[head] > result[i])
		{
			return 0;
		}
		while (head > -1 && stack[head] == result[i])
		{
			pop(k);
			dtd[a] = '-';
			a++;
			k++;
			i++;
		}
		i--;
	}
	return 1;
}


int main(void)
{
	int num = 0, k = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &result[i]);
	}
	int get =check(num);
	if (get == 0)
	{
		printf("NO");
		return 0;
	}
	else
	{
		while (dtd[k] != '\0')
		{
			printf("%c\n", dtd[k]);
			k++;
		}
	}
}
