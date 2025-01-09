#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void) 
{
	int num = 0;
	scanf("%d", &num);
	int* ary = (int*)malloc(sizeof(int) * (num + 1));
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
	}
	int test = 0;
	scanf("%d", &test);
	for (int z = 0; z < test; z++)
	{
		int check = 0, where = 0;
		scanf("%d %d", &check, &where);
		if (check == 1)
		{
			for (int i = 1; i * where <= num; i++)
			{
				if (ary[i * where] == 0)
				{
					ary[i * where] = 1;
				}
				else
				{
					ary[i * where] = 0;
				}
			}
		}
		else
		{
			if (ary[where] == 0)
			{
				ary[where] = 1;
			}
			else
			{
				ary[where] = 0;
			}
			int size = Min(num - where, where - 1);
			for (int i = 1; i <= size; i++)
			{
				if (ary[where - i] == ary[where + i])
				{
					if (ary[where - i] == 0)
					{
						ary[where - i] = 1;
						ary[where + i] = 1;
					}
					else
					{
						ary[where - i] = 0;
						ary[where + i] = 0;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	for (int i = 1; i <= num; i++)
	{
		printf("%d ", ary[i]);
		if (i % 20 == 0)
		{
			printf("\n");
		}
	}
	free(ary);
}