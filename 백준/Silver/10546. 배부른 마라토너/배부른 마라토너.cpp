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
	unordered_map<string, int>m;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		m[str]++;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		string str;
		cin >> str;
		m[str]--;
	}
	for (auto& i : m)
	{
		if (i.second > 0)
		{
			cout << i.first << '\n';
		}
	}
	return 0;
}