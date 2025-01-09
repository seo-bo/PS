#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//오류나기 쉬우니까 차라리 함수안에서 최솟값 비교하는거보다 비교만 하는 함수 만들어버리자!
//https://h202.tistory.com/314 당신은 천재야..!

typedef struct value
{
	long long number;
	long long index;
}value;

value tree[4 * 100001] = { 0, };
value ary[100001] = { 0, };

value mini(value num1, value num2)
{
	if (num1.number == num2.number)
	{
		return (num1.index < num2.index) ? num1: num2;
	}
	return (num1.number < num2.number) ? num1 : num2;
}

value init(long long start, long long end, long long node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	long long mid = (start + end) / 2;
	return tree[node] = mini(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

value query(long long start, long long end, long long node, long long left, long long right)
{
	if (left > end || right < start)
	{
		return (value) { 9223372036854775807, -1 };
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	long long mid = (start + end) / 2;
	return mini(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

void update(long long start, long long end, long long node, long long idx, long long change)
{
	if (idx < start || idx > end)
	{
		return;
	}
	if (start == end)
	{
		tree[node] = (value){ change,idx };
		return;
	}
	long long mid = (start + end) / 2;
	update(start, mid, node * 2, idx, change);
	update(mid + 1, end, node * 2 + 1, idx, change);
	tree[node] = mini(tree[node * 2], tree[node * 2 + 1]);
}

int main(void)
{
	int num = 0, test = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i].number);
		ary[i].index = i;
	}
	init(0, num - 1, 1);
	scanf("%d", &test);
	getchar();
	for (int i = 0; i < test; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		getchar();
		switch (temp)
		{
		case 1:
		{
			int idx = 0, change = 0;
			scanf("%d %d", &idx, &change);
			getchar();
			update(0, num - 1, 1, idx - 1, change);
			break;
		}
		case 2:
		{
			value result;
			int start = 0, end = 0;
			scanf("%d %d", &start, &end);
			getchar();
			result = query(0, num - 1, 1, start - 1, end - 1);
			printf("%lld\n", result.index + 1);
			break;
		}
		}
	}
}