#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, t = 0, g = 0;
	cin >> n >> t >> g;
	vector<bool>visited(100001, 0);
	auto bfs = [&]
		{
			queue<pii>q;
			q.push(make_pair(n, 0));
			visited[n] = true;
			while (!q.empty())
			{
				pii cur = q.front();
				q.pop();
				if (cur.first == g)
				{
					cout << cur.second;
					exit(0);
				}
				if (cur.second == t)
				{
					continue;
				}
				if (cur.first * 2 < 100000)
				{
					int dd = cur.first * 2;
					if (dd > 0)
					{
						string tr = to_string(cur.first * 2);
						tr[0] -= 1;
						int tt = stoi(tr);
						if (tt < 100000 && !visited[tt])
						{
							visited[tt] = true;
							q.push(make_pair(tt, cur.second + 1));
						}
					}
				}
				if (cur.first + 1 < 100000 && !visited[cur.first + 1])
				{
					visited[cur.first + 1] = true;
					q.push(make_pair(cur.first + 1, cur.second + 1));
				}
			}
		};
	bfs();
	cout << "ANG";
	return 0;
}