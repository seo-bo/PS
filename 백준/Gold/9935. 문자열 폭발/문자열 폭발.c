#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char ary[1000001] = { 0, };
char stack[1000001] = { 0, };
char bomb[37] = { 0, };
int head = 0;

int main(void)
{
	int k = 0;
	scanf("%s %s", ary, bomb);
	int size = (int)strlen(ary);
	int bombsize = (int)strlen(bomb);
	for (int i = 0; i < size; i++)
	{
		stack[head++] = ary[i];
		if (head >= bombsize && memcmp(stack + head - bombsize, bomb, bombsize) == 0)
		{
			head -= bombsize;
		}
	}
	stack[head] = '\0';
	if (head == 0)
	{
		printf("FRULA");
	}
	else
	{ 
		printf("%s", stack);
	}
}
