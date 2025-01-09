#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main() 
{
	int num = 0;
	scanf("%d", &num);
	while (1)
	{
		if (num == 0)
		{
			break;
		}
		int h = 0;
		int w = 0;
		int n = 0;
		
		scanf("%d %d %d", &h, &w, &n);
		int** ary;
		ary = (int**)malloc(sizeof(int*) * w);
		for (int i = 0; i < w; i++)
		{
			ary[i] = (int*)malloc(sizeof(int) * h);
		}
		int k = 1;
		int result1 = 0;
		int result2 = 0;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				ary[i][j] = k++;
				if (ary[i][j] == n)
				{
					result1 = i+1;
					result2 = j+1;
				}
			}
		}
		result2 = result2 * pow(10, 2);
		printf("%d\n", result1 + result2);
		num--;
		for (int i = 0; i < w; i++)
		{
			free(ary[i]);
		}
		free(ary);
	}
	
}

