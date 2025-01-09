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
	int n = 0, m = 0, cnt = 0, ver = 0;
	cin >> n >> m;
	unordered_map<char, int>mm = { {'U',0},{'D',1},{'L',2},{'R',3} };
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<int>v(n * m, 0),parent(n*m,0), rank(n*m,0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			if (parent[root] == root)
			{
				return parent[root];
			}
			return parent[root] = find(parent[root]);
		};
	auto merge = [&](int root1, int root2)
		{
			int r1 = find(root1);
			int r2 = find(root2);
			if (r1 != r2)
			{
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
				}
				else
				{
					parent[r1] = r2;
					rank[r2]++;
				}
			}
		};
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; ++j)
		{
			v[i * m + j] = mm[a[j]];
		}
	}
	for (int i = 0; i < n * m; ++i)
	{
		int x = i / m, y = i % m, d = v[i];
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		int nxt = nx * m + ny;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			int r1 = find(i), r2 = find(nxt);
			if (r1 != r2)
			{
				merge(i, nxt);
			}
		}
	}
	unordered_set<int>s;
	for (int i = 0; i < n * m; ++i)
	{
		s.insert(find(i));
	}
	cout << s.size();
	return 0;
}