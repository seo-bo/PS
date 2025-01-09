#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m = 0, q = 0;
		cin >> n >> m >> q;
		vector<ll>a(n), b(m);
		for (auto& i : a)
		{
			cin >> i;
		}
		for (auto& i : b)
		{
			cin >> i;
		}
		vector<int>v(n + 1, m + 1);
		for (int i = 0; i < m; ++i)
		{
			if (v[b[i]] == m + 1)
			{
				v[b[i]] = i + 1;
			}
		}
		bool check = true;
		ll pivot = 0;
		for (auto& i : a)
		{
			if (v[i] < pivot)
			{
				check = false;
				break;
			}
			if (v[i] > pivot)
			{
				pivot = v[i];
			}
		}
		if (check)
		{
			cout << "YA" << '\n';
		}
		else
		{
			cout << "TIDAK" << '\n';
		}
	}
	return 0;
}
