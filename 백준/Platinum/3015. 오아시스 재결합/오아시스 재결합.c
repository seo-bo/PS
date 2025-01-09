#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct human
{
	int height;
	long long freq;
}human;

int head = -1;

void push(human* stack, human num)
{
	stack[++head] = num;
}

human pop(human* stack)
{
	return stack[head--];
}

int main(void)
{
	long long result = 0;
	int num = 0;
	scanf("%d", &num);
	getchar();
	human* stack = (human*)malloc(sizeof(human) * num);
	for (int i = 0; i < num; i++)
	{
		human new = { 0, 0 };
		scanf("%d", &new.height);
		getchar();
		new.freq = 1;
		while (head > -1 && stack[head].height < new.height)
		{
			result += pop(stack).freq;
		}
		if (head == -1)
		{
			push(stack, new);
			continue;
		}
		if (stack[head].height == new.height)
		{
			long long temp = pop(stack).freq;
			result += temp;
			if (head > -1)
			{
				result++;
			}
			new.freq = temp + 1;
			push(stack, new);
		}
		else
		{
			push(stack, new);
			result++;
		}
	}
	printf("%lld", result);
}