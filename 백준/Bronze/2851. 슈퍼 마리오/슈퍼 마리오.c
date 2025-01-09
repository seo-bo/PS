#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int ary[10] = { 0, };
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &ary[i]);
		
	}
	for (int i = 0; i < 10; i++)
	{
		result += ary[i];
		if (result == 100)
		{
			break;
		}
		else if (result < 100 && result + ary[i + 1] > 100)
		{
			if (abs(100 - result) < abs(100 - result - ary[i + 1]))
			{
				break;
			}
			else if (abs(100 - result) > abs(100 - result - ary[i + 1]))
			{
				result += ary[i+1];
				break;
			}
			else if (abs(100 - result) == abs(100 - result - ary[i + 1]))
			{
				result += ary[i + 1];
				break;
			}
		}	
	}
	printf("%d", result);
}
