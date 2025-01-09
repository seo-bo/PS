#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	vector<vector<ll>>v(100001);
	vector<bool>visited(100001, false);
	vector<ll>p(100001, 0);
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n >> k;
		if (!visited[k])
		{
			if (k == 1)
			{
				p[k] = 1;
				v[k].push_back(1);
				visited[k] = true;
			}
			else
			{
				ll p1 = 0, p2 = 1;
				int idx = 1;
				vector<ll>temp;
				while (1)
				{
					ll tt = (p1 + p2) % k;
					p1 = p2, p2 = tt;
					idx++;
					if (p2 == 0)
					{
						temp.push_back(idx);
					}
					if (p1 == 0 && p2 == 1)
					{
						break;
					}
				}
				int pivot = idx - 1;
				p[k] = pivot;
				v[k] = temp;
				visited[k] = true;
			}
		}
		ll pivot = p[k];
		ll len = v[k].size();
		ll q = (n - 1) / len, r = (n - 1) % len;
		ll ans = (q % MOD) * (pivot % MOD) % MOD;
		cout << (ans + v[k][r]) % MOD << '\n';
	}
	return 0;
}
