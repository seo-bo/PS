#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[1000001] = { 0, };
int main(void)
{
	int num = 0, len = 0, in =0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int get = 0;
		scanf("%d", &get);
		switch (get)
		{
		case 1:
			scanf("%d", &in);
			ary[len] = in;
			len++;
			break;
		case 2:
			if (len == 0)
			{
				printf("%d\n", -1);
			}
			else
			{
				printf("%d\n", ary[len - 1]);
				ary[len - 1] = 0;
				len--;
			}
			break;
		case 3:
			printf("%d\n", len);
			break;
		case 4:
			if (len == 0)
			{
				printf("%d\n", 1);
			}
			else
			{
				printf("%d\n", 0);
			}
			break;
		case 5:
			if (len == 0)
			{
				printf("%d\n", -1);
			}
			else
			{
				printf("%d\n", ary[len - 1]);
			}
			break;
		}
	}
}