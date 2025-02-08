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
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>parent(n + 1, 0);
	vector<ll>prefix(n + 1, 0);
	set<int, greater<int>>s;
	for (int i = 1; i <= n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			s.insert(b);
		}
		else
		{
			cin >> b >> c;
			auto it = s.upper_bound(c);
			if (it == s.end())
			{
				cout << prefix[c] - prefix[b - 1] << '\n';
				continue;
			}
			else if (*it == c)
			{
				it--;
			}
			if (b <= *it && *it <= c)
			{
				cout << prefix[c] - prefix[*it] << '\n';
			}
			else
			{
				cout << prefix[c] - prefix[b - 1] << '\n';
			}
		}
	}
	return 0;
}