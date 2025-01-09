#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare(const char* num1, const char* num2)
{
	if (*(int*)num1 > *(int*)num2)
	{
		return -1;
	}
	if (*(int*)num1 < *(int*)num2)
	{
		return 1;
	}
	else
		return 0;
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	while (1)
	{
		if (num == 0)
		{
			break;
		}
		int ary[10] = { 0, };
		for (int i = 0; i < 10; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, 10, sizeof(int), compare);
		printf("%d\n",ary[2]);
		num--;
	}
}

