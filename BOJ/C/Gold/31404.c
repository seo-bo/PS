#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int result = 0, tempresult = 0, cleanStart = 0;

typedef struct pos
{
	int h, w, direction;
}pos;

int where[1025][1025] = { 0, };
int visited[1025][1025][4] = { 0, };
int way[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
char A[1025][1025];
char B[1025][1025];

int main(void)
{
	pos Aris = { 0,0,0 };
	pos before;
	int H = 0, W = 0;
	int nodust = 0;
	scanf("%d %d", &H, &W);
	getchar();
	scanf("%d %d %d", &Aris.h, &Aris.w, &Aris.direction);
	getchar();
	for (int i = 0; i < H; i++)
	{
		scanf("%s", A[i]);
	}
	for (int i = 0; i < H; i++)
	{
		scanf("%s", B[i]);
	}
	while (1)
	{
		if (where[Aris.h][Aris.w] == 0)
		{
			result += tempresult;
			nodust = 0, tempresult = 0;
			where[Aris.h][Aris.w] = 1;
			cleanStart = result;
			Aris.direction = (Aris.direction + A[Aris.h][Aris.w] - '0') % 4;
			int new_h = Aris.h + way[Aris.direction][0];
			int new_w = Aris.w + way[Aris.direction][1];
			if (!(new_h >= 0 && new_h < H && new_w >= 0 && new_w < W))
			{
				result++;
				break;
			}
			Aris.h = new_h;
			Aris.w = new_w;
			before.h = Aris.h;
			before.w = Aris.w;
			before.direction = Aris.direction;
			result++;
		}
		else if (where[Aris.h][Aris.w] == 1)
		{
			tempresult++;
			Aris.direction = (Aris.direction + B[Aris.h][Aris.w] - '0') % 4;
			int new_h = Aris.h + way[Aris.direction][0];
			int new_w = Aris.w + way[Aris.direction][1];
			if (!(new_h >= 0 && new_h < H && new_w >= 0 && new_w < W))
			{
				break;
			}
			if (visited[new_h][new_w][Aris.direction] > cleanStart)
			{
				break;
			}
			visited[new_h][new_w][Aris.direction] = result;
			Aris.h = new_h;
			Aris.w = new_w;
			before.h = Aris.h;
			before.w = Aris.w;
			before.direction = Aris.direction;
		}
	}
	printf("%d", result);
}
