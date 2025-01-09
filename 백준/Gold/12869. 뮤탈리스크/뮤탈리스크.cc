#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	set<vector<int>>visited;
	vector<int>per = { 1,3,9 };
	queue<pair<vector<int>, int>>q;
	q.push(make_pair(v, 0));
	visited.insert(v);
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		vector<int>tt = per;
		do
		{
			int cnt = 0;
			vector<int>vv = a;
			for (int i = 0; i < n; ++i)
			{
				vv[i] = max(vv[i] - tt[i], 0);
				if (!vv[i])
				{
					cnt++;
				}
			}
			if (cnt == n)
			{
				cout << b + 1;
				return 0;
			}
			if (visited.find(vv) == visited.end())
			{
				visited.insert(vv);
				q.push(make_pair(vv, b + 1));
			}
		} while (next_permutation(tt.begin(), tt.end()));
	}
	return 0;
}