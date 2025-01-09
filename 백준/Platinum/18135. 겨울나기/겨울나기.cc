#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>tree, lazy;
int check[2000001] = { 0, };
vector<ll>ary;

ll init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void lazy_update(int start, int end, int node)
{
	if (lazy[node])
	{
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int start, int end, int node, int left, int right, ll value)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1) * value;
		if (start != end)
		{
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end, int node, int left, int right)
{
	lazy_update(start, end, node);
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
	int num = 0, space = 0;
	cin >> num >> space;
	ary.resize(num);
	tree.resize(num * 4);
	lazy.resize(num * 4);
	for (int i = 0; i < space; i++)
	{
		int start = 0, end = 0, dotori = 0;
		cin >> start >> end >> dotori;
		if (i > 0)
		{
			for (int j = start; j <= end; j++)
			{
				check[j] = i;
			}
		}
		ary[i] = dotori;
	}
	init(0, space - 1, 1);
	while (1)
	{
		int temp = 0, start = 0, end = 0;
		cin >> temp >> start >> end;
		if (!temp && !start && !end)
		{
			return 0;
		}
		switch (temp)
		{
			case 1:
			{
				ll sum = 0;
				if (start > end)
				{
					sum += query(0, space - 1, 1, check[start], space - 1);
					sum += query(0, space - 1, 1, 0, check[end]);
					cout << sum << "\n";
				}
				else
				{
					cout << query(0, space - 1, 1, check[start], check[end]) << "\n";
				}
				break;
			}
			case 2:
			{
				ll value = 0;
				cin >> value;
				if (start > end)
				{
					update(0, space - 1, 1, check[start], space - 1, value);
					update(0, space - 1, 1, 0, check[end], value);
				}
				else
				{
					update(0, space - 1, 1, check[start], check[end], value);
				}
				break;
			}
		}
	}
	return 0;
}