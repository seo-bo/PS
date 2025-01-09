#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<ll>tree;

void update(int start, int end, int node, int idx, int value)
{
	if (start > idx || end < idx)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		tree[node] += value;
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
	int T = 0;
	cin >> T;
	while (T--)
	{
		int B = 0, P = 0, Q = 0;
		cin >> B >> P >> Q;
		tree.resize((B + 5) * 4);
		for (int i = 0; i < P + Q; ++i)
		{
			char temp;
			int start = 0, end = 0;
			cin >> temp >> start >> end;
			switch (temp)
			{
			case 'P':
			{
				update(1, B, 1, start, end);
				break;
			}
			case 'Q':
			{
				cout << query(1, B, 1, start, end) << "\n";
				break;
			}
			}
		}
		vector<ll>().swap(tree);
	}

	return 0;
}
