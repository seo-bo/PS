#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ary;
vector<int> tree;
int num = 0, movie = 0;

void init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int start, int end, int node, int idx, int value)
{
	if (start > idx || idx > end)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		tree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end, int node, int left, int right)
{
	if (start > right || left > end)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		cin >> num >> movie;
		ary.resize(num + 1);
		int size = num + movie + 2;
		tree.resize(size * 4);
		vector<int>create(size, 0);
		for (int i = 1; i <= num; ++i)
		{
			ary[num - i + 1] = i;
			create[i] = 1;
		}
		init(1, size, 1);
		for (int i = 0; i < movie; ++i)
		{
			int temp = 0;
			cin >> temp;
			ll result = query(1, size, 1, ary[temp] + 1, num);
			update(1, size, 1, ary[temp], 0);
			update(1, size, 1, ++num, 1);
			ary[temp] = num;
			cout << result << " ";
		}
		cout << "\n";
		vector<int>().swap(tree);
		vector<int>().swap(ary);
	}
	return 0;
}