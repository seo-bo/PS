#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(n - 1);
		bool check = true;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> v[i];
		}
		vector<ll>ans;
		ans.push_back(v[0]);
		for (int i = 0; i < n - 2; ++i)
		{
			int pre = ans.size() - 1;
			ans.push_back(v[i] | v[i + 1]);
			int siz = ans.size() - 1;
			if ((ans[pre] & ans[siz]) != v[i])
			{
				check = false;
				break;
			}
		}
		if (!check)
		{
			cout << -1 << '\n';
			continue;
		}
		ans.push_back(v[n - 2]);
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
