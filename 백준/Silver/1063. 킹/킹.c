#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char king[3];
char dol[3];

typedef struct Point
{
	char x;
	int y;
}Point;

int main(void)
{
	Point* ary = (Point*)malloc(sizeof(Point));
	int move = 0;
	scanf("%s %s %d", king, dol, &move);
	ary[0].x = king[0], ary[0].y = king[1] - '0';
	ary[1].x = dol[0], ary[1].y = dol[1] - '0';
	for (int i = 0; i < move; i++)
	{
		char order[3] = { 0, };
		scanf("%s", order);
		if (!strcmp(order, "R"))
		{
			char next_x = ary[0].x + 1;
			if (next_x > 'H')
			{
				continue;
			}
			ary[0].x = next_x;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				char next_xx = ary[1].x + 1;
				if (next_xx > 'H')
				{
					ary[0].x -= 1;
					continue;
				}
				ary[1].x = next_xx;
			}
		}
		else if (!strcmp(order, "L"))
		{
			char next_x = ary[0].x - 1;
			if (next_x < 'A')
			{
				continue;
			}
			ary[0].x = next_x;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				char next_xx = ary[1].x - 1;
				if (next_xx < 'A')
				{
					ary[0].x += 1;
					continue;
				}
				ary[1].x = next_xx;
			}
		}
		else if (!strcmp(order, "B"))
		{
			int next_y = ary[0].y - 1;
			if (next_y < 1)
			{
				continue;
			}
			ary[0].y = next_y;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				int next_yy = ary[1].y - 1;
				if (next_yy < 1)
				{
					ary[0].y += 1;
					continue;
				}
				ary[1].y = next_yy;
			}
		}
		else if (!strcmp(order, "T"))
		{
			int next_y = ary[0].y + 1;
			if (next_y > 8)
			{
				continue;
			}
			ary[0].y = next_y;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				int next_yy = ary[1].y + 1;
				if (next_yy > 8)
				{
					ary[0].y -= 1;
					continue;
				}
				ary[1].y = next_yy;
			}
		}
		else if (!strcmp(order, "RT"))
		{
			char next_x = ary[0].x + 1;
			int next_y = ary[0].y + 1;
			if (next_x > 'H' || next_y > 8)
			{
				continue;
			}
			ary[0].x = next_x, ary[0].y = next_y;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				char next_xx = ary[1].x + 1;
				int next_yy = ary[1].y + 1;
				if (next_xx > 'H'|| next_yy > 8)
				{
					ary[0].x -= 1;
					ary[0].y -= 1;
					continue;
				}
				ary[1].x = next_xx;
				ary[1].y = next_yy;
			}
		}
		else if (!strcmp(order, "LT"))
		{
			char next_x = ary[0].x - 1;
			int next_y = ary[0].y + 1;
			if (next_x < 'A' || next_y > 8)
			{
				continue;
			}
			ary[0].x = next_x, ary[0].y = next_y;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				char next_xx = ary[1].x - 1;
				int next_yy = ary[1].y + 1;
				if (next_xx < 'A' || next_yy > 8)
				{
					ary[0].x += 1;
					ary[0].y -= 1;
					continue;
				}
				ary[1].x = next_xx;
				ary[1].y = next_yy;
			}
		}
		else if (!strcmp(order, "RB"))
		{
			char next_x = ary[0].x + 1;
			int next_y = ary[0].y - 1;
			if (next_x > 'H' || next_y < 1)
			{
				continue;
			}
			ary[0].x = next_x, ary[0].y = next_y;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				char next_xx = ary[1].x + 1;
				int next_yy = ary[1].y - 1;
				if (next_xx > 'H' || next_yy < 1)
				{
					ary[0].x -= 1;
					ary[0].y += 1;
					continue;
				}
				ary[1].x = next_xx;
				ary[1].y = next_yy;
			}
		}
		else if (!strcmp(order, "LB"))
		{
			char next_x = ary[0].x - 1;
			int next_y = ary[0].y - 1;
			if (next_x < 'A' || next_y < 1)
			{
				continue;
			}
			ary[0].x = next_x, ary[0].y = next_y;
			if (ary[0].x == ary[1].x && ary[0].y == ary[1].y)
			{
				char next_xx = ary[1].x - 1;
				int next_yy = ary[1].y - 1;
				if (next_xx < 'A' || next_yy < 1)
				{
					ary[0].x += 1;
					ary[0].y += 1;
					continue;
				}
				ary[1].x = next_xx;
				ary[1].y = next_yy;
			}
		}
	}
	printf("%c%d\n%c%d", ary[0].x, ary[0].y, ary[1].x, ary[1].y);
}
