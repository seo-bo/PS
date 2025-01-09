#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
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
	int n = 0, m = 0, k1 = 0, k2 = 0;
	cin >> n >> m >> k1 >> k2;
	vector<vector<char>>v(n, vector<char>(n));
	vector<pii>node;
	pii home;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == 'B')
			{
				home = make_pair(i, j);
			}
			else if (v[i][j] == 'N')
			{
				node.push_back(make_pair(i, j));
			}
		}
	}
	ll ans1 = 0, ans2 = 0;
	auto cal1 = [&](vector<pii>a)
		{
			int pivot = 0;
			for (auto& [i, j] : a)
			{
				pivot += abs(i - home.first) + abs(j - home.second);
			}
			return pivot;
		};
	auto cal2 = [&](vector<pii>a)
		{
			int x = INT_MAX, y = INT_MAX, xx = INT_MIN, yy = INT_MIN;
			for (auto& [i, j] : a)
			{
				x = min(x, i);
				y = min(y, j);
				xx = max(xx, i);
				yy = max(yy, j);
			}
			return (xx - x + 1) * (yy - y + 1);
		};
	auto check = [&](int k)
		{
			if (!k)
			{
				return 0;
			}
			int pivot = 0, siz = node.size();
			vector<int>cc(siz, 0);
			fill(cc.end() - k, cc.end(), 1);
			do
			{
				vector<pii>a;
				for (int i = 0; i < siz; ++i)
				{
					if (cc[i])
					{
						a.push_back(node[i]);
					}
				}
				int a1 = cal1(a);
				int a2 = cal2(a);
				pivot = max(pivot, max(a1 - a2, 0));
			} while (next_permutation(cc.begin(), cc.end()));
			return pivot;
		};
	cout << check(k1) << '\n' << check(k2);
	return 0;
}