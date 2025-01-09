#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int parent[1000001] = { 0, };

int find(int num)
{
	if (parent[num] == num)
	{
		return num;
	}
	return parent[num] = find(parent[num]);
}

void Union(int num1, int num2)
{
	int root1 = find(num1);
	int root2 = find(num2);
	if (root1 != root2)
	{
		parent[root1] = root2;
	}
}
int main(void)
{
	int count = 0, room = 0, test = 0;
	scanf("%d %d", &room, &test);
	getchar();
	int result = room;
	for (int i = 1; i <= room; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < test; i++)
	{
		int start = 0, end = 0;
		scanf("%d %d", &start, &end);
		getchar();
		while (find(start) != find(end))
		{
			int temp = find(start) + 1;
			Union(start, end);
			parent[start] = temp; // 제일 오른쪽 루트 찾기(분리집합 원소의 크기가 클 수록 루트)
			result--;
		}
	}
	printf("%d", result);
}
