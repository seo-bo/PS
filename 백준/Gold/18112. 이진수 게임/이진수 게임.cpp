#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	ll a = 0, b = 0;
	for (ll i = (ll)A.size() - 1, c = 0; i >= 0; --i, ++c)
	{
		if (A[i] == '1')
		{
			a |= (1LL << c);
		}
	}
	for (ll i = (ll)B.size() - 1, c = 0; i >= 0; --i, ++c)
	{
		if (B[i] == '1')
		{
			b |= (1LL << c);
		}
	}
	queue<ll>q;
	q.push(a);
	vector<int>visited(1LL << 12, INT_MAX);
	visited[a] = 0;
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		if (cur == b)
		{
			cout << visited[cur];
			break;
		}
		ll pa = cur + 1, pb = cur - 1;
		if (visited[pa] > visited[cur] + 1)
		{
			visited[pa] = visited[cur] + 1;
			q.push(pa);
		}
		if (pb >= 0 && visited[pb] > visited[cur] + 1)
		{
			visited[pb] = visited[cur] + 1;
			q.push(pb);
		}
		if (cur > 0)
		{
			ll ok = 63 - __builtin_clzll(cur);
			for (int i = 0; i < ok; ++i)
			{
				ll temp = cur ^ (1LL << i);
				if (visited[temp] > visited[cur] + 1)
				{
					visited[temp] = visited[cur] + 1;
					q.push(temp);
				}
			}
		}
	}
	return 0;
}