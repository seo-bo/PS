#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 위에 있는게 정렬된 결과라고 생각하고, 밑에 있는게 정렬 안된거?

void update(int tree[], int start, int end, int node, int idx)
{
	if (idx > end || idx < start)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;
	update(tree, start, mid, node * 2, idx);
	update(tree, mid + 1, end, node * 2 + 1, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int* tree, int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(tree, start, mid, node * 2, left, right) + query(tree, mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
	long long result = 0;
	int num = 0, temp = 0;
	scanf("%d", &num);
	int* sorted = (int*)calloc(1000001, sizeof(int));
	int* tree = (int*)calloc((num + 1) * 4, sizeof(int));
	for (int i = 1; i <= num; ++i)
	{
		scanf("%d", &temp);
		sorted[temp] = i;
	}
	for (int i = 0; i < num; ++i)
	{
		scanf("%d", &temp);
		result += query(tree, 1, num, 1, sorted[temp] + 1, num);
		update(tree, 1, num, 1, sorted[temp]);
	}
	printf("%lld", result);
	free(sorted);
	free(tree);
}