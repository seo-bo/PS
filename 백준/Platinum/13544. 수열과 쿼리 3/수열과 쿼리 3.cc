#include <bits/stdc++.h>
using namespace std;

int ary[100001] = { 0, };
vector<int>tree[100010 * 4];

void init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node].push_back(ary[start]);
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	vector<int>& left = tree[node * 2];
	vector<int>& right = tree[node * 2 + 1];
	tree[node].resize(left.size() + right.size());
	merge(left.begin(), left.end(), right.begin(), right.end(), tree[node].begin());
}

int query(int start, int end, int node, int left, int right, int value)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right, value) + query(mid + 1, end, node * 2 + 1, left, right, value);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0, last_ans = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i)
	{
		cin >> ary[i];
	}
	init(1, num, 1);
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		int start = 0, end = 0, value = 0;
		cin >> start >> end >> value;
		start ^= last_ans;
		end ^= last_ans;
		value ^= last_ans;
		last_ans = query(1, num, 1, start, end, value);
		cout << last_ans << "\n";
	}
}