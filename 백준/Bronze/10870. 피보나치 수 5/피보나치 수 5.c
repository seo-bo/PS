#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	if (num == 0)
	{
		printf("%d", 0);
		return 0;
	}
	if (num == 1)
	{
		printf("%d", 1);
		return 0;
	}
	int fir = 0, sec = 1, ph = 0,count = 1;
	while (1)
	{
		if (count == num)
		{
			break;
		}
		ph = fir + sec;
		fir = sec;
		sec = ph;
		count++;
	}
	printf("%d", ph);
}

