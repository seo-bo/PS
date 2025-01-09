#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num = 0, count = 0, get = 0;
	scanf("%d", &num);
	int start = 0, end = num - 1;
	int* ary = (int*)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	scanf("%d", &get);
	while(start < end)
	{
		if ((ary[start] + ary[end]) == get)
		{
			count++;
			if (ary[start + 1] - ary[start] < ary[end] - ary[end - 1])
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		else if ((ary[start] + ary[end]) < get)
		{
			start++;
		}
		else if ((ary[start] + ary[end]) > get)
		{
			end--;
		}
	}
	free(ary);
	printf("%d", count);
}