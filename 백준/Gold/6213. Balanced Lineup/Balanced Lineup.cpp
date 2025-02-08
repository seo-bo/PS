#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>>tree; // first = MIN , second = MAX
vector<int>ary;
pair<ll, ll> result;

pair<ll, ll> init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = { ary[start], ary[start] };
	}
	int mid = (start + end) / 2;
	pair<ll, ll>left = init(start, mid, node * 2);
	pair<ll, ll>right = init(mid + 1, end, node * 2 + 1);
	tree[node].first = min(left.first, right.first);
	tree[node].second = max(left.second, right.second);
	return tree[node];
}

pair<ll, ll> query(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
	{
		return { INT_MAX, INT_MIN };
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	pair<ll, ll>lleft = query(start, mid, node * 2, left, right);
	pair<ll, ll>rright = query(mid + 1, end, node * 2 + 1, left, right);
	result.first = min(lleft.first, rright.first);
	result.second = max(lleft.second, rright.second);
	return result;
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num >> test;
	ary.resize(num + 10);
	tree.resize((num + 10) * 4);
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i];
	}
	init(0, num - 1, 1);
	for (int i = 0; i < test; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		start--;
		end--;
		pair<ll, ll>result = query(0, num - 1, 1, start, end);
		cout << llabs(result.first - result.second) << "\n";
	}
	return 0;
}