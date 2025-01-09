#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<bool>prime(10001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(10000); ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	int T = 0, ans = INT_MAX;
	cin >> T;
	auto bfs = [&](string st, string ed)
		{
			queue<pair<string, int>>q;
			map<string, bool>visited;
			visited[st] = true;
			q.push(make_pair(st, 0));
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				if (a == ed)
				{
					ans = b;
					return;
				}
				for (int i = 0; i <= 3; ++i)
				{
					for (int j = 0; j <= 9; ++j)
					{
						if (!i && !j)
						{
							continue;
						}
						string temp = a;
						temp[i] = j + '0';
						if (!visited[temp] && prime[stoi(temp)])
						{
							visited[temp] = true;
							q.push(make_pair(temp, b + 1));
						}
					}
				}
			}
		};
	while (T--)
	{
		ans = INT_MAX;
		string a, b;
		cin >> a >> b;
		bfs(a,b);
		(ans == INT_MAX) ? (cout << "Impossible" <<'\n') : (cout << ans << '\n');
	}
	return 0;
}