#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	double** ary = (double**)calloc(num, sizeof(double*));
	for (int i = 0; i < num; i++)
	{
		ary[i] = (double*)calloc(num, sizeof(double));
		for (int j = 0; j < num; j++)
		{
			scanf("%lf", &ary[i][j]);
		}
	}

	double** L = (double**)calloc(num, sizeof(double*));
	double** U = (double**)calloc(num, sizeof(double*));
	for (int i = 0; i < num; i++)
	{
		L[i] = (double*)calloc(num, sizeof(double));
		U[i] = (double*)calloc(num, sizeof(double));
	}

	for (int i = 0; i < num; i++) 
	{
		L[i][i] = 1;
		for (int j = i; j < num; j++) 
		{
			double sum = 0;
			for (int k = 0; k < i; k++) 
			{
				sum += L[i][k] * U[k][j];
			}
			U[i][j] = ary[i][j] - sum;
		}

		for (int j = i + 1; j < num; j++) 
		{
			double sum = 0;
			for (int k = 0; k < i; k++) 
			{
				sum += L[j][k] * U[k][i];
			}
			if (U[i][i] == 0) 
			{
				printf("%d", -1);
				return 0;
			}
			L[j][i] = (ary[j][i] - sum) / U[i][i];
		}
	}

	for (int i = 0; i < num; i++) 
	{
		for (int j = 0; j < num; j++) 
		{
			printf("%.3lf ", L[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < num; i++) 
	{
		for (int j = 0; j < num; j++) 
		{
			printf("%.3lf ", U[i][j]);
		}
		printf("\n");
	}

}