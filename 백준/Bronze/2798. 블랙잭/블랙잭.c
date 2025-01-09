#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getscore(int* ary, int num,int score)
{
	int max = 0;
	for (int i = 0; i < num-2; i++)
	{
		for (int j = i + 1; j < num - 1; j++)
		{
			for (int k = j + 1; k < num; k++)
			{
				if ((ary[i] + ary[j] + ary[k]) <= score && (ary[i] + ary[j] + ary[k])>= max)
				{
					max = ary[i] + ary[j] + ary[k];
				}
			}
		}
	}
	return max;
}
int main(void)
{
	int num = 0, score = 0;
	scanf("%d %d", &num, &score);
	int* ary = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	int result = getscore(ary,num,score);
	printf("%d", result);
}
