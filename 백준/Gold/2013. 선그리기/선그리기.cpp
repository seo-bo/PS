#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<pll>>v(n, vector<pll>(2));
	auto cal = [&](string& str)
		{
			string temp = "";
			bool flag = false;
			int cnt = 0;
			for (auto& i : str)
			{
				if (i == '.')
				{
					flag = true;
					continue;
				}
				if (flag)
				{
					cnt++;
				}
				temp += i;
			}
			while (cnt < 2)
			{
				temp += '0';
				cnt++;
			}
			return stoll(temp);
		};
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			string str;
			cin >> str;
			ll a = cal(str);
			cin >> str;
			ll b = cal(str);
			j = make_pair(a, b);
		}
	}
	vector<int>parent(n, 0), rank(n, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else
				{
					parent[r1] = r2;
					if (rank[r1] == rank[r2])
					{
						rank[r2]++;
					}
				}
			}
		};
	auto sv = [&](vector<pll>& A, vector<pll>& B)
		{
			auto ccw = [&](pll& a, pll& b, pll& c)
				{
					ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
					temp -= a.second * b.first + b.second * c.first + c.second * a.first;
					return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
				};
			if (ccw(A[0], A[1], B[0]) || ccw(A[0], A[1], B[1]) || ccw(B[0], B[1], A[0]) || ccw(B[0], B[1], A[1]))
			{
				return false;
			}
			ll axmi = min(A[0].first, A[1].first);
			ll axma = max(A[0].first, A[1].first);
			ll aymi = min(A[0].second, A[1].second);
			ll ayma = max(A[0].second, A[1].second);
			ll bxmi = min(B[0].first, B[1].first);
			ll bxma = max(B[0].first, B[1].first);
			ll bymi = min(B[0].second, B[1].second);
			ll byma = max(B[0].second, B[1].second);
			if (axma < bxmi || bxma < axmi || ayma < bymi || byma < aymi)
			{
				return false;
			}
			return true;
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int r1 = find(i), r2 = find(j);
			if (r1 != r2)
			{
				if (sv(v[i], v[j]))
				{
					merge(i, j);
				}
			}
		}
	}
	unordered_set<int>ss;
	for (int i = 0; i < n; ++i)
	{
		ss.insert(find(i));
	}
	cout << ss.size();
	return 0;
}