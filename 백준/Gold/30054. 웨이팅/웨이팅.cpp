#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>per(n);
	vector<int>ok(200001, -1);
	vector<vector<int>>v(200001);
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b] = per[i];
		cin >> a >> b;
		ok[a] = i;
		v[b].push_back(i);
		maxi = max({ maxi,a,b });
	}
	for (int i = 1; i <= maxi; ++i)
	{
		if (!v[i].empty())
		{
			sort(v[i].begin(), v[i].end());
		}
	}
	vector<bool>visited(n, false);
	vector<int>time(n, 0);
	queue<int>q;
	int cnt = 0, ans = 0;
	for (int i = 1; i <= maxi + n; ++i)
	{
		if (i <= maxi)
		{
			for (auto& j : v[i])
			{
				q.push(j);
			}
		}
		bool flag = false;
		if (i <= maxi)
		{
			if (ok[i] != -1 && !visited[ok[i]] && per[ok[i]].second <= i)
			{
				int pi = ok[i];
				visited[pi] = true;
				cnt++;
				time[pi] = i;
				ans = max(ans, i - per[pi].second);
				flag = true;
			}
		}
		if (!flag)
		{
			while (!q.empty() && visited[q.front()])
			{
				q.pop();
			}
			if (!q.empty())
			{
				int cur = q.front();
				q.pop();
				visited[cur] = true;
				cnt++;
				time[cur] = i;
				ans = max(ans, i - per[cur].second);
			}
		}
		if (cnt == n)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}