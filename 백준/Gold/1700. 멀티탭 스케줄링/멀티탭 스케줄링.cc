#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, k = 0, ans = 0;
	cin >> n >> k;
	unordered_set<int>plug;
	vector<int>v(k);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int _ = 0; _ < k; ++_)
	{
		auto& i = v[_];
		if (plug.find(i) != plug.end())
		{
			continue;
		}
		else if (plug.size() < n)
		{
			plug.insert(i);
		}
		else
		{
			int pivot = -1, f = -1;
			for (auto& j : plug)
			{
				int nxt = INT_MAX;
				for (int z = _ + 1; z < k; ++z)
				{
					if (v[z] == j)
					{
						nxt = z;
						break;
					}
				}
				if (nxt > f)
				{
					f = nxt;
					pivot = j;
				}
			}
			plug.erase(pivot);
			plug.insert(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}