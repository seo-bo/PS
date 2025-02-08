#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = INT_MAX;
	cin >> n;
	string z, x;
	cin >> z >> x;
	vector<int>s1, s2;
	for (int i = 0; i < n; ++i)
	{
		s1.push_back(z[i] - '0');
		s2.push_back(x[i] - '0');
	}
	auto c = [&](vector<int> a, vector<int> b, bool f)
		{
			int cnt = 0;
			if (f)
			{
				a[0] = !a[0];
				a[1] = !a[1];
				cnt++;
			}
			for (int i = 1; i < n; ++i)
			{
				if (a[i - 1] != b[i - 1])
				{
					cnt++;
					for (int j = 0; j < 3 && i - 1 + j < n; ++j)
					{
						a[i - 1 + j] = !a[i - 1 + j];
					}
				}
			}
			if (a == b)
			{
				ans = min(ans, cnt);
			}
		};
	c(s1, s2, true);
	c(s1, s2, false);
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}