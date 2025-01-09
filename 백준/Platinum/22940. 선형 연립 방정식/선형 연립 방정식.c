#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Linear
{
	double ary[7];
	double root;
}Linear;

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Linear* result = (Linear*)malloc(sizeof(Linear) * num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			double temp = 0;
			scanf("%lf", &temp);
			if (j == num)
			{
				result[i].root = temp;
			}
			else
			{
				result[i].ary[j] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++) 
	{
		int maxIdx = i;
		for (int j = i + 1; j < num; j++) 
		{
			if (fabs(result[j].ary[i]) > fabs(result[maxIdx].ary[i])) 
			{
				maxIdx = j;
			}
		}
		Linear temp = result[i];
		result[i] = result[maxIdx];
		result[maxIdx] = temp;
		for (int j = i + 1; j < num; j++) 
		{
			double factor = result[j].ary[i] / result[i].ary[i];
			for (int k = i; k < num; k++) 
			{
				result[j].ary[k] -= factor * result[i].ary[k];
			}
			result[j].root -= factor * result[i].root;
		}
	}

	for (int i = num - 1; i >= 0; i--) 
	{
		for (int j = i + 1; j < num; j++) 
		{
			result[i].root -= result[j].root * result[i].ary[j];
		}
		result[i].root /= result[i].ary[i];
	}

	for (int i = 0; i < num; i++) {
		printf("%.0lf ", round(result[i].root));
	}
	free(result);
}
