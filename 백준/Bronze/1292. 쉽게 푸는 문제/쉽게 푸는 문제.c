#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int start = 0, end = 0, count = 0, re =0, k =1, fill = 1, level =1, result =0;
	scanf("%d %d", &start, &end);
	int* ary = (int*)malloc(sizeof(int) * (end+1));
	while (1)
	{
		for (int i = re; i < k; i++)
		{
			ary[i] = fill;
			count++;
			if (count == end)
			{
				break;
			}
		}
		if (count == end)
		{
			break;
		}
		re = k;
		level++;
		k+= level;
		fill++;
	}
	for (int i = start -1; i < end; i++)
	{
		result += ary[i];
	}
	printf("%d", result);
	free(ary);
}

