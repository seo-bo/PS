#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, sum = 0;
	cin >> n >> m;
	string ans;
	unordered_map<char, int>mm;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int k = 0; k < m; ++k)
	{
		int temp = -1;
		char tp = 'Z';
		for (int i = 0; i < n; ++i)
		{
			mm[v[i][k]]++;
		}
		for (auto& i : mm)
		{
			if (i.second > temp)
			{
				temp = i.second;
				tp = i.first;
			}
			else if (i.second == temp)
			{
				tp = min(tp, i.first);
			}
		}
		sum += n - temp, ans += tp;
		unordered_map<char, int>().swap(mm);
	}
	cout << ans << '\n' << sum;
	return 0;
}