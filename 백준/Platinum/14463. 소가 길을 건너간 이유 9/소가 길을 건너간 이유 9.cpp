#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cow
{
	int start, end;
};

vector<int>tree;
vector<cow>ary;

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

int query(int start, int end, int node, int left, int right)
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
	ll result = 0;
	int num = 0;
	cin >> num;
	ary.resize(num + 1, { 0,0, });
	tree.resize((num + 10) * 8, 0);
	for (int i = 1; i <= 2 * num; ++i)
	{
		int temp;
		cin >> temp;
		if (!ary[temp].start)
		{
			ary[temp].start = i;
		}
		else
		{
			ary[temp].end = i;
		}
	}
	sort(ary.begin(), ary.end(), [](const cow& a, const cow& b)
		{
			return a.start < b.start;
		});
	int siz = ary.size();
	for (int i = 1; i < siz; ++i)
	{
		result += query(1, num * 2 + 1, 1, ary[i].start, ary[i].end);
		update(1, num * 2 + 1, 1, ary[i].start);
		update(1, num * 2 + 1, 1, ary[i].end);
	}
	cout << result;
	return 0;
}