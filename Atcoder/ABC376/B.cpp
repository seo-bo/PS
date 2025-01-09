#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, q = 0;
	cin >> n >> q;
	auto bfs = [&](ll a, ll b, ll ban)
		{
			vector<int>visited(n + 1, -1);
			queue<int>q;
			q.push(a);
			visited[a] = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				if (cur == b)
				{
					return visited[cur];
				}
				int p = cur % n + 1;
				if (p != ban && visited[p] == -1)
				{
					visited[p] = visited[cur] + 1;
					q.push(p);
				}
				p = (cur - 2 + n) % n + 1;
				if (p != ban && visited[p] == -1)
				{
					visited[p] = visited[cur] + 1;
					q.push(p);
				}
			}
			return 0;
		};
	ll left = 1, right = 2, ans = 0;
	for (int i = 0; i < q; ++i)
	{
		char a;
		ll b = 0;
		cin >> a >> b;
		if (a == 'L')
		{
			ans += bfs(left, b, right);
			left = b;
		}
		else
		{
			ans += bfs(right, b, left);
			right = b;
		}
	}
	cout << ans;
	return 0;
}
