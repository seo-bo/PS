#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[1000001] = { 0,};
int func(int num)
{
	if (num <= 2)
	{
		return num;
	}
	else if (ary[num] == 0)
	{
		return ary[num] = ((func(num - 1) + func(num - 2)) % 15746);
	}
	else
		return ary[num];
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int result = func(num);
	printf("%d", result);

}
