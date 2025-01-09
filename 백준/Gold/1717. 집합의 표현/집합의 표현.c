#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int find(int* ary, int num)
{
	if(ary[num] == num)
	{
		return num;
	}
	return ary[num] = find(ary, ary[num]);
}

void Union(int* ary, int num1, int num2)
{
	num1 = find(ary, num1);
	num2 = find(ary, num2);
	if (num1 < num2)
	{
		ary[num2] = num1;
	}
	else
	{
		ary[num1] = num2;
	}
}


int main(void)
{
	int num = 0, test = 0;
	scanf("%d %d", &num, &test);
	int* ary = (int*)malloc(sizeof(int) * (num + 1));
	for (int i = 1; i <= num; i++)
	{
		ary[i] = i;
	}
	for (int i = 0; i < test; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		switch (temp)
		{
			case 0:
			{
				int get1 = 0, get2 = 0;
				scanf("%d %d", &get1, &get2);
				getchar();
				Union(ary, get1, get2);
				break;
			}
			case 1:
			{
				int get1 = 0, get2 = 0;
				scanf("%d %d", &get1, &get2);
				getchar();
				if (find(ary, get1) == find(ary, get2))
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
				break;
			}
		}
	}
	free(ary);
}
