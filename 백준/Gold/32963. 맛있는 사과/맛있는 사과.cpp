#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0, idx = 0;
	cin >> n >> q;
	vector<pii>v(n);
	for (auto& [a, _] : v)
	{
		cin >> a;
	}
	for (auto& [_, a] : v)
	{
		cin >> a;
	}
	sort(v.rbegin(), v.rend());
	vector<pii>query(q);
	vector<int>res(q);
	for (int i = 0; i < q; ++i)
	{
		cin >> query[i].first;
		query[i].second = i;
	}
	sort(query.rbegin(), query.rend());
	int cnt = 0, pivot = 0;
	for (auto& [a, b] : query)
	{
		while (idx < n && v[idx].first >= a)
		{
			if (v[idx].second > pivot)
			{
				pivot = v[idx].second;
				cnt = 1;
			}
			else if (v[idx].second == pivot)
			{
				cnt++;
			}
			idx++;
		}
		res[b] = cnt;
	}
	for (auto& i : res)
	{
		cout << i << '\n';
	}
	return 0;
}