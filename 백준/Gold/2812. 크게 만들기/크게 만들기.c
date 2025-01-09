#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[500001];
int head = -1;

int main(void)
{
	int num = 0, del = 0, count = 0;
	scanf("%d %d", &num, &del);
	char* ary = (char*)malloc(sizeof(char) * (num + 1));
	scanf("%s", ary);
	stack[++head] = ary[0];
	for (int i = 1; i < num; i++)
	{
		if (ary[i] > stack[head] && count < del)
		{
			while (head > -1 && ary[i] > stack[head] && count < del)
			{
				head--;
				count++;
			}
			stack[++head] = ary[i];
		}
		else
		{
			stack[++head] = ary[i];
		}
	}
	while (head > -1 && count < del)
	{
		head--;
		count++;
	}
	stack[head + 1] = '\0';
	if (head == -1)
	{
		printf("0");
		return 0;
	}
	for (int i = 0; i <= head; i++)
	{
		printf("%c", stack[i]);
	}
}