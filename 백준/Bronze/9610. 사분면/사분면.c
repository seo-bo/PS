#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int num = 0, space1 = 0, space2 = 0, space3 = 0, space4 = 0, axis = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		if (x == 0 || y == 0)
		{
			axis++;
		}
		else if (x > 0 && y > 0)
		{
			space1++;
		}
		else if (x > 0 && y < 0)
		{
			space4++;
		}
		else if (x < 0 && y > 0)
		{
			space2++;
		}
		else if (x < 0 && y < 0)
		{
			space3++;
		}
	}
	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", space1, space2, space3, space4, axis);
}


