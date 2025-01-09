#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num = 0, test = 0;
	scanf("%d %d", &num, &test);
	int* prefix = (int*)malloc(sizeof(int) * (num + 1));
	prefix[0] = 0;
	for (int i = 1; i <= num; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		prefix[i] = prefix[i - 1] + temp;
	}
	for (int i = 0; i < test; i++)
	{
		int start = 0, end = 0;
		scanf("%d %d", &start, &end);
		printf("%d\n", prefix[end] - prefix[start - 1]);
	}
	free(prefix);
}