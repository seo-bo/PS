#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct eat
{
	int burger;
	int cola;
}eat;

int compare(const void* num1, const void* num2)
{
	if ((*(eat*)num1).cola == (*(eat*)num2).cola)
	{
		return (*(eat*)num2).burger - (*(eat*)num1).burger;
	}
	else
		return (*(eat*)num1).cola - (*(eat*)num2).cola;
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	int tower = 0, bulgogi = 0, time =0;
	scanf("%d %d %d", &tower, &bulgogi, &time);
	int more = Max(tower, bulgogi);
	int less = Min(tower, bulgogi);
	int cal = time / less;
	eat* result = (eat*)malloc(sizeof(eat) * (cal + 1));
	memset(result, 0, sizeof(eat) * (cal + 1));
	for (int i = cal; i >= 0; i--)
	{
		result[i].burger += i;
		result[i].burger += ((time - (i * less)) / more);
		result[i].cola += ((time - (i * less)) % more);
	}
	qsort(result, cal + 1, sizeof(eat), compare);
	printf("%d %d", result[0].burger, result[0].cola);
}