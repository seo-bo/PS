#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	int end = 0, prob = 0, day = 0;
	scanf("%d %d %d", &end, &prob, &day);
	if (end >= prob * day)
	{
		end -= prob * day;
		printf("%d %d", end, end + prob - 1);
	}
	else if (end < prob * day)
	{
		if (end <= prob)
		{
			printf("0 %d", end - 1);
		}
		else
		{
			printf("0 %d", (end - (prob * (day - 1))) - 1);
		}
	}
}