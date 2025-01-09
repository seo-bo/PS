#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>>ary;
vector<int>tree;

void update(int start, int end, int node, int idx)
{
	if (idx < start || idx > end)
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
	int num = 0;
	ll result = 0;
	cin >> num;
	ary.resize(num);
	tree.resize((num + 1) * 4);
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i].first;
		ary[i].second = i;
	}
	sort(ary.begin(), ary.end());
	for (int i = 0; i < num; i++)
	{
		ary[i].first = i;
	}
	sort(ary.begin(), ary.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			return a.second < b.second;
		});
	for (auto i : ary)
	{
		result += query(0, num - 1, 1, i.first, num - 1);
		update(0, num - 1, 1, i.first);
	}
	cout << result;
	return 0;
}