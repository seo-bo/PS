#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int ary[1000001] = { 0, };
void prime()
{
	for (int i = 1; i <= 1000001; ++i)
	{
		ary[i] = 1;
	}
	ary[0] = 0;
	ary[1] = 0;
	for (int i = 2; i * i <= 1000001; ++i)
	{
		if (ary[i] == 1)
		{
			for (int j = i * i; j <= 1000001; j += i)
			{
				ary[j] = 0;
			}
		}
	}
	for (int i = 1; i <= 1000001; ++i)
	{
		ary[i] = ary[i - 1] + ary[i];
	}
}

int main(void)
{
	prime();
	int test = 0;
	scanf("%d", &test);
	while (test--)
	{
		int start = 0, end = 0;
		scanf("%d %d", &start, &end);
		printf("%d\n", ary[2 * end - 1] - ary[2 * start]);
	}
	return 0;
}