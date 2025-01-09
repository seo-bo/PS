#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Sort
{
	int number;
	int newnumber;
	int index;
}Sort;

void update(int tree[], int start, int end, int node, int idx)
{
	if (idx > end || start > idx)
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
	if (left > end || start > right)
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


int compare(const void* num1, const void* num2)
{
	return ((Sort*)num1)->number - ((Sort*)num2)->number;
}

int backcompare(const void* num1, const void* num2)
{
	return ((Sort*)num1)->index - ((Sort*)num2)->index;
}

int main(void)
{
	long long result = 0;
	int num = 0, count = 1;
	scanf("%d", &num);
	Sort* ary = (Sort*)calloc((num + 1), sizeof(Sort));
	int* tree = (int*)calloc((num + 1) * 5, sizeof(int));
	for (int i = 1; i <= num; ++i)
	{
		scanf("%d", &ary[i].number);
		ary[i].index = i;
	}
	qsort(ary + 1, num, sizeof(Sort), compare); // 좌표 압축 해줘야하나?
	ary[1].newnumber = 1;
	for (int i = 2; i <= num; ++i)
	{
		if (ary[i].number != ary[i - 1].number)
		{
			count++;
		}
		ary[i].newnumber = count;
	}
	qsort(ary + 1, num, sizeof(Sort), backcompare);
	for (int i = 1; i <= num; ++i)
	{
		result += query(tree, 1, num, 1, ary[i].newnumber + 1, count);
		update(tree, 1, num, 1, ary[i].newnumber);
	}
	printf("%lld", result);
	free(ary);
	free(tree);
}