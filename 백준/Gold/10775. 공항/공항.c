#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int gate[100001] = { 0, };
int airplane[100001] = { 0, };
long long result = 0;

int find(int num)
{
	if (num == gate[num])
	{
		return num;
	}
	else
	{
		gate[num] = find(gate[num]);
		return gate[num];
	}
}

int Union(int num)
{
	int temp = find(num);
	if (temp == 0)
	{
		return -1;
	}
	else
	{
		gate[temp] = find(temp - 1);
		result++;
		return 1;
	}
}

int main(void)
{
	int gatenum = 0, airnum = 0;
	scanf("%d %d", &gatenum, &airnum);
	getchar();
	for (int i = 1; i <= gatenum; i++)
	{
		gate[i] = i;
	}
	for (int i = 1; i <= airnum; i++)
	{
		scanf("%d", &airplane[i]);
		
	}
	for (int i = 1; i <= airnum; i++)
	{
		int get = Union(airplane[i]);
		if (get == -1)
		{
			printf("%lld", result);
			return 0;
		}
	}
	printf("%lld", result);
}