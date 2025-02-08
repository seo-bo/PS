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
	vector<char>v(25);
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < 5; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < 5; ++j)
		{
			v[i * 5 + j] = a[j];
		}
	}
	int ans = 0;
	vector<int>per(25, 0);
	fill(per.end() - 7, per.end(), 1);
	auto bfs = [&]
		{
			int p = 0;
			vector<bool>pick(25, false);
			vector<bool>visited(25, false);
			vector<int>pp;
			queue<int>q;
			for (int i = 0; i < 25; ++i)
			{
				if (per[i])
				{
					pick[i] = true;
					pp.push_back(i);
					if (v[i] == 'S')
					{
						p++;
					}
				}
			}
			if (p < 4)
			{
				return;
			}
			visited[pp[0]] = true;
			q.push(pp[0]);
			int cnt = 1;
			while (!q.empty())
			{
				int a = q.front();
				q.pop();
				int x = a / 5, y = a % 5;
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
					{
						int nxt = nx * 5 + ny;
						if (pick[nxt] && !visited[nxt])
						{
							visited[nxt] = true;
							q.push(nxt);
							cnt++;
						}
					}
				}
			}
			if (cnt == 7)
			{
				ans++;
			}
		};
	do
	{
		bfs();
	} while (next_permutation(per.begin(), per.end()));
	cout << ans;
	return 0;
}