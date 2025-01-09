#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct value
{
	int idx;
	ll number;
};

value ary[100010]; 
value tree [100010 * 4];

value mini(value num1, value num2)
{
	if (num1.number == num2.number)
	{
		return (num1.idx < num2.idx) ? num1 : num2;
	}
	return (num1.number < num2.number) ? num1 : num2;
}

value init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = mini(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

void update(int start, int end, int node, int idx, ll value)
{
	if (idx < start || idx > end)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		tree[node].number = value;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
	tree[node] = mini(tree[node * 2], tree[node * 2 + 1]);
}

value query(int start, int end, int node, int left, int right)
{
	if (right < start || left > end)
	{
		return { -1,LLONG_MAX };
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return mini(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i)
	{
		cin >> ary[i].number;
		ary[i].idx = i;
	}
	init(1, num, 1);
	cin >> test;
	for (int i = 0; i < num; ++i)
	{
		int temp = 0;
		cin >> temp;
		switch (temp)
		{
		case 1:
		{
			int index = 0;
			ll value = 0;
			cin >> index >> value;
			update(1, num, 1, index, value);
			break;
		}
		case 2:
		{
			cout << query(1, num, 1, 1, num).idx << "\n";
			break;
		}
		}
	}
	return 0;
}