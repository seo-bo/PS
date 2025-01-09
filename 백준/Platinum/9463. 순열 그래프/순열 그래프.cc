#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<int, int>sorted;
vector<int>tree;

void update(int start, int end, int node, int idx)
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
	update(start, mid, node * 2, idx);
	update(mid + 1, end, node * 2 + 1, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end, int node, int left, int right)
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
		ll result = 0;
		int num = 0;
		cin >> num;
		tree.resize((num + 10) * 4);
		for (int i = 0; i < num; ++i)
		{
			int temp = 0;
			cin >> temp;
			sorted.insert(make_pair(temp, i));
		}
		for (int i = 0; i < num; ++i)
		{
			int temp = 0;
			cin >> temp;
			result += query(0, num - 1, 1, sorted[temp], num - 1);
			update(0, num - 1, 1, sorted[temp]);
		}
		cout << result << "\n";
		unordered_map<int, int>().swap(sorted);
		vector<int>().swap(tree);
	}
	return 0;
}