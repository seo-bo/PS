#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long ary[101] = { 0,};
int main(void)
{
	ary[1] = 1;
	ary[2] = 1;
	ary[3] = 1;
	for (int i = 4; i < 101; i++)
	{
		ary[i] = ary[i - 3] + ary[i - 2];
	}
	int num = 0, test = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &test);
		printf("%lld\n", ary[test]);
	}
}
