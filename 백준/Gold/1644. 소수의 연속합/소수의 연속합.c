#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[4000001] = { 0, };
int list[300000] = { 0, };

int prime(int num)
{
	ary[0] = 1, ary[1] = 1;
	for (int i = 2; i * i <= num; i++)
	{
		if(ary[i] == 0)
		{ 
			for (int j = i * i; j <= num; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int idx = 1;
	list[idx++] = 2;
	for (int i = 3; i <= num; i++)
	{
		if (ary[i] == 0)
		{
			list[idx++] = list[idx - 1] + i;
		}
	}
	return idx;
}


int main(void)
{
	int num = 0, count = 0;
	scanf("%d", &num);
	int size = prime(num);
	int start = 0, end = 0;
	while (start <= end && end < size)
	{
		int get = list[end] - list[start];
		if (get < num)
		{
			end++;
		}
		else if (get >= num)
		{
			if (get == num)
			{
				count++;
			}
			start++;
		}
	}
	printf("%d", count);
}