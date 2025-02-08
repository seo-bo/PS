#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) // 아니 잠시만.... 쿼리 k개면 그냥 bfs 돌려도 되는거 아님?
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pll>q;
	unordered_set<ll>visited;
	ll l = 0, n = 0, k = 0;
	cin >> l >> n >> k;
	vector<int>dir = { -1,1 };
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		visited.insert(temp);
		q.push(make_pair(temp, 0));
	}
	while (!q.empty() && k)
	{
		auto [a, b] = q.front();
		q.pop();
		cout << b << '\n';
		k--;
		for (int i = 0; i < 2; ++i)
		{
			ll nx = a + dir[i];
			if (nx >= 0 && nx <= l && visited.find(nx) == visited.end())
			{
				visited.insert(nx);
				q.push(make_pair(nx, b + 1));
			}
		}
	}
	return 0;
}