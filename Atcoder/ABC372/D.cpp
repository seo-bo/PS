#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 이거 모노톤 스택 문제!???
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<ll>s, diff(n + 2, 0), temp(n, 0);
	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() && v[s.back()] <= v[i])
		{
			s.pop_back();
		}
		if (!s.empty())
		{
			temp[i] = s.back() + 1;
		}
		else
		{
			temp[i] = 0;
		}
		s.push_back(i);
	}
	for (int i = 0; i < n; ++i)
	{
		ll tt = 1;
		if (temp[i] >= 1)
		{
			tt = temp[i];
		}
		if (tt <= i)
		{
			diff[tt]++;
			diff[i + 1]--;
		}
	}
	vector<ll>ans(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		ans[i] = ans[i - 1] + diff[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
