#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(long long**min, long long **max)
{ 
	long long* temp = *min;
	*min = *max;
	*max = temp;
}
int main(void)
{
	long long min = 0, max = 0, result =0,i=1;
	scanf("%lld %lld", &min, &max);
	if (min > max)
	{
		swap(&min, &max);
	}
	while (1)
	{
		if (((max * i) % min) == 0)
		{
			max = max * i;
			break;
		}
		else
			i++;
	}
	printf("%lld", max);
}
