#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double result[10];

int compare(const void* num1, const void* num2)
{
	if (*(double*)num1 < *(double*)num2)
	{
		return -1;
	}
	if (*(double*)num1 > *(double*)num2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	char* ary = (char*)malloc(sizeof(char) * (num+1));
	scanf("%s", ary);
	getchar();
	for (int i = 0; i < num; i++)
	{
		if (ary[i] == 'B')
		{
			result[0]++;
		}
		else if (ary[i] == 'O')
		{
			result[1]++;
		}
		else if (ary[i] == 'N')
		{
			result[2]++;
		}
		else if (ary[i] == 'Z')
		{
			result[3]++;
		}
		else if (ary[i] == 'S')
		{
			result[4]++;
		}
		else if (ary[i] == 'I')
		{
			result[5]++;
		}
		else if (ary[i] == 'L')
		{
			result[6]++;
		}
		else if (ary[i] == 'V')
		{
			result[7]++;
		}
		else if (ary[i] == 'E')
		{
			result[8] += 0.5;
		}
		else if (ary[i] == 'R')
		{
			result[9] += 0.5;
		}
	}
	qsort(result, 10, sizeof(double), compare);
	result[0] = floor(result[0]);
	printf("%d", (int)result[0]);
}