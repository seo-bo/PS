#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Pos
{
	long long ph;
	long long pw;
	long long pd;
	long long pds;
}Pos;

long long H = 0, W = 0;
int direction[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int map[1025][1025] = { 0, };
long long stack[1025 * 1025 * 4] = { 0, };
long long total = 0;

long long change_num(long long h, long long w, long long d)
{
	return 4 * W * h + 4 * w + d;
}

Pos change_pos(long long changed)
{
	return (Pos) { changed / (4 * W), changed / 4 % W, changed % 4 , -1 };
}

long long findandupdate(long long num, long long* parent, long long* height)
{
	int head = -1;
	while (num != parent[num])
	{
		stack[++head] = num;
		num = parent[num];
	}
	long long get_sum = 0;
	for (int i = head; i >= 0; --i)
	{
		get_sum += height[stack[i]];
		height[stack[i]] = get_sum;
		parent[stack[i]] = num;
	}
	return num;
}

long long find(long long root, long long* parent, long long* height)
{
	if (parent[root] == root)
	{
		return 0;
	}
	return height[root] + find(parent[root], parent, height);
}

void Union(long long root1, long long root2, long long* parent, long long* height)
{
	parent[root1] = root2;
	height[root1] = 1;
}

Pos next_point(long long h, long long w, long long d, char** A, char** B)
{
	int get_rotate = !map[h][w] ? A[h][w] - '0' : B[h][w] - '0';
	int rotate = (d + get_rotate) % 4;
	return (Pos) { h + direction[rotate][0], w + direction[rotate][1], rotate, -1 };
}

Pos Move(long long h, long long  w, long long d, long long* parent, long long* height, char** A, char** B)
{
	long long distance = 0;
	while (1)
	{
		long long changed1 = change_num(h, w, d);
		long long rootnum = findandupdate(changed1, parent, height);
		Pos point1 = change_pos(rootnum);
		distance += find(changed1, parent, height);
		Pos point2 = next_point(point1.ph, point1.pw, point1.pd, A, B);
		long long changed2 = change_num(point2.ph, point2.pw, point2.pd);
		if (point2.ph < 0 || point2.ph >= H || point2.pw < 0 || point2.pw >= W)
		{
			return (Pos) { -1, -1, -1, -1 };
		}
		if (!map[point2.ph][point2.pw])
		{
			return (Pos) { point2.ph, point2.pw, point2.pd, ++distance };
		}
		if (findandupdate(rootnum, parent, height) == findandupdate(changed2, parent, height))
		{
			return (Pos) { -1, -1, -1, -1 };
		}
		Union(rootnum, changed2, parent, height);
		h = point2.ph;
		w = point2.pw;
		d = point2.pd;
		distance++;
	}
}

int main(void)
{
	long long Aris_H = 0, Aris_W = 0, Aris_D = 0;
	long long result = 0;
	scanf("%lld %lld", &H, &W);
	getchar();
	scanf("%lld %lld %lld", &Aris_H, &Aris_W, &Aris_D);
	getchar();
	char** A = (char**)calloc(H, sizeof(char*));
	for (int i = 0; i < H; ++i)
	{
		A[i] = calloc(W + 1, sizeof(char));
	}
	char** B = (char**)calloc(H, sizeof(char*));
	for (int i = 0; i < H; ++i)
	{
		B[i] = calloc(W + 1, sizeof(char));
	}
	for (int i = 0; i < H; ++i)
	{
		scanf("%s", A[i]);
		getchar();
	}
	for (int i = 0; i < H; ++i)
	{
		scanf("%s", B[i]);
		getchar();
	}
	total = H * W * 4;
	long long* parent = (long long*)malloc(sizeof(long long) * total);
	long long* height = (long long*)malloc(sizeof(long long) * total);
	for (int i = 0; i < total; ++i)
	{
		parent[i] = i;
		height[i] = i;
	}
	while (0 <= Aris_H && Aris_H < H && 0 <= Aris_W && Aris_W < W)
	{
		if (map[Aris_H][Aris_W])
		{
			Pos temp = Move(Aris_H, Aris_W, Aris_D, parent, height, A, B);
			if (temp.ph < 0)
			{
				break;
			}
			Aris_H = temp.ph;
			Aris_W = temp.pw;
			Aris_D = temp.pd;
			result += temp.pds;
		}
		Pos temp = next_point(Aris_H, Aris_W, Aris_D, A, B);
		map[Aris_H][Aris_W] = 1;
		++result;
		Aris_H = temp.ph;
		Aris_W = temp.pw;
		Aris_D = temp.pd;
	}
	printf("%lld", result);
	return 0;
}