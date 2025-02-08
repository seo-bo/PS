#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>>ary;
vector<ll>tree;

void update(int start, int end, int node, int idx)
{
	if (idx < start || idx > end)
	{
		return;
	}
	tree[node] += 1;
	if (start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx);
	update(mid + 1, end, node * 2 + 1, idx);
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
	cin >> num;
	ary.resize(num);
	tree.resize(num * 4);
	for (int i = 0; i < num; i++)
	{
		cin >> ary[i].first;
		ary[i].second = i;
	}
	sort(ary.begin(), ary.end());
	for (int i = 0; i < num; i++) //실력 순으로 정렬 하고 상대적 실력 매기기
	{
		ary[i].first = i;
	}
	sort(ary.begin(), ary.end(), [](const pair<int, int>& a, const pair<int, int>& b) // 다시 인덱스로 돌아오기
		{
			return a.second < b.second;
		});
	for (int i = 1; i <= num; i++)
	{
		cout << i - query(0, num - 1, 1, 0, ary[i - 1].first) << "\n";
		update(0, num - 1, 1, ary[i - 1].first);
	}
	return 0;
}