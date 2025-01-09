#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct XY
{
	int x;
	int y;
}XY;

XY ary[500010];

int compare(const void* num1, const void* num2)
{
	if (((XY*)num1)->x == ((XY*)num2)->x)
	{
		return ((XY*)num1)->y - ((XY*)num2)->y;
	}
	else
	{
		return ((XY*)num1)->x - ((XY*)num2)->x;
	}
}


int main(void)
{
	int chess = 0, da = 0, count = 0, k = 0;
	scanf("%d %d", &chess, &da);
	for (int i = 0; i < da; i++)
	{
		int posx = 0, posy = 0;
		scanf("%d %d", &posx, &posy);
		ary[k].x = posx; ary[k].y = posy; k++;
		if (posx - 2 > 0)
		{
			ary[k].x = posx - 2;
			ary[k].y = posy;
			k++;
		}
		if (posx + 2 <= chess)
		{
			ary[k].x = posx + 2;
			ary[k].y = posy;
			k++;
		}
		if (posy - 2 > 0)
		{
			ary[k].x = posx;
			ary[k].y = posy - 2;
			k++;
		}
		if (posy + 2 <= chess)
		{
			ary[k].x = posx;
			ary[k].y = posy + 2;
			k++;
		}
	}
	qsort(ary, k, sizeof(XY), compare);
	ary[k + 1].x = -1; ary[k + 1].y = -1;
	for (int i = 0; i < k; i++)
	{
		if ((ary[i].x != ary[i+1].x) || (ary[i].y != ary[i+1].y))
		{
			count++;
		}
	}
	printf("%d", count-da);
}