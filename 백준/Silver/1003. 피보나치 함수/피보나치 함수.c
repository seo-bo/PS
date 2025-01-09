#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fibo[41][2] = { 0, };

int main(void)
{
	int test = 0, num =0;
	scanf("%d", &test);
	fibo[0][0] = 1, fibo[0][1] = 0;
	fibo[1][0] = 0, fibo[1][1] = 1;
	for (int i = 2; i < 41; i++)
	{
		fibo[i][0] = fibo[i - 2][0] + fibo[i - 1][0];
		fibo[i][1] = fibo[i - 2][1] + fibo[i - 1][1];
	}
	for (int i = 0; i < test; i++)
	{
		scanf("%d", &num);
		printf("%d %d\n", fibo[num][0], fibo[num][1]);
	}
}


