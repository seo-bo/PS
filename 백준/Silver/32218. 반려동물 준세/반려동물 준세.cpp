#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	auto cal = [&](const vector<ll>& a)
		{
			int siz = a.size();
			vector<ll>b(n, 0);
			for (int i = 0; i < n; ++i)
			{
				for (int j = i + 1; j < n; ++j)
				{
					if (a[j] > a[i])
					{
						b[i]++;
					}
				}
			}
			return b;
		};
	vector<ll>v(n, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	int ans = 1;
	while (1)
	{
		vector<ll>b = cal(v);
		if (v == b)
		{
			cout << ans;
			break;
		}
		v = b;
		ans++;
		if (ans > 1000)
		{
			cout << -1;
			break;
		}
	}
	return 0;
}