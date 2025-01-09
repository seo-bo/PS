// kjy2002와 팀 연습때 제가 짠겁니다.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int>ti;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n;
		int ed = INT_MIN;
		map<int, set<int>>mm;
		vector<pii>q;
		for (int i = 0; i < n; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			ed = max(ed, a);
			mm[a].insert(b);
		}
		vector<ti>ans;
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int temp = 0;
			cin >> temp;
			q.push_back(make_pair(temp, i));
		}
		sort(q.begin(), q.end());
		int pre = 0;
		int cnt = 1, idx = 0;
		for (int i = 0; i <= ed; ++i)
		{
			if (mm[i].find(pre) == mm[i].begin())
			{
				for (auto it = mm[i].begin(); it != mm[i].end(); ++it)
				{
					if (idx < m && cnt == q[idx].first)
					{
						while (idx < m && cnt == q[idx].first)
						{
							ans.push_back(make_tuple(q[idx].second, i, *it));
							idx++;
						}
					}
					pre = *it;
					cnt++;
				}
			}
			else
			{
				for (auto it = prev(mm[i].end());; --it)
				{
					if (idx < m && cnt == q[idx].first)
					{
						while (idx < m && cnt == q[idx].first)
						{
							ans.push_back(make_tuple(q[idx].second, i, *it));
							idx++;
						}
					}
					pre = *it;
					cnt++;
					if (it == mm[i].begin())
					{
						break;
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		for (auto& [_, a, b] : ans)
		{
			cout << a << ' ' << b << '\n';
		}
	}
	return 0;
}