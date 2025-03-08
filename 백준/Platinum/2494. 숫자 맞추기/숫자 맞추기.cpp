#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string A, B;
	cin >> A >> B;
	vector<int>now, nxt;
	for (auto& i : A)
	{
		now.push_back(i - '0');
	}
	for (auto& i : B)
	{
		nxt.push_back(i - '0');
	}
	vector<vector<int>>dp(n, vector<int>(10, -1));
	auto cal = [&](int st, int ed)
		{
			int a = 10, b = 10;
			if (st < ed)
			{
				a = ed - st;
				b = st + 10 - ed;
			}
			else if (st > ed)
			{
				a = 10 - st + ed;
				b = st - ed;
			}
			return make_pair(a, b);
		};
	function<int(int, int)> dfs = [&](int idx, int turn)
		{
			if (idx == n)
			{
				return 0;
			}
			if (dp[idx][turn] != -1)
			{
				return dp[idx][turn];
			}
			int res = 1e8;
			int nw = (now[idx] + turn) % 10;
			if (nw == nxt[idx])
			{
				res = min(res, dfs(idx + 1, turn));
			}
			auto [a, b] = cal(nw, nxt[idx]);
			res = min({ res, dfs(idx + 1,turn) + b, dfs(idx + 1, (turn + a) % 10) + a });
			return dp[idx][turn] = res;
		};
	cout << dfs(0, 0) << '\n';
	function<void(int, int)> track = [&](int idx, int turn)
		{
			if (idx == n - 1)
			{
				int nw = (now[idx] + turn) % 10;
				auto [a, b] = cal(nw, nxt[idx]);
				cout << idx + 1 << ' ';
				if (dp[idx][turn] == 0)
				{
					cout << 0;
				}
				else
				{
					if (dp[idx][turn] == a)
					{
						cout << dp[idx][turn];
					}
					else
					{
						cout << -dp[idx][turn];
					}
				}
				return;
			}
			cout << idx + 1 << ' ';
			int nw = (now[idx] + turn) % 10;
			auto [a, b] = cal(nw, nxt[idx]);
			if (nw == nxt[idx])
			{
				if (dp[idx][turn] == dp[idx + 1][turn])
				{
					cout << 0 << '\n';
					track(idx + 1, turn);
					return;
				}
			}
			if (dp[idx][turn] - dp[idx + 1][turn] == b)
			{
				cout << -b << '\n';
				track(idx + 1, turn);
			}
			else
			{
				cout << a << '\n';
				track(idx + 1, (turn + a) % 10);
			}
		};
	track(0, 0);
	return 0;
}