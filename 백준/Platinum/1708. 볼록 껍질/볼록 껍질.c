#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long head = -1;
long long stack[100001] = { 0, };

void push(long long num)
{
	stack[++head] = num;
}

typedef struct Point
{
	long long x;
	long long y;
}Point;

Point p0;

long long dist(Point p1, Point p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(Point p, Point q, Point r) //https://www.acmicpc.net/blog/view/27의 도움을 받음.
{
	long long temp = p.x * q.y + q.x * r.y + r.x * p.y;
	temp = temp - p.y * q.x - q.y * r.x - r.y * p.x;
	if (temp > 0)
	{
		return 1;
	}
	else if (temp < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int compare(const void* num1, const void* num2)
{
	long long temp = ccw(p0, *(Point*)num1, *(Point*)num2);
	if (temp == 0)
	{
		return (dist(p0, *(Point*)num2) >= dist(p0, *(Point*)num1)) ? -1 : 1;
	}
	return (temp == 1) ? -1 : 1;
}

void swap(Point* num1, Point* num2)
{
	Point temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

long long convex(Point* ary, long long num)
{
	long long ymin = ary[0].y, min = 0;
	for (long long i = 1; i < num; i++)
	{
		long long y = ary[i].y;
		if ((y < ymin) || (ymin == y && ary[i].x < ary[min].x))
		{
			ymin = ary[i].y, min = i;
		}
	}
	swap(&ary[0], &ary[min]);
	p0 = ary[0];
	qsort(&ary[1], num - 1, sizeof(Point), compare);
	long long get = 1;
	for (long long i = 1; i < num; i++)
	{
		while (i < num - 1 && ccw(p0, ary[i], ary[i + 1]) == 0)
		{
			i++;
		}
		ary[get] = ary[i];
		get++;
	}
	for (long long i = 0; i < 3; i++)
	{
		push(i);
	}
	for (long long i = 3; i < get; i++)
	{
		while (ccw(ary[stack[head - 1]], ary[stack[head]], ary[i]) != 1)
		{
			head--;
		}
		push(i);
	}
	return head + 1;
}

int main(void)
{
	long long num = 0, min = 50000, idx = 500001;
	scanf("%lld", &num);
	Point* ary = (Point*)malloc(sizeof(Point) * num);
	for (long long i = 0; i < num; i++)
	{
		scanf("%lld %lld", &ary[i].x, &ary[i].y);
	}
	printf("%lld", convex(ary, num));
	free(ary);
}
