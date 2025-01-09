#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 상위 10개만 관리라.... 분리집합인가?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
	vector<vector<int>>ver(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		ver[i].push_back(i);
	}
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			if (parent[root] == root)
			{
				return parent[root];
			}
			return parent[root] = find(parent[root]);
		};
	auto cal = [&](int r1, int r2)
		{
			vector<int>temp;
			int id = 0, jd = 0;
			while (id < ver[r1].size() && jd < ver[r2].size() && temp.size() < 10)
			{
				if (ver[r1][id] > ver[r2][jd])
				{
					temp.push_back(ver[r1][id++]);
				}
				else
				{
					temp.push_back(ver[r2][jd++]);
				}
			}
			while (id < ver[r1].size() && temp.size() < 10)
			{
				temp.push_back(ver[r1][id++]);
			}
			while (jd < ver[r2].size() && temp.size() < 10)
			{
				temp.push_back(ver[r2][jd++]);
			}
			ver[r1] = temp;
			ver[r2].clear();
		};
	auto merge = [&](int root1, int root2)
		{
			int r1 = find(root1);
			int r2 = find(root2);
			if (r1 != r2)
			{

				if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
					cal(r2, r1);
				}
				else // 케이스 나누지말고 그냥 하나로 합쳐버리자
				{
					parent[r2] = r1;
					if (rank[r1] == rank[r2])
					{
						rank[r1]++;
					}
					cal(r1, r2);
				}
			}
		};
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			merge(b, c);
		}
		else
		{
			int r1 = find(b);
			if (ver[r1].size() >= c)
			{
				cout << ver[r1][c - 1] << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}
