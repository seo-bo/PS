#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tree[1000010 * 4];

void update(int start, int end, int node, int idx, ll value)
{
	if (idx > end || idx < start)
	{
		return;
	}
	tree[node] += value;
	if (idx <= start && end <= idx)
	{
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end, int node, int left, ll right)
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
	int num = 0, test = 0;
	cin >> num >> test;
	for (int i = 0; i < test; ++i)
	{
		int temp = 0, start = 0;
		ll end = 0;
		cin >> temp >> start >> end;
		switch (temp)
		{
		case 1:
		{
			update(1, num, 1, start, end);
			break;
		}
		case 2:
		{
			cout << query(1, num, 1, start, end) << "\n";
			break;
		}
		}
	}
	return 0;
}